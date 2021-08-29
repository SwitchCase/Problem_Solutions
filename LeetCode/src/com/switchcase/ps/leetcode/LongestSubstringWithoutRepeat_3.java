package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
public class LongestSubstringWithoutRepeat_3 {

    class Solution {
        public int lengthOfLongestSubstring(String s) {
            int start = 0; //start is sure.
            int end = 0; // end is not sure;
            Set<Character> used = new HashSet<>();
            int ans = 0, best = 0;
            int curr = 0;

            while(curr < s.length()) {
                Character khar = s.charAt(curr);
                if (used.contains(khar)) {
                    used.remove(s.charAt(start));
                    start++;
                    ans--;
                } else {
                    ans++;
                    used.add(khar);
                    curr++;
                    best = Math.max(best, ans);
                }
            }
            return best;
        }
    }

    static class SolutionPassesNonOptimal {

        public int lengthOfLongestSubstring(String s) {
            String[] dp = new String[s.length() + 4];
            for(int i = 0; i < s.length() + 4; i++) dp[i] = "-1";
            longestSubString(dp, s, 0);
            String longest = "";
            for (int i = 0; i < dp.length; i++) {
                if (dp[i].equals("-1")) continue;
                longest = longest.length() > dp[i].length()? longest : dp[i];
            }
            System.out.println(longest);
            return longest.length();
        }

        private String longestSubString(String[] dp, String s, int startPos) {
            if (startPos >= s.length()) {
                return "";
            }
            if (!dp[startPos].equals("-1")) return dp[startPos];
            String longest = longestSubString(dp, s, startPos + 1);
            if (longest.contains("" + s.charAt(startPos))) {
                Set<Character> chars = new HashSet<>();
                for (int j = startPos; j < s.length(); j++) {
                    if (chars.contains(s.charAt(j))) {
                        String str = chars.stream().map(c -> "" + c).collect(Collectors.joining(""));
                        return (dp[startPos] = str);
                    } else chars.add(s.charAt(j));
                }
                return dp[startPos] = "" + s.charAt(startPos);

            } else {
                return (dp[startPos] = "" + s.charAt(startPos) + longest);
            }
        }
    }
}
