package com.switchcase.ps.leetcode;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/first-missing-positive/
 */
public class FirstMissingPositive41 {
    static class Solution {
        public int firstMissingPositive(int[] nums) {
            int n = nums.length;
            if (n == 0) return 1;
            int k = n + 1;
            for (int i = 0; i < n; i++) nums[i]--;

            for (int i = 0; i < n; i++) {
                while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]]) {
                    swap(nums, i, nums[i]);
                }
            }
            int i = 0;
            for (; i < n; i++) {
                if(nums[i] != i) {
                    return i + 1;
                }
            }
            return i+1;
        }

        private void swap(int[] nums, int i, int j) {
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }
    }

    public static void main(String[] args) {
        int[][] cases = {
                {1,3},
                {1, 2},
                {1},
                {-1},
                {0},
                {2},
                {100},
                {-3, 0, 4, 5, 7, 2, 1, 3, 6, 9, 10},
                {},
                {1, 1}
        };
        for (int[] kase: cases){
            System.out.println("Input: " + Arrays.toString(kase) + "; output: " + new Solution().firstMissingPositive(kase));
        }
    }
}
