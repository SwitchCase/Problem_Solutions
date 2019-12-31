package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Random;

/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */
public class FindRangeInSortedArray_34 {
    static class Solution {
        public int[] searchRange(int[] nums, int target) {
            if (nums.length == 0) return new int[] {-1, -1};
            int lhs = findSmallest(nums, target);
            int rhs = findLargest(nums, target);
            if (lhs == -1 || rhs == -1) {
                return new int[] {-1, -1};
            }
            return new int[]{lhs, rhs};
        }

        //return index of largest number smaller than target. -1 if target does not exist.
        private int findSmallest(int[] nums, double target) {
            int lo = 0, hi = nums.length - 1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                if (nums[mid] < target) lo = mid + 1;
                else hi = mid;
            }
            if (nums[lo] == target) return lo;
            return -1;
        }

        //return is index of target such than nums[pos - 1] < nums[pos] && nums[pos] == target
        private int findLargest(int[] nums, int target) {
            int lo = 0, hi = nums.length - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1)/2;
                if (nums[mid] > target) hi = mid - 1;
                else lo = mid ;
            }
            if (nums[lo] == target) return lo;
            return -1;
        }
    }

    public static void main(String[] args) {
        int[][] cases = {
                {5,7,7,8,8,10},
                {1, 2},
                {1, 1, 2, 2, 3,4,4,4,5,6,7,8},
                {1},
                {-1},
                {0},
                {2},
        };
        Random rand = new Random();
        for (int[] kase: cases){
            int ans = rand.nextInt(kase.length);
            int target = kase[ans];
            System.out.println("Input: " + Arrays.toString(kase) + ", target = " + target + " ; output: " + Arrays.toString(new Solution().searchRange(kase, target)) +" expected: " + ans);
        }
    }
}
