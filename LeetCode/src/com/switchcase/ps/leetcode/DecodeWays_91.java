package com.switchcase.ps.leetcode;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/decode-ways/
 */
public class DecodeWays_91 {
    static class Solution {
        private static final int LARGEST = 26;
        int[] dp;
        public int numDecodings(String s) {
            dp = new int[s.length()];
            Arrays.fill(dp, -1);
            return calculate(s, 0);
        }

        int calculate(String s, int startPos) {
            if (dp[startPos] != -1) {
                return dp[startPos];
            }

            if (s.charAt(startPos) == '0') {
                return 0;
            }

            int ans = 0;
            int first = s.charAt(startPos) - '0';
            if (startPos < s.length() - 1) {
                int first2 = (s.charAt(startPos) - '0') * 10 + (s.charAt(startPos + 1) - '0');
                if (first2 <= LARGEST && first2 > 0) {
                    if (startPos + 2 < s.length()) {
                        ans += calculate(s, startPos + 2);
                    } else ans += 1;
                }
            }
            if (first > 0 && first <= LARGEST) {
                if (startPos + 1 < s.length()) {
                    ans += calculate(s, startPos + 1);
                } else ans++;
            }
            return dp[startPos] = ans;
        }
    }

    public static void main(String[] args) {
        String[] kases = new String[]{
                "0",
                "00",
                "100",
                "001",
                "200",
                "20",
                "2002002",
                "3003003",
                "12",
                "226"
        };
        for (int i = 0; i < kases.length; i++) {
            System.out.println("For Case: " + kases[i] + " ans = " + new Solution().numDecodings(kases[i]));
        }
    }


}
