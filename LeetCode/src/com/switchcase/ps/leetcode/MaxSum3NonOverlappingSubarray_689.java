package com.switchcase.ps.leetcode;

import java.util.*;

public class MaxSum3NonOverlappingSubarray_689 {

    class Solution {

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
            Answer ans = Nonrecurse(k, 3, 0, runSum, new Answer[idx][4]);
            int[] result = new int[3];
            for (int i = 0; i < ans.indices.size(); i++) result[i] = ans.indices.get(i);
            return result;
        }

        private Answer Nonrecurse(int subArraySize, int rem, int start, int[] arr, Answer[][] dp) {
            int bestV = -1000000, bestIdx = -1;
            for (int i = 0; i < arr.length; i++) {
                dp[i][1] = new Answer();
                dp[i][2] = new Answer();
                dp[i][3] = new Answer();
            }

            //for 1:
            for (int i = arr.length - 1; i >= 0; i--) {
                if (arr[i] >= bestV) {
                    bestV = arr[i];
                    bestIdx = i;
                }
                dp[i][1] = new Answer(bestV, bestIdx);
            }

             for (int k = 2; k <= 3; k++) {
                 for (int i = arr.length - 1 - subArraySize; i >= 0; i--) {
                     Answer answer = new Answer();
                     if (!dp[i + subArraySize][k - 1].indices.isEmpty()) {
                         if (answer.val <= dp[i + subArraySize][k - 1].val + arr[i]) {
                             answer = new Answer(dp[i + subArraySize][k - 1].val + arr[i], i);
                             answer.indices.addAll(dp[i + subArraySize][k - 1].indices);
                         }
                     }
                     if (!dp[i + 1][k].indices.isEmpty()) {
                         if (answer.val < dp[i + 1][k].val || answer.indices.isEmpty()) {
                             answer = new Answer(dp[i + 1][k].val);
                             answer.indices.addAll(dp[i + 1][k].indices);
                         }
                     }
                     dp[i][k] = answer;
                 }
             }
             return dp[0][3];
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
