package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class DecodeWays2_639 {

    static class Solution {

        private static final int MOD = 1_000_000_007;

        long[] dp;

        public int numDecodings(String s) {
            dp = new long[s.length()];
            Arrays.fill(dp, -1L);
            return (int) recurse(s, 0);
        }

        long recurse(String s, int idx) {
            if (idx >= s.length()) return 1L;
            if (dp[idx] >= 0) return dp[idx];
            long ans = 0;
            if (idx + 1 <= s.length()) ans += (1L * ways(s.substring(idx, idx + 1)) * recurse(s, idx + 1)) % MOD;
            if (idx + 2 <= s.length()) ans += (1L * ways(s.substring(idx, idx + 2)) * recurse(s, idx + 2)) % MOD;

            ans %= MOD;
            return dp[idx] = ans;
        }


        //entire string as 1 char.
        int ways(String s) {
            if (s.length() > 2) {
                return 0;
            }
            if (s.length() == 1) {
                if (s.charAt(0) == '*') return 9;
                else if (s.charAt(0) == '0') return 0;
                return 1;
            } else {
                if(s.equals("**")) {
                    return 15;
                } else {
                    if (s.charAt(0) == '0') return 0;
                    else if (s.charAt(0) == '*') {
                        if (s.charAt(1) >= '7') return 1;
                        else return 2;
                    } else { // at0 is non zero non *
                        if (s.charAt(0) == '1') {
                            if (s.charAt(1) == '*') return 9;
                            else if (s.charAt(1) == '0') return 1;
                            else return 1;
                        } else if (s.charAt(0) == '2') {
                            if (s.charAt(1) == '*') return 6;
                            else if (s.charAt(1) >= '0' && s.charAt(1) <= '6') return 1;
                            else return 0;
                        } else {
                            return 0;
                        }
                    }
                }
            }
        }
    }


    public static void main(String[] args) {
        System.out.println(new Solution().numDecodings("**"));
        System.out.println(new Solution().numDecodings("1*"));
        System.out.println(new Solution().numDecodings("*1"));
        System.out.println(new Solution().numDecodings("*0"));
        System.out.println(new Solution().numDecodings("*********"));
    }


}
