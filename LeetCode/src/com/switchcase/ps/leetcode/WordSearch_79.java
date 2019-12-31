package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/word-search/
 */
public class WordSearch_79 {
    class Solution {
        public boolean exist(char[][] board, String word) {
            if (word.length() == 0 || board.length == 0) return false;
            char start = word.charAt(0);
            int r = board.length;
            int c = board[0].length;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (board[i][j] == start) {
                        boolean[][] state = new boolean[r][c];
                        state[i][j] = true;
                        boolean result = search(board, word, state, i,j, 1);
                        if (result) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        private boolean search(char[][] board, String word, boolean[][] state, int si, int sj, int cpos) {
            if (cpos >= word.length()) return true;
            int[] dr = {1, -1, 0, 0};
            int[] dc = {0, 0, -1, 1};
            int r = board.length;
            int c = board[0].length;
            for (int d = 0; d < 4; d++) {
                int di = si + dr[d];
                int dj = sj + dc[d];
                if (valid(di, dj, r, c) && !state[di][dj] && board[di][dj] == word.charAt(cpos)) {
                    state[di][dj] = true;
                    boolean result = search(board, word, state, di, dj, cpos+1);
                    if (result) return result;
                    state[di][dj] = false;
                }
            }
            return false;
        }

        private boolean valid(int di, int dj, int r, int c) {
            return di >=0 && dj >=0 && di < r && dj < c;
        }
    }
}
