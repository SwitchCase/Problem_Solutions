package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/word-break-ii/
 */
public class WordBreakII_140 {
    class Solution {
        private Map<String, List<List<String>>> memoize = new HashMap<>();
        public List<String> wordBreak(String s, List<String> wordDict) {
            Set<String> dict = new HashSet<>(wordDict);
            List<List<String>> ans = recurse(s, dict);
            List<String> result = new ArrayList<>();
            for (List<String> soln : ans) {
                result.add(String.join(" ", soln));
            }
            return result;
        }

        private List<List<String>> recurse(String rem, Set<String> dict) {
            if (rem.length() == 0) {
                return Collections.emptyList();
            }
            if (memoize.containsKey(rem)) {
                return memoize.get(rem);
            }
            List<List<String>> ans = new ArrayList<>();
            for (int i = 1; i < rem.length(); i++) {
                String pre = rem.substring(0, i);
                String suff = rem.substring(i);
                if (dict.contains(pre)) {
                    List<List<String>> subSolution = recurse(suff, dict);
                    for (List<String> soln : subSolution) {
                        List<String> copy = new ArrayList<>();
                        copy.add(pre);
                        copy.addAll(soln);
                        ans.add(copy);
                    }
                }
            }
            if (dict.contains(rem)) {
                ans.add(Arrays.asList(rem));
            }

            memoize.put(rem, ans);
            return ans;
        }
    }
}
