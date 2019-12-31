package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * https://leetcode.com/problems/maximum-product-subarray/
 */
public class MaxProductSubarray_152 {

    static class Solution {
        public int maxProduct(int[] nums) {
            long[][] dp = new long[nums.length][2];
            int n = nums.length;
            dp[n-1][0] = dp[n-1][1] = nums[n-1];
            for (int i = n - 2; i >= 0; i--) {
                int m = nums[i];
                long a = m * dp[i+1][0];
                long b = m * dp[i+1][1];
                dp[i][0] = Math.max(m, Math.max(a, b));
                dp[i][1] = Math.min(m, Math.min(a, b));
            }
            long ans = Integer.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, dp[i][0]);
            }
            return (int) ans;
        }
    }

    public static void main(String[] args) {
        int[][] cases = {
                {2, 3, -2, 4},
                {-2, 0, -1},
                {-2, 4, 2, -1, 3, -1, -1, -1}
        };
        for (int[] kase : cases) {
            System.out.println("Case: " + Arrays.toString(kase) + ": " + new Solution().maxProduct(kase));
        }
    }
}
