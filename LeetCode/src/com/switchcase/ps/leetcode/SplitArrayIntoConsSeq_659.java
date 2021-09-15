package com.switchcase.ps.leetcode;

import java.util.*;
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


    class Solution {
        public boolean isPossible(int[] nums) {
            //simulate.
            Map<Integer, Integer> counts = new HashMap<>();
            for (int num :nums) {
                counts.put(num, counts.getOrDefault(num, 0) + 1);
            }
            List<Integer> uniq = new ArrayList<>(counts.keySet());
            uniq.sort(Comparator.naturalOrder());

            List<List<Integer>> sequences = new ArrayList<>();
            for (int i = 0; i < uniq.size(); i++) {
                int first = uniq.get(i);
                if (counts.get(first) > 0) {
                    //first needs a new home.
                    for (int j = 0; j < sequences.size(); j++) {
                        if (sequences.get(j).get(sequences.get(j).size() - 1) == first - 1 && counts.get(first) > 0) {
                            sequences.get(j).add(first);
                            counts.put(first, counts.get(first) -1 );
                        }
                    }
                }
                while (counts.getOrDefault(first, 0) > 0
                        && counts.getOrDefault(first + 1, 0) > 0
                        && counts.getOrDefault(first + 2, 0) > 0) {
                    List<Integer> seq = new ArrayList<>();
                    seq.add(first);seq.add(first + 1); seq.add(first + 2);
                    sequences.add(seq);
                    counts.put(first, counts.get(first) - 1);
                    counts.put(first + 1, counts.get(first + 1) - 1);
                    counts.put(first + 2, counts.get(first + 2) - 1);
                }

                if (counts.get(first) > 0) {
                    return false;
                }
            }
            return true;
        }
    }
}
