package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/minimum-size-subarray-sum/
 */
public class MinSizeSubarraySum {
    class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int start = 0, end = 0;
            int bestSize = Integer.MAX_VALUE;
            int sum = 0;
            while(end < nums.length) {
                while (end < nums.length && sum < s) {
                    sum += nums[end++];
                    if (sum >= s) {
                        bestSize = Math.min(bestSize, end - start);
                    }
                }
                while (start <= end && sum >= s) {
                    sum -= nums[start++];
                    if (sum >= s) {
                        bestSize = Math.min(bestSize, end - start);
                    }
                }
            }
            return bestSize == Integer.MAX_VALUE ? 0 : bestSize;
        }
    }
}
