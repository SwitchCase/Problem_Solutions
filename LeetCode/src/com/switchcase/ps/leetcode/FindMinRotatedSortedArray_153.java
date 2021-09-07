package com.switchcase.ps.leetcode;

public class FindMinRotatedSortedArray_153 {

    class Solution {
        public int findMin(int[] nums) {
            int lo = 0, hi = nums.length;
            while(lo < hi) {
                int mid = (hi + lo) / 2;
                if (mid + 1 < nums.length && nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                } else {
                    if (nums[mid] >= nums[lo]) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
            }
            return nums[0];
        }
    }
}
