package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Queue;

/**
 * https://leetcode.com/problems/word-search/
 */
public class WordSearch_79 {
    class Solution {
        public boolean exist(char[][] board, String word) {
            if (board.length == 0) return false;

            int N = board.length;
            int M = board[0].length;
            int[][] done = new int[N][M];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    done[i][j] = 1;
                    if (board[i][j] == word.charAt(0) && search(board, N, M, i, j, word, done, 1)) {
                        return true;
                    }
                    done[i][j] = 0;
                }
            }
            return false;
        }

        private boolean search(char[][] board, int N, int M, int sN, int sM, String word, int[][] done, int cpos) {
            if (cpos >= word.length()) {
                return true;
            }

            int[] dN = {0, 0, -1, 1};
            int[] dM = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++) {
                int nn = dN[i] + sN;
                int mm = dM[i] + sM;
                if (nn >= 0 && mm >= 0 && nn < N && mm < M) {
                    if (done[nn][mm] == 0) {
                        done[nn][mm] = 1;
                        if(board[nn][mm] == word.charAt(cpos) &&
                                search(board, N, M, nn, mm, word, done, cpos + 1)) {
                            return true;
                        }
                        done[nn][mm] = 0;
                    }
                }
            }
            return false;
        }
    }
}
