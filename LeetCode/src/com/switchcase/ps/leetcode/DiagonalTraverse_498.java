package com.switchcase.ps.leetcode;

public class DiagonalTraverse_498 {
    static class Solution {
        public int[] findDiagonalOrder(int[][] matrix) {
            if (matrix == null || matrix.length == 0) return new int[]{};
            int R = matrix.length;
            int C = matrix[0].length;
            int[] ans = new int[R*C];
            int idx = 0;
            ans[idx++] = matrix[0][0];
            for(int i = 1; i <= R + C; i++) {
                if (i % 2 == 1) {
                    //downward
                    for(int j = 0; j <= i; j++) {
                        int col = i - j;
                        if (col >= C || j >= R) continue;
                        ans[idx++] = matrix[j][col];
                    }

                } else {
                    //upward
                    for(int j = i; j >= 0; j--) {
                        int col = i - j;
                        if (col >= C || j >= R) continue;
                        ans[idx++] = matrix[j][col];
                    }
                }
            }
            return ans;
        }
    }
}
