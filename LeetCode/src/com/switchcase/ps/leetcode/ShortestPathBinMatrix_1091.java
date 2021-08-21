package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Queue;

public class ShortestPathBinMatrix_1091 {

    //fails because loop moves in left to right and up to down whereas all 8 directional moves are allowed.
    static class SolutionWA {
        public int shortestPathBinaryMatrix(int[][] grid) {
            if (grid == null || grid.length == 0) return -1;
            int rows = grid.length;
            int cols = grid[0].length;
            if (grid[0][0] == 1 || grid[rows-1][cols-1] == 1) return -1;

            int[][] ans = new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    ans[i][j] = 1000000;
                }
            }

            int[] di = new int[]{1, 0, 1, -1, 0, -1, 1, -1};
            int[] dj = new int[]{0, 1, 1, 0, -1, -1, -1, 1};
            ans[0][0] = 0;

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 1) continue;
                    for (int k = 0; k < di.length; k++) {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if (ni >= 0 && nj >=0 && ni <rows && nj < cols) {
                            if (grid[ni][nj] != 1) {
                                ans[ni][nj] = Math.min(ans[ni][nj], 1 + ans[i][j]);
                            }
                        }
                    }
                }
            }
            return ans[rows-1][cols-1] >= 10000 ? -1 : ans[rows-1][cols-1] + 1;
        }
    }

    static class Solution {
        public int shortestPathBinaryMatrix(int[][] grid) {
            if (grid == null || grid.length == 0) return -1;
            int rows = grid.length;
            int cols = grid[0].length;
            if (grid[0][0] == 1 || grid[rows-1][cols-1] == 1) return -1;

            int[][] ans = new int[rows][cols];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    ans[i][j] = 1000000;
                }
            }
            ans[0][0] = 0;

            Queue<int[]> queue = new ArrayDeque<>();
            queue.offer(new int[]{0, 0});

            int[] di = new int[]{1, 0, 1, -1, 0, -1, 1, -1};
            int[] dj = new int[]{0, 1, 1, 0, -1, -1, -1, 1};

            while(!queue.isEmpty()) {
                int[] curr = queue.poll();
                if (curr[0] == rows -1 && curr[1] == cols - 1) {
                    return ans[rows-1][cols-1] + 1;
                }
                for (int k = 0; k < di.length; k++) {
                    int ni = curr[0] + di[k];
                    int nj = curr[1] + dj[k];
                    if (ni >= 0 && nj >=0 && ni <rows && nj < cols) {
                        if (grid[ni][nj] != 1) {
                            if (ans[ni][nj] > 1 + ans[curr[0]][curr[1]]) {
                                queue.offer(new int[]{ni, nj});
                                ans[ni][nj] = 1 + ans[curr[0]][curr[1]];
                            }
                        }
                    }
                }
            }

            return ans[rows-1][cols-1] >= 10000 ? -1 : ans[rows-1][cols-1] + 1;
        }
    }
}
