package com.switchcase.ps.leetcode;

public class MinPathSum_64 {
    static class Solution {
        public int minPathSum(int[][] grid) {
            if (grid == null || grid.length == 0) return 0;
            int rows = grid.length;
            int cols = grid[0].length;
            int[][] ans = new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    ans[i][j] = 10000000;
                }
            }
            ans[0][0] = grid[0][0];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if ( i < rows - 1) {
                        ans[i+1][j] = Math.min(ans[i+1][j], grid[i+1][j] + ans[i][j]);
                    }
                    if (j < cols - 1) {
                        ans[i][j+1] = Math.min(ans[i][j+1], grid[i][j+1] + ans[i][j]);
                    }
                }
            }
            return ans[rows-1][cols-1];
        }
    }
}
