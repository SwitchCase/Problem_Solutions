package com.switchcase.ps.leetcode;

import java.util.*;
import java.util.stream.IntStream;

public class DivideArrayIntoKContinuousSub_1296 {

    static class SolutionGTEK {
        public boolean isPossibleDivide(int[] nums, int k) {
            Arrays.sort(nums);
            Map<Integer, Integer> ends = new HashMap<>();
            Map<Integer, Integer> counts = new HashMap<>();
            for (int n : nums) {
                counts.putIfAbsent(n, 0);
                counts.put(n, counts.get(n) + 1);
            }
            for (int i = 0; i < nums.length; i++) {
                int v = nums[i];
                if (counts.getOrDefault(v, 0) == 0 ) continue;
                if (ends.getOrDefault(v - 1, 0) > 0) {
                    ends.put(v - 1, ends.get(v - 1)  - 1);
                    ends.putIfAbsent(v, 0);
                    ends.put(v, ends.get(v) + 1);
                    counts.put(v, counts.get(v) - 1);
                } else {
                    boolean allPresent = IntStream.range(v + 1, v + k).allMatch(x -> counts.getOrDefault(x, 0) > 0);
                    if (allPresent) {
                        ends.putIfAbsent(v + k - 1, 0);
                        ends.put(v + k - 1, ends.get(v + k - 1) + 1);
                        for (int j = v; j < v + k; j++) {
                            counts.putIfAbsent(j, 0);
                            counts.put(j, counts.get(j) - 1);
                        }
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    static class SolutionSlower {
        public boolean isPossibleDivide(int[] nums, int k) {
            Map<Integer, Integer> counts = new HashMap<>();
            for (int n : nums) {
                counts.putIfAbsent(n, 0);
                counts.put(n, counts.get(n) + 1);
            }
            int idx = 0;
            List<Integer> sorted = new ArrayList<>(counts.keySet());
            Collections.sort(sorted);

            for (int i = 0; i < sorted.size(); i++) {
                int v = sorted.get(i);
                int cnt = counts.get(v);
                while (cnt > 0) {
                    nums[idx++] = v;
                    cnt--;
                }
            }

            for (int i = 0; i < nums.length; i++) {
                int v = nums[i];
                if (counts.getOrDefault(v, 0) == 0) continue;
                boolean allPresent = IntStream.range(v + 1, v + k).allMatch(x -> counts.getOrDefault(x, 0) > 0);
                if (allPresent) {
                    for (int j = v; j < v + k; j++) {
                        counts.put(j, counts.get(j) - 1);
                    }
                } else return false;
            }
            return true;
        }
    }

    static class Solution {
        public boolean isPossibleDivide(int[] nums, int k) {
            Arrays.sort(nums);
            Map<Integer, Integer> counts = new HashMap<>();
            for (int n : nums) {
                counts.putIfAbsent(n, 0);
                counts.put(n, counts.get(n) + 1);
            }
            for (int i = 0; i < nums.length; i++) {
                int v = nums[i];
                if (counts.getOrDefault(v, 0) == 0) continue;
                boolean allPresent = IntStream.range(v + 1, v + k).allMatch(x -> counts.getOrDefault(x, 0) > 0);
                if (allPresent) {
                    for (int j = v; j < v + k; j++) {
                        counts.put(j, counts.get(j) - 1);
                    }
                } else return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {

        System.out.println(new Solution().isPossibleDivide(new int[]{1,2,3,3,4,4,5,6}, 4));
        System.out.println(new Solution().isPossibleDivide(new int[]{3,2,1,2,3,4,3,4,5,9,10,11}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{3,3,2,2,1,1}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{1,2,3,4}, 3));

        System.out.println(new Solution().isPossibleDivide(new int[]{4,5,6,7,7,8,8,9,10,11}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{2,3,9,10,10,11,11,12,13,14}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{1, 2, 3, 4}, 3));
        System.out.println(new Solution().isPossibleDivide(new int[]{1, 2, 5, 6, 7}, 3));
    }

}
