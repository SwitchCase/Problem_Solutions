package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class MergeIntervals_56 {
    class Solution {
        public int[][] merge(int[][] intervals) {
            if (intervals.length == 0) return intervals;
            Arrays.sort(intervals, Comparator.comparingInt((int[] a) -> a[0]));
            List<int[]> merged = new ArrayList<>();
            merged.add(intervals[0]);
            for (int i = 1; i < intervals.length; i++) {
                if (mergeable( merged.get(merged.size() - 1), intervals[i])) {
                    int[] prev =  merged.get(merged.size() - 1);
                    merged.remove(merged.size() - 1);
                    merged.add(mergeIt(prev, intervals[i]));
                } else {
                    merged.add(intervals[i]);
                }
            }
            int[][] ans = new int[merged.size()][2];
            return merged.toArray(ans);
        }

        private int[] mergeIt(int[] A, int[] B) {
            return new int[] {A[0], Math.max(A[1], B[1])};
        }

        private boolean mergeable(int[] A, int[] B) {
            return A[1] >= B[0];
        }
    }
}
