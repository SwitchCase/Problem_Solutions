package com.switchcase.ps.leetcode;

public class LongestIncreasingPathMatrix_329 {
    class Solution {
        public int longestIncreasingPath(int[][] matrix) {
            int N = matrix.length;
            int M = matrix[0].length;

            int[][] ans = new int[N][M];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                    ans[i][j] = -1;
            }
            int result = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    result = Math.max(result, recurse(matrix, N, M, ans, i, j));
                }
            }
            return result;
        }

        private int recurse(int[][] matrix, int N, int M, int[][] ans, int sN, int sM) {
            if (ans[sN][sM] != -1) {
                return ans[sN][sM];
            }
            int result = 1;
            int[] dN = {0, 0, -1, 1};
            int[] dM = {-1, 1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int nn = sN + dN[i];
                int mm = sM + dM[i];
                if (nn >= 0 && nn < N && mm >=0 && mm < M) {
                    if (matrix[nn][mm] > matrix[sN][sM]) {
                        result = Math.max(result, 1 + recurse(matrix, N, M, ans, nn, mm));
                    }
                }
            }
            ans[sN][sM] = result;
            return result;
        }
    }
}
