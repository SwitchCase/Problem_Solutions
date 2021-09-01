package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/gas-station/
 */
public class GasStation_134 {

    class Solution {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            int N = gas.length;
            int[][] delta = new int[N][2];
            for (int i = 0; i < N; i++) {
                delta[i][0] = cost[i] - gas[i];
                delta[i][1] = i;
            }
            Arrays.sort(delta, Comparator.comparingInt(array -> array[0]));
            for (int i = 0; i < delta.length; i++) {
                if (delta[i][0] <= 0) {
                    if (check(gas, cost, delta[i][1])) {
                        return delta[i][1];
                    }
                } else {
                    break;
                }
            }
            return -1;
        }

        private boolean check(int[] gas, int[] cost, int start) {
            int fuel = 0;
            for (int i = start; i < start + gas.length; i++) {
                int idx = i % gas.length;
                if (fuel + gas[idx] >= cost[idx]) {
                    fuel = fuel + gas[idx] - cost[idx];
                } else {
                    return false;
                }
            }
            return true;
        }
    }
}
