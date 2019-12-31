package com.switchcase.ps.leetcode;

public class LongestIncreasingPathMatrix_329 {
    class Solution {
        public int longestIncreasingPath(int[][] matrix) {
            if (matrix.length == 0) return 0;
            int n = matrix.length;
            int m = matrix[0].length;
            int[][] soln = new int[n][m];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    soln[i][j] = -1;
                }
            }
            int ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (soln[i][j] == -1) {
                        ans = Math.max(ans, recurse(soln, matrix, i, j, n, m));
                    }
                }
            }
            return ans;
        }

        private int recurse(int[][] soln, int[][] matrix, int i, int j, int N, int M) {
            if (soln[i][j] != -1) {
                return soln[i][j];
            }
            int n = matrix[i][j];
            int[] dn = {0, 0, 1, -1};
            int[] dm = {-1, 1, 0, 0};
            int ans = 1;
            for (int d = 0; d < 4; d++) {
                int di = i + dn[d];
                int dj = j + dm[d];
                if (di >=0 && dj >=0 && di < N && dj < M) {
                    int m = matrix[di][dj];
                    if ( m > n) {
                        ans = Math.max(ans, 1 + recurse(soln, matrix, di, dj, N, M));
                    }
                }
            }
            soln[i][j] = ans;
            return ans;
        }
    }
}
