package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Random;

/**
 * https://leetcode.com/problems/wiggle-sort-ii/
 */
public class WiggleSort2_341 {

    static class Solution {
        Random rand = new Random();
        public void wiggleSort(int[] nums) {
            if (nums.length <= 1) return;
            int medianPos = midLargest(nums);
            int median = nums[medianPos];
            int[] ans = new int[nums.length];
            int odd = 1;
            int even = (nums.length - 1) % 2 == 0 ? nums.length - 1 : nums.length - 2;
            int medCount = 0;
            for(int i = 0; i < nums.length; i++) {
                if (nums[i] < median) {
                    ans[even] = nums[i];
                    even-=2;
                } else if (nums[i] > median) {
                    ans[odd] = nums[i];
                    odd+=2;
                }
            }
            for (;even >=0; even -=2) ans[even] = median;
            for (;odd < nums.length; odd +=2) ans[odd] = median;

            for (int i = 0; i < nums.length; i++) nums[i] = ans[i];
        }

        private int midLargest(int[] nums) {
            int k = (nums.length + 1) / 2;
            int lo = 0;
            int hi = nums.length;
            while(lo < hi) {
                int pivPos = rand.nextInt(hi - lo) + lo;
                int newPivPos = pivotPartition(nums, lo, hi, pivPos);
                if (newPivPos == k) {
                    return newPivPos;
                }
                else if (newPivPos < k) {
                    lo = newPivPos + 1;
                } else {
                    hi = newPivPos;
                }
            }
            return lo;
        }

        private int pivotPartition(int[] nums, int lo, int hi, int pivPos) {
            int pivot = nums[pivPos];
            swap(nums, pivPos, hi - 1);
            int i = lo;
            for (int j = lo; j < hi; j++) {
                if (nums[j] < pivot) {
                    swap(nums, i, j);
                    i++;
                }
            }
            swap(nums, i, hi - 1);
            return i;
        }

        private void swap(int[] nums, int a, int b) {
            int tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }

    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        //int[] nums = new int[] {1,2,1,2,1,2,4,9,7,8,9,8,9,4};
        int[] nums = new int[] {5,6,5,4};
        sol.wiggleSort(nums);
        System.out.println(Arrays.toString(nums));
    }
}
