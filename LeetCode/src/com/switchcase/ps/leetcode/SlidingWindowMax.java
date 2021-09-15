package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Deque;

/**
 * https://leetcode.com/problems/sliding-window-maximum/
 */
public class SlidingWindowMax {
    class SolutionDP {
        public int[] maxSlidingWindow(int[] nums, int k) {
            if (k == 1 || nums.length == 0) return nums;
            if (k == 0) return new int[0];
            int[] left = new int[nums.length];
            int[] right = new int[nums.length];
            int n = nums.length;

            left[n - 1] = nums[n-1];
            right[0] = nums[0];

            for (int i = 1; i <= n - 1; i++) {
                int j = n - 1 - i;
                left[j] = (j%k == k - 1) ? nums[j] : Math.max(nums[j], left[j+1]);
                right[i] = (i%k == 0) ? nums[i] : Math.max(nums[i], right[i-1]);
            }
            int[] ans = new int[n-k+1];
            for (int i = 0; i < n - k + 1; i++) {
                ans[i] = Math.max(left[i], right[i+k-1]);
            }
            return ans;
        }
    }

    class Solution {
        public int[] maxSlidingWindow(int[] a, int k) {
            if (a == null || k <= 0) return new int[0];
            int[] ans = new int[a.length - k + 1];
            Deque<Integer> deque = new ArrayDeque<>();
            for (int i = 0; i < a.length; i++) {
                //first is oldest and largest.

                while(!deque.isEmpty() && deque.peekFirst() < i - k + 1) {
                    deque.pollFirst();
                }

                while(!deque.isEmpty() && a[deque.peekLast()] <= a[i]) {
                    deque.pollLast();
                }
                deque.offerLast(i);
                if (i - k + 1 >= 0) {
                    ans[i - k + 1] = a[deque.peekFirst()];
                }
            }
            return ans;

        }
    }
}
