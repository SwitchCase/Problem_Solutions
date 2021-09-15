package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class JumpGameVI_1696 {

    class Solution {
        public int maxResult(int[] nums, int k) {
            int n = nums.length;
            int[] dp = new int[n];
            Arrays.fill(dp, Integer.MIN_VALUE);
            dp[n - 1] = nums[n-1];

            //largest and oldest is at first.

            Deque<Integer> deque = new ArrayDeque<>();
            deque.offerFirst(n - 1);

            for (int i = n - 2; i >= 0; i--) {
                while(!deque.isEmpty() && deque.peekFirst() > i + k) {
                    deque.pollFirst();
                }

                dp[i] = nums[i] + dp[deque.peekFirst()];

                while(!deque.isEmpty() && dp[deque.peekLast()] <= dp[i]) {
                    deque.pollLast();
                }
                deque.offerLast(i);
            }
            return dp[0];
        }
    }
}
