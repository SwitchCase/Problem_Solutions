package com.switchcase.ps.leetcode;

public class NextPermutation_31 {

    class Solution {
        public int[] testHelper(int[] nums) {
            nextPermutation(nums);
            return nums.clone();
        }
        public void nextPermutation(int[] nums) {
            int i = nums.length - 2;
            for (; i >=0; i--) {
                if (nums[i] >= nums[i+1]) continue;
                else break;
            }
            if (i >= 0) {
                int j = nums.length - 1;
                while( j >= 0 && nums[i] >= nums[j]) {
                    j--;
                }
                swap(nums, i, j);
            }
            reverse(nums, i + 1);
        }

        private void reverse(int[] nums, int s) {
            int i = s, j = nums.length - 1;
            while (i < j) {
                swap(nums, i, j);
                i++;
                j--;
            }
        }

        private void swap(int[] nums, int i, int j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
}
