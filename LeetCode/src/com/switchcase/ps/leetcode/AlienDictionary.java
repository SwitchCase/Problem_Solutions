package com.switchcase.ps.leetcode;

import java.util.*;

public class AlienDictionary {
    class Solution {
        public String alienOrder(String[] words) {
            if (words == null) return "";
            int N = words.length;
            if (N == 1) return words[0];
            Map<Character, List<Character>> graph = new HashMap<>();
            Set<Character> allChars = new HashSet<>();
            addWord(words[0], allChars);
            for (int i = 1; i < N; i++) {
                char[] cmp = compare(words[i-1], words[i]);
                if (cmp.length == 2) {
                    graph.putIfAbsent(cmp[0], new ArrayList<>());
                    graph.get(cmp[0]).add(cmp[1]);
                }
                addWord(words[i], allChars);
            }
            for (Character c : allChars) graph.putIfAbsent(c, new ArrayList<>());

            return toposort(graph);
        }

        private String toposort(Map<Character, List<Character>> graph) {
            StringBuilder ans = new StringBuilder();
            int[] visited = new int[128];
            Arrays.fill(visited, 0); //1 means partial, 2 means visited
            for(Map.Entry<Character, List<Character>> entry: graph.entrySet()) {
                boolean noCycle = doTopSort(ans, graph, entry.getKey(), visited);
                if (!noCycle) return "";
            }
            return ans.reverse().toString();
        }

        private boolean doTopSort(StringBuilder sb, Map<Character, List<Character>> graph, char key, int[] visited) {
            if (visited[key] == 2) return true;
            if (visited[key] == 1) return false;
            visited[key] = 1;
            for (Character adj : graph.get(key)) {
                boolean v = doTopSort(sb, graph, adj, visited);
                if (!v) return false;
            }
            visited[key] = 2;
            sb.append(key);
            return true;
        }

        private void addWord(String word, Set<Character> allChars) {
            word.chars().forEach(x -> allChars.add((char)x));
        }

        private char[] compare(String word, String word1) {
            for (int i = 0; i < Math.min(word.length(), word1.length()); i++) {
                if (word.charAt(i) != word1.charAt(i)) {
                    return new char[]{word.charAt(i), word1.charAt(i)};
                }
            }
            return new char[]{};
        }
    }
}
