package com.switchcase.ps.leetcode;

import java.util.Random;

/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */
public class SearchRotatedArray_33 {
    class Solution {
        public int search(int[] nums, int target) {
            int pivot = findPivot(nums);
            int lo = 0, hi = nums.length - 1;

            if (nums[0] == target) return 0;

            if (target > nums[0]) {
                hi = (pivot - 1 + nums.length) % nums.length;
            } else {
                lo = pivot;
            }

            while (lo < hi) {
                int mid = (lo + hi)/2;
                if (nums[mid] == target) {
                    return mid;
                }

                if (mid == lo) break;
                if (nums[mid] > target) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            if (nums[lo] == target) {
                return lo;
            }
            if (nums[hi] == target) {
                return hi;
            }
            return -1;
        }

        private int findPivot(int[] nums) {
            if (nums[0] < nums[nums.length - 1]) {
                return 0;
            }

            int lo = 0, hi = nums.length - 1;
            while(lo < hi) {
                int mid = (lo+hi)/2;
                if (mid + 1 < nums.length && nums[mid] > nums[mid + 1]) {
                    return mid + 1;
                }
                if (nums[mid] < nums[hi]) {
                    hi = mid;
                } else {
                    lo = mid - 1;
                }
            }
            return lo;
        }
    }

    public static void main(String[] args) {
        int[][] cases = {
                {2, 2, 2, 2,2,2,2,2, 3,2,2,2,2},
                {120, 199, 201, 232, 1,3, 11, 99, 102, 105},
                {1, 2},
                {1},
                {-1},
                {0},
                {2},
                {-3, 0, 4, 5, 7},
                {5, 1},
                {4,5,6,7,0,1,2},
                {4,5,6,7,0,1,2},
                {3, 1},
                {3,1,2}
        };
        Random rand = new Random();
        for (int i = 0; i < cases.length; i++){
            int[] kase = cases[i];
            int ans = rand.nextInt(kase.length);
            int target = kase[ans];
           // System.out.println("Input: " + Arrays.toString(kase) + ", target = " + target + " ; output: " + new Solution().search(kase, target) +" expected: " + ans);
        }
    }
}
