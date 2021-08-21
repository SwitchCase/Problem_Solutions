package com.switchcase.ps.leetcode;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/maximal-rectangle/
 */
public class MaximalRectangle_85 {

    static class Solution {
        public int maximalRectangle(char[][] matrix) {
            if (matrix.length == 0 || matrix[0].length == 0) return 0;
            int R = matrix.length;
            int C = matrix[0].length;

            int[] H = new int[C];
            Arrays.fill(H, 0);
            for (int j = 0; j < C; j++) {
                H[j] = matrix[0][j] - '0';
            }
            int ans = bestArea(H);

            for (int i = 1; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    H[j] = matrix[i][j] == '0' ? 0 : H[j] + 1;
                }
                ans = Math.max(ans, bestArea(H));
            }
            return ans;
        }

        private int bestArea(int[] H) {
            int N = H.length;
            int[] right = new int[N];
            int[] left = new int[N];
            right[N-1] = N;
            left[0] = -1;
            for (int i = N - 2; i >=0; i--) {
                int p = i + 1;
                while(p < N && H[p] >= H[i]) {
                    p = right[p];
                }
                right[i] = p;
            }
            for (int i = 1; i < N; i++) {
                int p = i - 1;
                while (p >= 0 && H[p] >= H[i]) {
                    p = left[p];
                }
                left[i] = p;
            }
            int ans = 0;
            for (int i = 0; i < N; i++) {
                ans = Math.max(ans, H[i] * (right[i] - left[i] - 1));
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().maximalRectangle(new char[][]{
                {'1', '0', '1', '0', '0'},
                {'1', '0', '1', '1', '1'},
                {'1', '1', '1', '1', '1'},
                {'1', '0', '0', '1', '0'},}));

        System.out.println(new Solution().maximalRectangle(new char[][]{
                {'0', '1'},
                {'0', '1'}}));
    }

}
