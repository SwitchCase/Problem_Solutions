package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Collectors;

public class MinimumArrows452 {

    class Solution {

        public int findMinArrowShots(int[][] input) {
            int[][] sorted = Arrays.stream(input)
                    .sorted(Comparator.comparingInt(array -> array[0]))
                    .collect(Collectors.toList())
                    .toArray(new int[0][0]);
            int arrow = 0;
            int count = sorted.length;
            int idx = 0;

            while (idx < count) {
                int start = idx + 1;
                int oxStart = sorted[idx][0];
                int oxEnd = sorted[idx][1];

                while (start < count) {
                    if (overlap(oxStart, oxEnd, sorted[start][0], sorted[start][1])
                            || overlap(sorted[start][0], sorted[start][1], oxStart, oxEnd)) {
                        oxStart = Math.max(oxStart, sorted[start][0]);
                        oxEnd = Math.min(oxEnd, sorted[start][1]);
                        start++;
                    } else {
                        break;
                    }
                }
                arrow++;
                idx = start;
            }
            return arrow;
        }

        private boolean overlap(int sA, int eA, int sB, int eB) {
            return (sB >= sA && sB <= eA);
        }
    }
}
