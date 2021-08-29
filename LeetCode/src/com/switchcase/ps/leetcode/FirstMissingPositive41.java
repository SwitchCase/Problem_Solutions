package com.switchcase.ps.leetcode;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/first-missing-positive/
 */
public class FirstMissingPositive41 {
    static class Solution {
        public int firstMissingPositive(int[] nums) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] <= 0 || nums[i] > nums.length) continue;
                int v = nums[i] - 1;
                while (v >= 0 && v < nums.length && nums[v] != v + 1) {
                    int t = nums[v];
                    nums[v] = v + 1;
                    v = t - 1;
                }
            }
            int ans = 1;
            for (;ans <= nums.length; ans++) {
                if(nums[ans - 1] != ans) {
                    return ans;
                }
            }
            return ans;
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
