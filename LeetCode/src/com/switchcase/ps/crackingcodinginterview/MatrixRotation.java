package com.switchcase.ps.crackingcodinginterview;

import java.util.Arrays;

public class MatrixRotation {

    static class Solution {
        int[][] rotate(int[][] matrix) {
            int N = matrix.length;
            for (int layer = 0; layer < N/2; layer++) {

            }
            return matrix;
        }
    }

    static class SolutionInNew {
        int[][] rotate(int[][] matrix) {
            if (matrix == null || matrix.length < 1 || matrix[0].length < 1) return matrix;
            int R = matrix.length;
            int C = matrix[0].length;
            int[][] ans = new int[C][R];
             for (int r = 0; r < R; r++) {
                 for (int c = 0; c < C; c++) {
                     int newR = c;
                     int newC = (R - r - 1 + R) % R;
                     ans[newR][newC] = matrix[r][c];
                 }
             }
             return ans;
        }
    }

    static class CorrectAns {
        public static int[][] rotate(int[][] matrix) {
            int n = matrix.length;
            for (int layer = 0; layer < n / 2; ++layer) {
                int first = layer;
                int last = n - 1 - layer;
                for (int i = first; i < last; ++i) {
                    int offset = i - first;
                    int top = matrix[first][i]; // save top
                    matrix[first][i] = matrix[last - offset][first];
                    matrix[last - offset][first] = matrix[last][last - offset];
                    matrix[last][last - offset] = matrix[i][last];
                    matrix[i][last] = top;
                }
            }
            return matrix;
        }
    }

    public static void main(String[] args) {
        int[][] ans = new CorrectAns().rotate(new int[][] {{1, 2, 3}, {4, 5, 6}, {7,8,9}});
        for (int i = 0; i < ans.length; i++)
        System.out.println(Arrays.toString(ans[i]));
    }
}
