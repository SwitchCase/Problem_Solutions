package com.switchcase.ps.leetcode;

public class SortMatrixDiagonally_1329 {

    class Solution {
        public int[][] diagonalSort(int[][] mat) {
            for (int i = 0; i < mat.length; i++) {
                sortDiagonalBubbleSort(mat, i, 0);
            }

            for (int j = 1; j < mat[0].length; j++) {
                sortDiagonalBubbleSort(mat, 0, j);
            }

            return mat;

        }

        private void sortDiagonalBubbleSort(int[][] mat, int startI, int startJ) {
            for(int outerLoopI = startI, outerLoopJ = startJ;
                    outerLoopI < mat.length && outerLoopJ < mat[0].length;
                    outerLoopI++, outerLoopJ++) {

                for (int i = outerLoopI, j = outerLoopJ; i < mat.length && j < mat[0].length; i++, j++) {
                    int lhs = mat[outerLoopI][outerLoopJ];
                    int rhs = mat[i][j];
                    if (lhs > rhs) {
                        mat[outerLoopI][outerLoopJ] = rhs;
                        mat[i][j] = lhs;
                    }
                }
            }
        }

        private void sortDiagonalMergeSort(int[][] mat, int startI, int startJ) {
            int elements = Math.min(mat.length - startI, mat[0].length - startJ);
            sortDiagonalMergeSort(mat, startI, startJ, startI + elements, startJ + elements);
        }

        private void sortDiagonalMergeSort(int[][] mat, int startI, int startJ, int endI, int endJ) {
            if (startI == endI || startJ == endJ) return;
            int midI = (startI + endI) / 2;
            int midJ = (startJ + endJ) / 2;
            sortDiagonalMergeSort(mat, startI, startJ, midI, midJ);
            sortDiagonalMergeSort(mat, midI + 1, midJ + 1, endI, endJ);
            mergeDiagonal(mat, startI, startJ, midI, midJ, endI, endJ);
        }

        private void mergeDiagonal(int[][] mat, int startI, int startJ, int midI, int midJ, int endI, int endJ) {
            while (startI < midI && startJ < midJ && midI < endI && midJ < endJ) {
                int lhs = mat[startI][startJ];
                int rhs = mat[midI][midJ];
                if (lhs > rhs) {
                    mat[startI][startJ] = rhs;
                    mat[midI][midJ] = lhs;
                }
                startI++;
                startJ++;
            }
        }

    }
}
