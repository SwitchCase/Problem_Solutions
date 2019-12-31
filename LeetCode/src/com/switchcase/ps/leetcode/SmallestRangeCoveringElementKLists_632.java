package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 */
public class SmallestRangeCoveringElementKLists_632 {

    static class Solution {
        public int[] smallestRange(List<List<Integer>> nums) {
            int K = nums.size();
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt((int[] a) -> a[0]));
            int maxNum = nums.stream().flatMap(l -> l.stream()).mapToInt(x -> x).max().getAsInt();
            int minNum = nums.stream().flatMap(l -> l.stream()).mapToInt(x -> x).min().getAsInt();
            int max = Integer.MIN_VALUE;
            for (int i = 0; i < nums.size(); i++) {
                if (nums.get(i).size() > 0) {
                    pq.add(new int[]{nums.get(i).get(0), i});
                    max = Math.max(max, nums.get(i).get(0));
                } else {
                    return new int[]{minNum, maxNum};
                }
            }

            int[] doneP = new int[K];
            Arrays.fill(doneP, 0);

            int range = Integer.MAX_VALUE;
            int bl = -1, br = -1;
            //merge K lists:
            while(true) {
                int[] record = pq.poll();
                if (max - record[0] < range) {
                    range = max - record[0];
                    bl = record[0];
                    br = max;
                }
                int idx = record[1];
                if (doneP[idx] + 1 < nums.get(idx).size()) {
                    int val = nums.get(idx).get(doneP[idx] + 1);
                    pq.add(new int[]{val, idx});
                    doneP[idx]++;
                    if (max < val) {
                        max = val;
                    }
                } else {
                    break;
                }
            }
            return new int[] {bl, br};
        }
    }

    static class MySolution {
        public int[] smallestRange(List<List<Integer>> nums) {
            int K = nums.size();
            int totalN = nums.stream().mapToInt(l -> l.size()).sum();
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt((int[] a) -> a[0]));

            int[][] sorted = new int[totalN][2];
            int done = 0;
            int[] doneP = new int[K];
            Arrays.fill(doneP, 0);

            //merge K lists:
            while(done < totalN) {
                if (pq.isEmpty()) {
                    addFromAll(pq, K, nums, doneP);
                } else {
                    int[] record = pq.poll();
                    sorted[done++] = record;
                    int listIdx = record[1];
                    if (doneP[listIdx] < nums.get(listIdx).size()) {
                        pq.add(new int[]{nums.get(listIdx).get(doneP[listIdx]), listIdx});
                        doneP[listIdx]++;
                    } else {
                        addFromAll(pq, K, nums, doneP);
                    }
                }
            }
            //we have sorted array; now we get range.
            int left = 0, right = 0;
            int count = 0;
            int[] counts = new int[K];
            int best = Integer.MAX_VALUE, br=0, bl=0;
            Arrays.fill(counts, 0);
            while(right < totalN) {
                int[] rightR = sorted[right];
                if (counts[rightR[1]] < 1) {
                    count++;
                }
                counts[rightR[1]]++;

                while(left < totalN && count == K) {
                    int[] leftR = sorted[left];
                    if (best > rightR[0] - leftR[0] + 1) {
                        best = rightR[0] - leftR[0] + 1;
                        br = rightR[0];
                        bl = leftR[0];
                    }

                    if (counts[leftR[1]] - 1 < 1) {
                        count--;
                    }
                    counts[leftR[1]]--;
                    left++;
                }
                right++;
            }
            return new int[]{bl,br};

        }

        private void addFromAll(PriorityQueue<int[]> pq, int K, List<List<Integer>> nums, int[] doneP) {
            for (int i = 0; i < K; i++) {
                if (doneP[i] < nums.get(i).size()) {
                    pq.add(new int[]{nums.get(i).get(doneP[i]), i});
                    doneP[i]++;
                }
            }
        }
    }

    public static void main(String[] args) {
        List<List<Integer>> lists = new ArrayList<>();
        lists.add(Arrays.asList(4,10,15,24,26));
        lists.add(Arrays.asList(0,9,12,20));
        lists.add(Arrays.asList(5,18,22,30));

        System.out.println(Arrays.toString(new Solution().smallestRange(lists)));

    }
}
