package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * https://leetcode.com/problems/decode-ways/
 */
public class DecodeWays_91 {
    class Solution {

        Set<String> dict = new HashSet<>();
        int[] dp = new int[150];

        public int numDecodings(String s) {
            for (int i = 1; i <= 26; i++) {
                dict.add(Integer.toString(i));
            }
            Arrays.fill(dp, -1);
            return recurse(s, 0);
        }

        public int recurse(String str, int sIdx) {
            if (sIdx >= str.length()) {
                return 1;
            }
            if (dp[sIdx] != -1) {
                return dp[sIdx];
            }
            int ans = 0;

            for (int i = sIdx; i < str.length(); i++) {
                String sub = str.substring(sIdx, i + 1);
                if (dict.contains(sub)) {
                    ans += recurse(str, i + 1);
                } else {
                    break;
                }
            }
            dp[sIdx] = ans;
            return ans;
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
            //System.out.println("For Case: " + kases[i] + " ans = " + new Solution().numDecodings(kases[i]));
        }
    }


}
