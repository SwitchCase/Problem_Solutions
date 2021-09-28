package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class CountSquareMatricesWithOnes_1277 {
    class Solution {
        public int countSquares(int[][] matrix) {
            int N = matrix.length;
            int M = matrix[0].length;

            int[][] dp = new int[N][M];
            for (int i = 0; i < N; i++) {
                Arrays.fill(dp[i], -1);
            }

            int ans = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    ans += recurse(matrix, N, M, i, j, dp);
                }
            }
            return ans;
        }

        private int recurse(int[][] matrix, int N, int M, int sN, int sM, int[][] dp) {
            if (sN == 0 || sM == 0) {
                return dp[sN][sM] = matrix[sN][sM];
            }
            if (dp[sN][sM] != -1) {
                return dp[sN][sM];
            }
            if (matrix[sN][sM] == 0) {
                return dp[sN][sM] = 0;
            }
            int top = recurse(matrix, N, M, sN - 1, sM, dp);
            int corner =  recurse(matrix, N, M, sN - 1, sM - 1, dp);
            int left = recurse(matrix, N, M, sN, sM - 1, dp);

            return dp[sN][sM] = 1 + Math.min(top, Math.min(corner, left));
        }

    }
}
