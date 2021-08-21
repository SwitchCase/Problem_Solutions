package com.switchcase.ps.leetcode;

import java.util.Stack;

/**
 * https://leetcode.com/problems/sum-of-subarray-minimums/
 */
public class SumOfSubarrayMins_907 {
    static class Solution {
        public int sumSubarrayMins(int[] A) {
            int sum = 0;
            int mod = 1000000007;
            int N = A.length;

            int[] ans = new int[N];
            Stack<Integer> stack = new Stack<>();

            for (int i = N - 1; i >= 0; i--) {
                while (!stack.isEmpty() && A[stack.peek()] >= A[i]) {
                    stack.pop();
                }
                if (!stack.isEmpty() && A[stack.peek()] < A[i]) {
                    int nextSmallest = stack.peek();
                    ans[i] = (ans[nextSmallest] + A[i] * (nextSmallest - i)) % mod;
                    sum += ans[i];
                    sum %= mod;
                    stack.push(i);
                } else {
                    //no element to the right is smallest than A[i]:
                    ans[i] = A[i] * (N - i) % mod;
                    sum += ans[i];
                    sum %= mod;
                    stack.push(i);
                }
            }
            return sum;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().sumSubarrayMins(new int[]{81, 55, 2}));
        System.out.println(new Solution().sumSubarrayMins(new int[]{3, 1, 2, 4}));
    }
}
