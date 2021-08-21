package com.switchcase.ps.leetcode;

import java.util.*;

/**
 * https://leetcode.com/problems/daily-temperatures/
 */
public class DailyTemperatures_739 {
    static class Solution {
        public int[] dailyTemperatures(int[] T) {
            Stack<Integer> stack = new Stack<>();
            int N = T.length;
            int[] res = new int[N];
            Arrays.fill(res, 0);
            for (int i = N - 1; i>=0; i--) {
                while (!stack.isEmpty() && T[stack.peek()] <= T[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && T[stack.peek()] > T[i]) {
                    res[i] = stack.peek() - i;
                    stack.push(i);
                } else {
                    res[i] = 0;
                    stack.push(i);
                }
            }
            return res;
        }
    }
    static class SolutionSlow {
        public int[] dailyTemperatures(int[] orig) {
            int N = orig.length;
            int[] T = reverse(orig);
            Deque<int[]> deq = new ArrayDeque<>();
            int[] res = new int[N];
            Arrays.fill(res, N + 1);
            res[0] = 0;
            deq.offerLast(new int[] {T[0], 0});
            for (int i = 1; i < N; i++) {
                if (deq.peekFirst()[0] > T[i]) {
                    for (int[] v : deq) {
                        if (v[0] > T[i]) {
                            res[i] = Math.min(res[i], i - v[1]);
                        } else break;
                    }
                }
                while(!deq.isEmpty() && deq.peekLast()[0] < T[i]) deq.pollLast();
                deq.offerLast(new int[]{T[i], i});
            }

            res = reverse(res);
            for (int i = 0; i < res.length; i++) if (res[i] >= N) res[i] = 0;
            return res;
        }

        int[] reverse(int[] T) {
            int N = T.length;
            int[] reverseT = new int[N];
            for (int i = 0, j = N - 1; i < N; i++, j--) {
                reverseT[i] = T[j];
            }
            return reverseT;
        }
    }

    public static void main(String[] args) {
        run(new int[]{73, 74, 75, 71, 69, 72, 76, 73}, new int[]{1, 1, 4, 2, 1, 1, 0, 0});
    }

    private static void run(int[] ints, int[] exp) {
        Solution sol = new Solution();
        int[] ans = sol.dailyTemperatures(ints);
        System.out.println(" For input: " + Arrays.toString(ints) + " ans is " + Arrays.toString(ans) + " and it matches exp: " + Arrays.equals(exp, ans));
    }
}
