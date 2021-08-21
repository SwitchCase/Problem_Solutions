package com.switchcase.ps.leetcode;

import java.util.*;

public class RandomPickIndex_398 {
    class Solution {

        private final Map<Integer, List<Integer>> map;
        private final Random random;

        public Solution(int[] nums) {
            this.random = new Random();
            this.map = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                map.putIfAbsent(nums[i], new ArrayList<>());
                map.get(nums[i]).add(i);
            }
        }

        public int pick(int target) {
            List<Integer> indices = map.getOrDefault(target, Collections.emptyList());
            int v = random.nextInt(indices.size());
            return indices.get(v);
        }
    }
}
