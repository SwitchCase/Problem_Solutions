package com.switchcase.ps.leetcode;

import java.util.*;

public class ShortestSubarraySumK_862 {

    static class SolutionTLE {
        public int shortestSubarray(int[] A, int K) {
            List<int[]> sums = new ArrayList<>();
            sums.add(new int[]{0, 0});
            int sum = 0;
            for (int i = 0; i < A.length; i++) {
                sum += A[i];
                sums.add(new int[] {sum, i + 1});
            }
            sums.sort(Comparator.comparingInt(x -> x[0]));
            int best = Integer.MAX_VALUE;
            for (int i = sums.size() - 1; i >=0; i--) {
                if (sums.get(i)[0] - sums.get(0)[0] >= K) {
                    int j = 0;
                    while (sums.get(i)[0] - sums.get(j)[0] >= K) {
                        if (sums.get(i)[1] > sums.get(j)[1]) {
                            best = Math.min(best, sums.get(i)[1] - sums.get(j)[1]);
                        }
                        j++;
                    }
                } else break;
            }
            if (best < Integer.MAX_VALUE) return best;
            return -1;
        }
    }

    static class SolutionNotWork {
        public int shortestSubarray(int[] A, int K) {
            int start = 0, end = 0;
            int currSum = 0;
            int best = Integer.MAX_VALUE;

            while(A[start] <= 0) start++;
            end = start;
            int endPosMaxIdx = start;
            for (int i = A.length - 1; i >= start; i--) {
                if (A[i] > 0) {
                    endPosMaxIdx = i;
                    break;
                }
            }

            while(end <= endPosMaxIdx) {
                while (currSum < K && end <= endPosMaxIdx) {
                    currSum += A[end++];
                }
                while (start < end) {
                    if (currSum >= K) {
                        int ans = end - start;
                        best = Math.min(ans, best);
                        currSum -= A[start++];
                    }
                    else if (A[start] < 0) {
                        while (start < end && A[start] < 0) {
                            if (currSum >= K) {
                                int ans = end - start;
                                best = Math.min(ans, best);
                            }
                            currSum -= A[start++];
                        }
                    } else break;
                }
            }
            if (best < Integer.MAX_VALUE) {
                return best;
            }
            return -1;
        }
    }

    static class Solution {
        public int shortestSubarray(int[] A, int K) {
            int[] sums = new int[A.length + 1];
            int[] sumMK= new int[A.length + 1];
            sums[0] = 0;
            sumMK[0] = -K;
            for (int i = 0; i < A.length; i++) {
                sums[i + 1] = sums[i] + A[i];
                sumMK[i + 1] = sums[i + 1] - K;
            }
            int best = Integer.MAX_VALUE;
            Deque<Integer> deq = new ArrayDeque<>();
            for (int i = 0; i < sums.length; i++) {
                while (!deq.isEmpty() && sums[deq.peekFirst()] <= sumMK[i]) {
                    best = Math.min(best, i - deq.pollFirst());
                }
                while(!deq.isEmpty() && sums[deq.peekLast()] > sums[i]) {
                    deq.pollLast();
                }
                deq.offerLast(i);
            }
            if (best < Integer.MAX_VALUE) return best;
            return -1;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().shortestSubarray(new int[]{84,-37,32,40,95}, 167) == 3);
        System.out.println(new Solution().shortestSubarray(new int[]{2, -1, 2}, 3) == 3);
        System.out.println( new Solution().shortestSubarray(new int[]{44,-25,75,-50,-38,-42,-32,-6,-40,-47}, 19) == 1);
        System.out.println( new Solution().shortestSubarray(new int[]{1, -5, 10, -3, 6, -2, -1, 1}, 13) == 3);
        System.out.println( new Solution().shortestSubarray(new int[]{-5, 10, -3, 6, -2, -1}, 13) == 3);
        System.out.println(new Solution().shortestSubarray(new int[]{45,95,97,-34,-42}, 21) == 1);
        System.out.println(new Solution().shortestSubarray(new int[]{12, -3, -5, -1, 6, 3, 6, -9, -4, 9, 3,2 -5}, 15) == 3);
        System.out.println(new Solution().shortestSubarray(new int[]{1}, 1) == 1);
        System.out.println(new Solution().shortestSubarray(new int[]{1, 2}, 4) == -1);
        System.out.println(new Solution().shortestSubarray(new int[]{2, -1, 2, 7, 9, -5, 10, -10, 0, 2, 7, 8, 9}, 30) == 9);

    }

}
