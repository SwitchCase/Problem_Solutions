package com.switchcase.ps.leetcode;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WordBreak_139 {

    static class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            return recurse(s, 0, new HashSet<>(wordDict), new Boolean[s.length()]);
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

    }
}
