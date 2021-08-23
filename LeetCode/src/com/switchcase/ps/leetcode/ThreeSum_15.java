package com.switchcase.ps.leetcode;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ThreeSum_15 {

    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            Arrays.sort(nums);

            List<List<Integer>> result = new ArrayList<>();
            Set<Integer> done = new HashSet<>();

            for (int i = 0; i < nums.length; i++) {
                if (done.contains(nums[i])) continue;
                result.addAll(twoSums(nums, i+1, - nums[i], nums[i]));
                done.add(nums[i]);
            }

            return result.stream().distinct().collect(Collectors.toList());
        }

        private List<List<Integer>> twoSums(int[] nums, int start, int target, int valToAdd) {
            List<List<Integer>> result = new ArrayList<>();

            int lo = start;
            int hi = nums.length - 1;

            while(lo < hi) {
                int total = nums[lo] + nums[hi];
                if (total == target) {
                    result.add(Stream.of(valToAdd, nums[lo], nums[hi]).sorted().collect(Collectors.toList()));
                    lo = lo + 1;
                    hi = hi - 1;
                } else if (total > target) {
                    hi = hi - 1;
                } else {
                    lo = lo + 1;
                }
            }

            return result;
        }
    }
}
