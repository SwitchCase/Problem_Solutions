package com.switchcase.ps.leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;

public class SwimInRisingWater_778 {
    class Solution {
        public int swimInWater(int[][] grid) {
            int N = grid.length;
            int M = grid[0].length;
            boolean[][] visited = new boolean[N][M];

            int[] dN = {0,  0, 1, -1 };
            int[] dM = {1, -1, 0, 0 };

            PriorityQueue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a[2]));
            queue.add(new int[]{0,0, grid[0][0]});
            visited[0][0] = true;

            while(!queue.isEmpty()) {
                int[] top = queue.poll();
                if (top[0] == N-1 && top[1] == M-1) {
                    return top[2];
                }
                for (int i = 0; i < 4; i++) {
                    int nN = top[0] + dN[i];
                    int nM = top[1] + dM[i];
                    if (nN >= 0 && nN < N && nM >=0 && nM < M && !visited[nN][nM]) {
                        visited[nN][nM] = true;
                        queue.add(new int[]{nN, nM, Math.max(top[2], grid[nN][nM])});
                    }
                }
            }
            return -1;

        }
    }
}
