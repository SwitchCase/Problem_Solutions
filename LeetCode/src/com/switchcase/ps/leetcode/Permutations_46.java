package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Permutations_46 {

    class Solution {
        public List<List<Integer>> permute(int[] nums) {
            Arrays.sort(nums);
            List<List<Integer>> ans = new ArrayList<>();
            List<Integer> soFar = new ArrayList<>();
            permute(nums, new boolean[nums.length], soFar, nums.length, ans);
            return ans;
        }

        private void permute(int[] nums, boolean[] visited, List<Integer> soFar, int max, List<List<Integer>> ans) {
            if (soFar.size() == max) {
                ans.add(new ArrayList<>(soFar));
                return;
            }
            for (int i = 0; i < visited.length; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    soFar.add(nums[i]);
                    permute(nums, visited, soFar, max, ans);
                    visited[i] = false;
                    soFar.remove(soFar.size() - 1);
                }
            }
        }
    }
}
