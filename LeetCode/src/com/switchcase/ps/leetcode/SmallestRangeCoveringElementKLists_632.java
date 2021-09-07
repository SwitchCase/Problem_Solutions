package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 */
public class SmallestRangeCoveringElementKLists_632 {

    static class Solution {
        public int[] smallestRange(List<List<Integer>> nums) {
            int N = nums.stream().mapToInt(lst -> lst.size()).sum();
            int K = nums.size();
            int[][] array = new int[N][2];
            int idx = 0;
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt((int[] a) -> a[0]));
            for (int i = 0; i < K; i++) {
                pq.add(new int[] {nums.get(i).get(0), i});
            }
            int[] numsIdx = new int[K];
            Arrays.fill(numsIdx, 0);

            while (!pq.isEmpty()) {
                int[] smallest = pq.poll();
                array[idx++] = smallest; // smallest[0] -> number, smallest[1] -> index of list from where the number came.
                numsIdx[smallest[1]]++; //increment nums[x]
                if (numsIdx[smallest[1]] < nums.get(smallest[1]).size()) {
                    pq.add(new int[]{nums.get(smallest[1]).get(numsIdx[smallest[1]]), smallest[1]});
                }
            }

            int[] satisfied = new int[K];
            Arrays.fill(satisfied, 0);
            int start = 0, end = 0;
            int[] ans = new int[2];
            int best = Integer.MAX_VALUE;
            int satCount = 0;

            while (true) {
                while (end < N) {
                    int[] curr = array[end];
                    if (satisfied[curr[1]] == 0) {
                        satisfied[curr[1]]++;
                        satCount++;
                    } else {
                        satisfied[curr[1]]++;
                    }
                    end++;
                    if (satCount == K) {
                        int currB = array[end-1][0] - array[start][0] + 1;
                        if (currB < best) {
                            best = currB;
                            ans = new int[]{array[start][0], array[end-1][0]};
                        }
                        break;
                    }
                }
                while (start < N) {
                    int[] curr = array[start];
                    if (satisfied[curr[1]] == 1) {
                        satisfied[curr[1]]--;
                        satCount--;
                    } else {
                        satisfied[curr[1]]--;
                    }
                    start++;
                    if (satCount < K) {
                        break;
                    } else {
                        int currB = array[end-1][0] - array[start][0] + 1;
                        if (currB < best) {
                            best = currB;
                            ans = new int[]{array[start][0], array[end-1][0]};
                        }
                    }
                }
                if (end >= N) break;
            }
            return ans;
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
