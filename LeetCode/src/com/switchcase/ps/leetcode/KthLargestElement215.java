package com.switchcase.ps.leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Random;

/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
public class KthLargestElement215 {
    class SolutionPQ {
        public int findKthLargest(int[] nums, int k) {
            PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);

            for (int n : nums) {
                if (pq.size() >= k) {
                    if (pq.peek() < n) {
                        pq.poll();
                        pq.add(n);
                    }
                } else {
                    pq.add(n);
                }
            }
            return pq.poll();
        }
    }

    static class Solution {
        Random random = new Random();

        public int findKthLargest(int[] nums, int k) {
            int idx = solve(nums, nums.length - k, 0, nums.length - 1);
            return nums[idx];
        }

        private int solve(int[] nums, int k, int sIdx, int eIdx) {
            int lo = partition(nums, sIdx, eIdx);
            if (k == lo) return lo;
            if (k < lo) {
                return solve(nums, k, sIdx, lo - 1);
            } else {
                return solve(nums, k, lo + 1, eIdx);
            }
        }

        //sIdx and eIdx are inclusive.
        private int partition(int[] nums, int sIdx, int eIdx) {
            int rIdx = random.nextInt(eIdx - sIdx + 1) + sIdx;
            int pivot = nums[rIdx];
            swap(nums, rIdx, eIdx);
            int lo = sIdx, hi = eIdx - 1;
            while (lo <= hi) {
                if (nums[lo] > pivot) {
                    swap(nums, lo, hi);
                    hi--;
                } else {
                    lo++;
                }
            }
            swap(nums, lo, eIdx);
            return lo;
        }

        private void swap(int[] nums, int aIdx, int bIdx) {
            int t = nums[aIdx];
            nums[aIdx] = nums[bIdx];
            nums[bIdx] = t;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {3,2,3,1,2,4,5,5,6};
        System.out.println(sol.findKthLargest(arr, 4));
    }
}
