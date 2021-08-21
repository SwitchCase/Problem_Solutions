package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class MaxLengthRepeatedSubarray_718 {

    static class SolutionGreedyFails {
        public int findLength(int[] A, int[] B) {
            int best = 0;
            for (int i = 0; i < B.length; i++) {
                int j = 0;
                while (j < A.length) {
                    while (j < A.length && B[i] != A[j]) j++;
                    int ans = 0;
                    int c = i;
                    while (j < A.length && c < B.length && A[j] == B[c]) {
                        ans++;
                        c++;
                        j++;
                    }
                    best = Math.max(best, ans);
                }
            }
            return best;
        }
    }

    static class Solution {
        public int findLength(int[] A, int[] B) {
            int[][] dp = new int[A.length][B.length];
            for (int i = 0; i < A.length; i++)
                for (int j = 0; j < B.length; j++) dp[i][j] = 0;

            int ans = 0;
            for (int i = 0; i < A.length; i++) {
                for (int j = 0; j < B.length; j++) {
                    if (A[i] == B[j]) {
                        if (i > 0 && j > 0)
                            dp[i][j] = Math.max(dp[i][j], 1 + dp[i-1][j-1]);
                        else dp[i][j] = 1;
                        ans = Math.max(ans, dp[i][j]);
                    }
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().findLength(
                new int[]{0,0,0,0,0,1,1,1,0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,1,0,0,0,1},
                new int[]{1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0}));

        System.out.println(new Solution().findLength(
                new int[]{3, 5, 3, 5,5,3,3,5,5,3},
                new int[]{3,5,3,3,5,5,3}));
    }

}
