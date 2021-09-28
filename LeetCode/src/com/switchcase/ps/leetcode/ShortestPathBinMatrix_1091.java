package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class ShortestPathBinMatrix_1091 {

    //fails because loop moves in left to right and up to down whereas all 8 directional moves are allowed.
    class SolutionWA {
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

    class Solution {
        public int shortestPathBinaryMatrix(int[][] grid) {
           int N = grid.length;
           int M = grid[0].length;

           if (grid[0][0] == 1 || grid[N-1][M-1] == 1) return -1;

           int[] dN = {0,  0, 1, 1,  1, -1, -1, -1 };
           int[] dM = {1, -1, 1, 0, -1,  1,  0, -1 };

           Queue<int[]> queue = new ArrayDeque<>();
           queue.add(new int[] {0,0,1});

           int[][] ans = new int[N][M];
           for (int i = 0; i < N; i++) {
               Arrays.fill(ans[i], 100000000);
           }

           while(!queue.isEmpty()) {
               int[] top = queue.poll();
               if (top[0] == N-1 && top[1] == M-1)  return top[2];
               for(int i =0; i < 8; i++) {
                   int nN = top[0] + dN[i];
                   int nM = top[1] + dM[i];
                   if (nN >= 0 && nN < N && nM >=0 && nM < M) {
                       if (grid[nN][nM] != 1) {
                           if (ans[nN][nM] > top[2] + 1) {
                               ans[nN][nM] = top[2] + 1;
                               queue.add(new int[]{nN, nM, top[2] + 1});
                           }
                       }
                   }
               }
           }
           return -1;

        }
    }
}
