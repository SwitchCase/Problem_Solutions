package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/word-ladder-ii/
 */
public class WordLadderII_126 {

    //1137 ms
    static class Solution {

        static class State {
            String word;
            int length;
            List<String> path;

            State(String word, int length, List<String> path) {
                this.word = word;
                this.length = length;
                this.path = path;
            }
        }


        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            Queue<State> queue = new ArrayDeque<>();
            queue.add(new State(beginWord, 1, Arrays.asList(beginWord)));
            wordList.add(beginWord);
            List<List<String>> ans = new ArrayList<>();
            Map<String, Set<String>> adjList = getAdj(wordList);

            int bestLength = -1;
            Set<String> visited = new HashSet<>();
            visited.add(beginWord);

            while (!queue.isEmpty()) {
                State top = queue.poll();
                Set<String> pathWords = new HashSet<>(top.path);
                if (endWord.equals(top.word)) {
                    if (bestLength == -1) {
                        bestLength = top.length;
                        ans.add(top.path);
                    } else {
                        if (top.length == bestLength) {
                            ans.add(top.path);
                        }
                    }
                } else {
                    if ( (bestLength != -1 && top.length > bestLength) || top.length >= wordList.size()) {
                        break;
                    }
                    for (String nextWord : adjList.getOrDefault(top.word, new HashSet<>())) {
                        if (pathWords.contains(nextWord) || visited.contains(nextWord)) {
                            continue;
                        }
                        List<String> path = new ArrayList<>(top.path);
                        path.add(nextWord);
                        State newState = new State(nextWord, top.length + 1, path);
                        queue.add(newState);
                    }
                }
                visited.add(top.word);
            }
            return ans;
        }

        private Map<String, Set<String>> getAdj(List<String> wordList) {

            Set<String> dict = new HashSet<>(wordList);
            Map<String, Set<String>> ans = new HashMap<>();

            for (String word : wordList) {
                ans.put(word, new HashSet<>());
                for (int i = 0; i < word.length(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        String newWord = getWord(word, c,i);
                        if (dict.contains(newWord) && !newWord.equals(word)) {
                            ans.get(word).add(newWord);
                        }
                    }
                }
            }
            return ans;
        }

