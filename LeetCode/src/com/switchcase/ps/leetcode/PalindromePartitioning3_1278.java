package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class PalindromePartitioning3_1278 {

    class Solution {
        public int palindromePartition(String s, int k) {
            int[][] dp = new int[s.length()][k+1];
            for (int i =0; i < dp.length; i++) {
                Arrays.fill(dp[i], -1);
            }
            return recurse(s, k, dp, 0);
        }

        private int recurse(String s, int k, int[][] dp, int startIdx) {
            if (startIdx >= s.length() || k > (s.length() - startIdx)) {
                return Integer.MAX_VALUE;
            }

            if (dp[startIdx][k] != -1) {
                return dp[startIdx][k];
            }


            if (k == 1) {
                return dp[startIdx][k] = getCost(s, startIdx, s.length() - 1);
            }

            int ans = Integer.MAX_VALUE;
            for (int i = startIdx; i < s.length(); i++) {
                int cost = getCost(s, startIdx, i);
                int dfsCost = recurse(s, k - 1, dp, i + 1);
                if (dfsCost == Integer.MAX_VALUE) continue;
                ans = Math.min(ans, dfsCost + cost);
            }
            return dp[startIdx][k] = ans;
        }

        private int getCost(String s, int startIdx, int endIdx) {
            int ans = 0;
            while (startIdx < endIdx) {
                if (s.charAt(startIdx) != s.charAt(endIdx)) {
                    ans++;
                }
                startIdx++;
                endIdx--;
            }
            return ans;
        }
    }
}
