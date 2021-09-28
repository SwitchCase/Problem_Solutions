package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Permutations_46 {

    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> ans = new ArrayList<>();
            permute(nums, ans, 0);
            return ans;
        }

        private void permute(int[] nums, List<List<Integer>> ans, int start) {
            if (start == nums.length - 1) {
                List<Integer> perm = new ArrayList<>();
                for (int i = 0; i < nums.length; i++) perm.add(nums[i]);
                ans.add(perm);
                return;
            }
            permute(nums, ans, start + 1);
            for (int i = start + 1; i < nums.length; i++) {
                swap(nums, start, i);
                permute(nums, ans, start + 1);
                swap(nums, start, i);
            }

        }

        private void swap(int[] nums, int start, int i) {
            int t = nums[start];
            nums[start] = nums[i];
            nums[i] = t;
        }
    }
}
