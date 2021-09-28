package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class DecodeWays2_639 {
    class Solution {
        private static final int MOD = 1000_000_000 + 7;
        public int numDecodings(String s) {
            int[] dp = new int[s.length()];
            Arrays.fill(dp, -1);
            return recurse(dp, s.toCharArray(), 0);
        }

        private int recurse(int[] dp, char[] s, int sIdx) {
            if (sIdx >= s.length) {
                return 1;
            }
            if (dp[sIdx] > -1) {
                return dp[sIdx];
            }
            char currChar = s[sIdx];
            long ans = ((long) getCombos(currChar, null) * recurse(dp, s, sIdx + 1)) % MOD;
            if (sIdx + 1 < s.length) {
                ans += ((long) getCombos(currChar, s[sIdx + 1]) * recurse(dp, s, sIdx + 2)) % MOD;
            }
            dp[sIdx] = (int) (ans % MOD);
            return dp[sIdx];
        }

        private int getCombos(Character a, Character b) {
            if (b == null) {
                if (a == '*') {
                    return 9;
                } else if (a == '0') {
                    return 0;
                } else return 1;
            } else {
                String[] values = new String[]{"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                        "21", "22", "23", "24", "25", "26"};
                int ans = 0;
                for (String v : values) {
                    if (a=='*' || (a == v.charAt(0))) {
                        if ( (b=='*' && v.charAt(1) != '0') || (b == v.charAt(1))) {
                            ans++;
                        }
                    }
                }
                return ans;
            }
        }
    }
}
