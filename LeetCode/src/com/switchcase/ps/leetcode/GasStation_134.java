package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * https://leetcode.com/problems/gas-station/
 */
public class GasStation_134 {

    static class Solution {
        public int canCompleteCircuit(int[] gas, int[] cost) {
            int[] deltas = new int[gas.length];
            int total = 0;
            int maxDelta = Integer.MIN_VALUE, maxDeltaPos = 0;
            List<int[]> deltaLst = new ArrayList<>();
            for (int i = 0; i < gas.length; i++) {
                deltas[i] = gas[i] - cost[i];
                total += deltas[i];
                if (maxDelta < deltas[i]) {
                    maxDelta = deltas[i];
                    maxDeltaPos = i;
                }
                if (deltas[i] > 0)
                    deltaLst.add(new int[]{deltas[i], i});
            }
            if (total < 0) return -1;

            Collections.sort(deltaLst, (int[] a, int[] b) -> b[0] - a[0]);

            for (int i = 0; i < deltaLst.size(); i++) {
                if (check(gas, cost, deltaLst.get(i)[1])) {
                    return deltaLst.get(i)[1];
                }
            }
            return -1;
        }

        private boolean check(int[] gas, int[] cost, int start) {
            int rem = 0;
            int n = gas.length;
            for (int i = 0; i < n; i++) {
                int pos = (start + i) % n;
                int delta = rem + gas[pos] - cost[pos];
                if (delta < 0) {
                    return false;
                }
                rem = delta;
            }
            return true;
        }
    }
}
