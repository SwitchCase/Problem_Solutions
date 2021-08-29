package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode.com/problems/maximum-product-subarray/
 */
public class MaxProductSubarray_152 {

    class Solution {
        public int maxProduct(int[] nums) {
            long[][] dp = new long[nums.length + 1][2];

            dp[nums.length][0] = 1;
            dp[nums.length][1] = 1;
            long ans = Long.MIN_VALUE;

            for (int i = nums.length - 1; i >=0; i--) {
                int curr = nums[i];
                long pVal = Math.max(curr, Math.max(dp[i+1][0] * curr, dp[i+1][1] * curr));
                long lVal = Math.min(curr, Math.min(dp[i+1][0] * curr, dp[i+1][1] * curr));
                dp[i][0] = pVal;
                dp[i][1] = lVal;
                ans = Math.max(ans, Math.max(pVal, lVal));
            }
            return (int) ans;
        }
    }
}
