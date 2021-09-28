package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class MergeIntervals_56 {
    class Solution {
        public int[][] merge(int[][] intervals) {
            Arrays.sort(intervals, Comparator.comparing(a -> a[0]));
            int[] lastInterval = intervals[0];
            List<int[]> ans = new ArrayList<>();
            for (int i = 1; i < intervals.length; i++) {
                int[] cand = intervals[i];
                if (cand[0] >= lastInterval[0] && cand[0] <= lastInterval[1]) {
                    lastInterval[0] = Math.min(lastInterval[0], cand[0]);
                    lastInterval[1] = Math.max(lastInterval[1], cand[1]);
                } else {
                    ans.add(lastInterval);
                    lastInterval = cand;
                }
            }
            ans.add(lastInterval);
            return ans.toArray(new int[][]{});
        }
    }
}
