package com.switchcase.ps.leetcode;

import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class TopKFrequentElements_347 {

    class Solution {
        public int[] topKFrequent(int[] nums, int k) {

            Map<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                counts.putIfAbsent(nums[i], 0);
                counts.put(nums[i], counts.get(nums[i]) +1 );
            }
            List<int[]> sorted = counts.entrySet().stream()
                    .map(e -> new int[] {e.getKey(), e.getValue()})
                    .sorted(Comparator.comparingInt((int[] a) -> a[1]).reversed())
                    .collect(Collectors.toList());
            int[]  ans = new int[k];
            for (int i = 0; i < k; i++) {
                ans[i] = sorted.get(i)[0];
            }
            return ans;
        }
    }
}
