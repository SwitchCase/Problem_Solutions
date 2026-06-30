package com.switchcase.ps.leetcode;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WordBreak_139 {

    static class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            return iterate(s, 0, new HashSet<>(wordDict), new boolean[s.length() + 1]);
        }

        private boolean iterate(String s, int start, Set<String> words, boolean[] cache) {
            cache[s.length()] = true;
            for (int i = s.length() - 1; i >= 0; i--) {
                for (int j = i+1; j <= s.length(); j++) {
                    String curr = s.substring(i, j);
                    if (words.contains(curr) && cache[j]) {
                        cache[i] = true;
                        break;
                    }
                }
            }
            return cache[0];
        }

        private boolean recurse(String s, int start, Set<String> words, Boolean[] cache) {
            if (cache[start] != null) return cache[start];
            StringBuffer prefix = new StringBuffer();
            prefix.append(s.charAt(start));
            boolean ans = false;
            for (int i = start + 1; i < s.length(); i++) {
                if (words.contains(prefix.toString())) {
                    if (recurse(s, i, words, cache)) {
                        return cache[start] = true;
                    }
                }
                prefix.append(s.charAt(i));
            }
            return cache[start] = words.contains(prefix.toString());
        }

        private boolean recurseByWord(String s, int start, Set<String> words, Boolean[] cache) {
            if (cache[start] != null) return cache[start];
            StringBuffer prefix = new StringBuffer();
            for (String w : words) {
                if (s.startsWith(w, start) && recurseByWord(s, start + w.length(), words, cache))
                    return cache[start] = true;
            }
            return cache[start] = false;
        }

    }
}
