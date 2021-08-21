package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 */
public class MinSizeSubarraySum {
    static class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int start = 0, end = 0;
            int best = Integer.MAX_VALUE;
            int curr = 0;
            while (end < nums.length) {
                curr += nums[end];
                while (curr >= s && start <= end) {
                    best = Math.min(best, end - start + 1);
                    curr -= nums[start++];
                }
                end++;
            }

            if (best == Integer.MAX_VALUE) return 0;
            return best;
        }
    }
}