        private String getWord(String word, char c, int i) {
            if (i == 0) {
                return c + word.substring(i + 1);
            } else if (i == word.length() - 1) {
                return word.substring(0, i) + c;
            } else return word.substring(0, i) + c + word.substring(i + 1);

        }
    }

    //85ms.
    static class Solution1 {
        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            Set<String> words = new HashSet<>(wordList);
            List<List<String>> res = new ArrayList<>();
            Map<String, List<List<String>>> layer = new HashMap<>();
            layer.put(beginWord, new ArrayList<>());
            layer.get(beginWord).add(Arrays.asList(beginWord));

            while (!layer.isEmpty()) {
                Map<String, List<List<String>>> newLayer = new HashMap<>();
                for (String w : layer.keySet()) {
                    if (w.equals(endWord)) {
                        res.addAll(layer.get(w));
                    } else {
                        for (int i = 0; i < endWord.length(); i++) {
                            StringBuilder sb = new StringBuilder(w);
                            for (char c = 'a'; c <='z'; c++) {
                                sb.setCharAt(i, c);
                                String newW = sb.toString();
                                if (words.contains(newW)) {
                                    newLayer.putIfAbsent(newW, new ArrayList<>());
                                    for (List<String> path : layer.get(w)) {
                                        List<String> nPath = new ArrayList<>(path);
                                        nPath.add(newW);
                                        newLayer.get(newW).add(nPath);
                                    }
                                }
                            }
                        }
                    }
                }
                words.removeAll(newLayer.keySet());
                layer = newLayer;
            }
            return res;
        }
    }

    // TLE.
    static class Solution2 {
        static class State {
           private final int distance;
           private final int wordIdx;
           private final LinkedList<Integer> path;
           private final Set<Integer> pathSet;
           State(int distance, int wordIdx, LinkedList<Integer> path) {
               this.distance = distance;
               this.wordIdx = wordIdx;
               this.path = path;
               this.pathSet = new HashSet<>(path);
           }
        }

        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            Map<String, Integer> set = new HashMap();
            for (int i = 0; i < wordList.size(); i++) {
                if (!beginWord.equals(wordList.get(i)))
                    set.put(wordList.get(i), i);
            }

            Map<String, Set<Integer>> map = buildMap(wordList, set);
            processWord(beginWord, wordList, set, map);
            set.put(beginWord, -1);
            if (!map.containsKey(endWord)) {
                return new ArrayList<>();
            }

            Map<Integer, String> reverseSet = new HashMap<>();
            set.entrySet().stream().forEach(e -> reverseSet.put(e.getValue(), e.getKey()));
            Set<LinkedList<Integer>> allPaths = generatePaths(map, set, reverseSet, set.get(endWord));
            List<List<String>> ans = new ArrayList<>();
            for (LinkedList<Integer> path : allPaths) {
                List<String> nPath = new ArrayList<>();
                nPath.add(beginWord);
                for (int i = 0; i < path.size(); i++) {
                    nPath.add(reverseSet.get(path.get(i)));
                }
                nPath.add(endWord);
                ans.add(nPath);
            }
            return ans;
        }

        private Set<LinkedList<Integer>> generatePaths(Map<String, Set<Integer>> map, Map<String, Integer> set, Map<Integer, String> reverseSet, int eIdx) {
            Set<LinkedList<Integer>> ans = new HashSet<>();
            Queue<State> queue = new ArrayDeque<>();
            queue.add(new State(0, -1, new LinkedList<>()));
            int shortest = Integer.MAX_VALUE;
            HashMap<Integer, Integer> seen = new HashMap<>();
            while(!queue.isEmpty()) {
                State curr = queue.poll();
                if (curr.distance > shortest) continue;
                Set<Integer> words = map.getOrDefault(reverseSet.get(curr.wordIdx), null);
                if (words != null) {
                    for (Integer wIdx : words) {
                        if (wIdx == eIdx) {
                            int currShortest = curr.distance + 1;
                            if (shortest >= currShortest) {
                                shortest = currShortest;
                                ans.add(curr.path);
                                break;
                            }
                        } else if (!seen.containsKey(wIdx)) {
                            LinkedList<Integer> path = new LinkedList<>(curr.path);
                            path.addLast(wIdx);
                            queue.add(new State(curr.distance + 1, wIdx, path));
                            seen.put(wIdx, curr.distance + 1);
                        }
                    }
                }
            }
            return ans;
        }

        private Map<String, Set<Integer>> buildMap(List<String> wordList, Map<String, Integer> set) {
            Map<String, Set<Integer>> ans = new HashMap<>();

            for (int j = 0; j < wordList.size(); j++) {
                String word = wordList.get(j);
                processWord(word, wordList, set, ans);
            }
            return ans;
        }

        private void processWord(String word, List<String> wordList, Map<String, Integer> set, Map<String, Set<Integer>> ans) {
            for (int i = 0; i < word.length(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (word.charAt(i) == c) continue;
                    String tword = replace(word, i, c);
                    if (set.containsKey(tword)) {
                        addToMap(ans, word, set.get(tword));
                    }
                }
            }
        }

        private void addToMap(Map<String, Set<Integer>> ans, String word, Integer index) {
            if (ans.containsKey(word)) {
                ans.get(word).add(index);
            } else {
                Set<Integer> val = new HashSet<>();
                val.add(index);
                ans.put(word, val);
            }
        }

        private String replace(String word, int idx, char c) {
            StringBuffer sb = new StringBuffer(word);
            sb.setCharAt(idx, c);
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().findLadders("red", "tax", Arrays.asList(new String[] {"ted","tex","red","tax","tad","den","rex","pee"})));
        System.out.println(new Solution().findLadders("cet", "ism", Arrays.asList(new String[] {"kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","cot","bid","ali","pay","col","gum","ger","row","won","has","zip","fez","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","coo","win","tao","coy","van","man","pit","guy","foe", "gee","pin","dun","pat","ten","mob"})));
        System.out.println(new Solution().findLadders("cet", "ism", Arrays.asList(new String[] {"kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"})));
        System.out.println(new Solution().findLadders("hit", "cog", Arrays.asList(new String[] {"hot","dot","dog","lot","log","cog"})));
        System.out.println(new Solution().findLadders("hit", "cog", Arrays.asList(new String[] {"hot","dot","dog","lot","log"})));

    }


}
