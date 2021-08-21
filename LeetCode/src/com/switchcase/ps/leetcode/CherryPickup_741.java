package com.switchcase.ps.leetcode;

public class CherryPickup_741 {

    static class Solution {
        public int cherryPickup(int[][] grid) {
            int rows = grid.length;
            int columns = grid[0].length;
            int sum = rows + columns;
            return Math.max(0, pick(grid, rows, columns, 0,0,0, new Integer[rows][rows][sum]));
        }

        int pick(int[][] grid, int rows, int columns, int r1, int r2, int sum, Integer[][][] dp) {

            int c1 = sum - r1;
            int c2 = sum - r2;

            if (r1 >= rows || r2 >= rows || c1 >= columns || c2 >=columns || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                return -100000;
            }

            if (dp[r1][r2][sum] != null) {
                return dp[r1][r2][sum];
            }

            int cherries = 0;

            if (r1 == r2 && c1 == c2) {
                cherries = grid[r1][c1];
            }
            else {
                cherries =  grid[r1][c1] + grid[r2][c2];
            }
            if (!(r1 == rows-1 && c1 == columns-1 && r1 == r2 && c1 == c2)) {
                cherries += maxOf(
                        pick(grid, rows, columns, r1 + 1, r2 + 1, sum + 1, dp),
                        pick(grid, rows, columns, r1, r2 + 1, sum + 1, dp),
                        pick(grid, rows, columns, r1 + 1, r2, sum + 1, dp),
                        pick(grid, rows, columns, r1, r2, sum + 1, dp));
            }

            return dp[r1][r2][sum] = cherries;

        }

        int maxOf(int...a) {
            int mx = a[0];
            for (int i = 1; i < a.length; i++) mx = Math.max(mx, a[i]);
            return mx;
        }
    }


    static class SolutionN4 {
        public int cherryPickup(int[][] grid) {
            int rows = grid.length;
            int columns = grid[0].length;
            return Math.max(0, pick(grid, rows, columns, 0,0,0,0, new Integer[rows][columns][rows][columns]));
        }

        int pick(int[][] grid, int rows, int columns, int r1, int c1, int r2, int c2, Integer[][][][] dp) {

            if (r1 >= rows || r2 >= rows || c1 >= columns || c2 >=columns || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                return -100000;
            }

            if (dp[r1][c1][r2][c2] != null) {
                return dp[r1][c1][r2][c2];
            }

            int cherries = 0;

            if (r1 == r2 && c1 == c2) {
                cherries = grid[r1][c1];
            }
            else {
                cherries =  grid[r1][c1] + grid[r2][c2];
            }
            if (!(r1 == rows-1 && c1 == columns-1 && r1 == r2 && c1 == c2)) {
                cherries += maxOf(
                        pick(grid, rows, columns, r1 + 1, c1, r2 + 1, c2, dp),
                        pick(grid, rows, columns, r1, c1 + 1, r2 + 1, c2, dp),
                        pick(grid, rows, columns, r1 + 1, c1, r2, c2 + 1, dp),
                        pick(grid, rows, columns, r1, c1 + 1, r2, c2 + 1, dp));
            }

            return dp[r1][c1][r2][c2] = cherries;

        }

        int maxOf(int...a) {
            int mx = a[0];
            for (int i = 1; i < a.length; i++) mx = Math.max(mx, a[i]);
            return mx;
        }
    }


    static class SolutionDoublePassWA {

        private static final int NEG_WEIGHT = -1000000;

        class Cell {
            int total;
            int path; // 1: left, 2: up
            Cell(int total, int path) {
                this.total = total;
                this.path = path;
            }
        }

        public int cherryPickup(int[][] grid) {
            int rows = grid.length;
            int columns = grid[0].length;
            Cell[][] newGrid = traverse(grid, rows, columns);
            int ans = newGrid[rows - 1][columns - 1].total;
            if (ans <= 0) return 0;
            int i = rows - 1;
            int j = columns - 1;
            while (i >=0 && j >=0) {
                grid[i][j] = 0;
                if (newGrid[i][j].path == 1) {
                    j--;
                }
                else if (newGrid[i][j].path == 2) {
                    i--;
                } else {
                    break; //means we reached end.
                }
            }
            //re traverse the graph.
            Cell[][] reverseGrid = traverse(grid, rows, columns);
            ans += reverseGrid[rows-1][columns-1].total;
            return ans;
        }

        Cell[][] traverse(int[][] grid, int rows, int columns) {
            Cell[][] newGrid = new Cell[rows][columns];
            for (int i = 0; i < rows; i++) for (int j = 0; j < columns; j++)
                newGrid[i][j] = new Cell(NEG_WEIGHT, 0);

            newGrid[0][0].total = grid[0][0];

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (i < rows - 1) {
                        int curr = newGrid[i + 1][j].total;
                        if (grid[i + 1][j] >= 0 && curr < (newGrid[i][j].total + grid[i + 1][j]) ) {
                            newGrid[i+1][j].total = newGrid[i][j].total + grid[i + 1][j];
                            newGrid[i+1][j].path = 2;
                        }
                    }
                    if (j < columns - 1) {
                        int curr = newGrid[i][j + 1].total;
                        if (grid[i][j + 1] >= 0 && curr < (newGrid[i][j].total + grid[i][j + 1]) ) {
                            newGrid[i][j + 1].total = newGrid[i][j].total + grid[i][j+1];
                            newGrid[i][j+1].path = 1;
                        }
                    }
                }
            }
            return newGrid;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().cherryPickup(new int[][]{{0, 1, -1}, {1, 0, -1}, {1,1,1}})); // 5
        System.out.println(new Solution().cherryPickup(new int[][]{{1, 1, 1, 1}, {1, 0, 1, 0}, {0 , 0, 1,1}})); //8
        System.out.println(new Solution().cherryPickup(new int[][]{ {1, 1, -1, 1, 1},
                                                                    {1, 1, 1, 1, 1},
                                                                    {-1, 1, 1, -1, -1},
                                                                    {0 , 1, 1, -1, 0},
                                                                    {1, 0, -1, 1, 0} })); //0

    }
}
