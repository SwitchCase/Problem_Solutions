package com.switchcase.ps.leetcode;

public class MaxSumCircularSubarray_918 {

    class Solution {
        public int maxSubarraySumCircular(int[] A) {
            long max = Long.MIN_VALUE, min = Long.MAX_VALUE;
            int currMax = 0, currMin = 0;
            int total = 0;
            for (int i = 0; i < A.length; i++) {
                currMax = Math.max(currMax + A[i], A[i]);
                max = Math.max(max, currMax);
                currMin = Math.min(currMin + A[i], A[i]);
                min = Math.min(min, currMin);
                total += A[i];
            }
            if (total - min == 0) return (int) max;
            return (int) Math.max(max, total - min);
        }
    }
}
