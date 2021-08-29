package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/word-break-ii/
 */
public class WordBreakII_140 {
    class Solution {

        private Map<String, List<String>> cache = new HashMap<>();

        public List<String> wordBreak(String s, List<String> wordDict) {
            cache.put("", Arrays.asList(""));
            return recurse(s, new HashSet<>(wordDict));
        }

        private List<String> recurse(String s, Set<String> dict) {
            if (cache.containsKey(s)) {
                return cache.get(s);
            }
            List<String> ans = new ArrayList<>();

            for (int i = 0; i < s.length(); i++) {
                String substr = s.substring(0, i+1);
                String rem = s.substring(i+1);
                if (dict.contains(substr)) {
                    recurse(rem, dict).stream()
                            .map(x -> {
                                if (x.equals("")) {
                                    return substr;
                                } else {
                                    return substr + " " + x;
                                }
                            })
                            .forEach(ans::add);
                }
            }
            cache.put(s, ans);
            return ans;
        }
    }
}
