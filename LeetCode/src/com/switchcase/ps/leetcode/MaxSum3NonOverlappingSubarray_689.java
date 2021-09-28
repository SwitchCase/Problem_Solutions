package com.switchcase.ps.leetcode;

import java.util.*;

public class MaxSum3NonOverlappingSubarray_689 {

    class Solution {
        public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
            int[] sums = new int[nums.length - k + 1];
            int sum = 0;
            int idx = 0;
            for (int i = 0; i < nums.length; i++) {
                if (i < k) {
                    sum += nums[i];
                } else {
                    sums[idx++] = sum;
                    sum += nums[i];
                    sum -= nums[i - k];
                }
            }
            sums[idx] = sum;
            int N = sums.length;
            int[] left = new int[N];
            int[] right = new int[N];
            left[0] = 0;
            right[N-1] = N-1;
            int max = 0;
            for (int i = 1; i < N; i++) {
                if (sums[i] > sums[max]) {
                    max = i;
                }
                left[i] = max;
            }
            max = N - 1;
            for (int i = N-2; i>=0; i--) {
                if (sums[i] >= sums[max]) {
                    max = i;
                }
                right[i] = max;
            }
            int[] ans = new int[3];

            max = Integer.MIN_VALUE;
            for (int i = k; i < N - k; i++) {
                int l = sums[left[i-k]];
                int m = sums[i];
                int r = sums[right[i+k]];
                if (l + r + m > max) {
                    ans = new int[] {left[i-k], i, right[i+k]};
                    max = l + r + m;
                }
            }
            return ans;
        }

    }

    //Causes Stack overflow exceptions
    class SolutionRecursive {

        class Answer {
            int val;
            List<Integer> indices;

            Answer(int n) {
                this.val = n;
                this.indices = new ArrayList<>();
            }

            Answer() {
                this.val = -1000000;
                this.indices = Collections.emptyList();
            }

            Answer(int v, int idx) {
                this.val = v;
                this.indices = new ArrayList<>();
                indices.add(idx);
            }
        }

        public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
            int[] runSum = new int[nums.length - k + 1];
            Deque<Integer> queue = new ArrayDeque<>();
            int sum = 0;
            for (int i = 0; i < k; i++) {
                sum+= nums[i];
                queue.addLast(nums[i]);
            }
            int idx = 0;
            runSum[idx++] = sum;
            for (int i = k; i < nums.length; i++) {
                int rem = queue.pollFirst();
                sum -= rem;
                sum += nums[i];
                runSum[idx++] = sum;
                queue.addLast(nums[i]);
            }
            Answer ans = recurse(3, 0, runSum, new Answer[idx][4]);
            int[] result = new int[3];
            for (int i = 0; i < ans.indices.size(); i++) result[i] = ans.indices.get(i);
            return result;
        }

        private Answer recurse(int rem, int start, int[] arr, Answer[][] dp) {
            if (rem == 0) return new Answer(0);
            if (start >= arr.length) return new Answer();
            if (dp[start][rem] != null) return dp[start][rem];
            Answer best = new Answer();
            Answer answer = recurse(rem - 1, start + 2, arr, dp);
            if (answer.val + arr[start] > best.val) {
                best = new Answer(answer.val + arr[start], start);
                best.indices.addAll(answer.indices);
            }
            answer = recurse(rem, start + 1, arr, dp);

            if (answer.val > best.val) {
                best = answer;
            }
            return dp[start][rem] = best;
        }
    }
}
