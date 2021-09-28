package com.switchcase.ps.leetcode;

import java.util.*;

public class Permutations2_47 {

    class Solution {
        public List<List<Integer>> permuteUnique(int[] nums) {
            Arrays.sort(nums);
            Map<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                counts.putIfAbsent(nums[i], 0);
                counts.put(nums[i], counts.get(nums[i]) + 1);
            }
            List<List<Integer>> ans = new ArrayList<>();
            permute(new int[nums.length], counts, 0, ans);
            return ans;
        }

        private void permute(int[] nums, Map<Integer, Integer> counts, int start, List<List<Integer>> ans) {
            if (start == nums.length) {
                List<Integer> p = new ArrayList<>();
                for (int i = 0; i < nums.length; i++) p.add(nums[i]);
                ans.add(p);
                return;
            }
            for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
                if (entry.getValue() > 0) {
                    nums[start] = entry.getKey();
                    int count = entry.getValue();
                    counts.put(entry.getKey(), count - 1);
                    permute(nums, counts, start + 1, ans);
                    counts.put(entry.getKey(), count);
                }
            }
        }
    }
}
