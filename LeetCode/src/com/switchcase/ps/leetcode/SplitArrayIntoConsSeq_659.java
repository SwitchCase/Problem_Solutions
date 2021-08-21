package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.IntStream;

public class SplitArrayIntoConsSeq_659 {
    static class SolutionFails {
        public boolean isPossible(int[] nums) {
            int count = 0;
            Map<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < nums.length; i++) {
                counts.putIfAbsent(nums[i], 0);
                counts.put(nums[i], counts.get(nums[i]) + 1);
            }
            int largest = nums[nums.length - 1];
            List<int[]> seq = new ArrayList<>();
            int rem = nums.length;

            while(rem > 0) {
                int[] check = new int[]{largest - 2, largest - 1, largest};
                boolean allPresent = IntStream.of(check).map(x -> counts.getOrDefault(x, 0)).allMatch(v -> v > 0);
                if (allPresent) {
                    seq.add(new int[] {largest - 2, largest});
                    for (int v : check) {
                        counts.put(v, counts.get(v) - 1);
                    }
                    rem -=3;
                    for (int l = largest; l >= nums[0]; l--) {
                        if (counts.getOrDefault(l, 0) > 0) {
                            largest = l;
                            break;
                        }
                    }
                } else break;
            }
            if (rem == 0) {
              return true;
            } else {
                while (rem > 0) {
                    //find longest seq from larg:
                    int l = largest;
                    int s = largest;
                    for (int i = largest - 1; i >= nums[0]; i--) {
                        if (counts.getOrDefault(i, 0) > 0) {
                            s = i;
                        } else break;
                    }
                    boolean found = false;
                    for (int i = 0; i < seq.size(); i++) {
                        if (seq.get(i)[0] - 1 == largest) {
                            seq.get(i)[0] = s;
                            found = true;
                            rem -= (l - s + 1);
                            break;
                        }
                    }
                    if (!found) return false;
                }
            }
            return true;
        }
    }


    static class Solution {
        public boolean isPossible(int[] nums) {
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
                    if (counts.getOrDefault(v + 1, 0) > 0 && counts.getOrDefault(v + 2, 0) > 0) {
                        ends.putIfAbsent(v + 2, 0);
                        ends.put(v + 2, ends.get(v + 2) + 1);
                        counts.put(v, counts.get(v) - 1);
                        counts.put(v + 1, counts.get(v + 1) - 1);
                        counts.put(v + 2, counts.get(v + 2) - 1);
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().isPossible(new int[]{4,5,6,7,7,8,8,9,10,11}));
        System.out.println(new Solution().isPossible(new int[]{2,3,9,10,10,11,11,12,13,14}));
        System.out.println(new Solution().isPossible(new int[]{1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9}));
        System.out.println(new Solution().isPossible(new int[]{1, 2, 3, 4}));
        System.out.println(new Solution().isPossible(new int[]{1, 2, 5, 6, 7}));
    }
}
