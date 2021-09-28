package com.switchcase.ps.leetcode;

public class PermutationSequence60 {
    class Solution {
        public String getPermutation(int n, int k) {
            int[] fact = new int[n+1];
            int[] nums = new int[n+1];
            nums[0] = 1;
            nums[1] = 2;
            fact[0] = fact[1] = 1;
            for (int i = 2; i <= n; i++) {
                fact[i] = fact[i-1] * i;
                nums[i] = nums[i-1] + 1;
            }

            k--; //0index.
            String ans = "";
            for (int i = 0, s = n-1; i < n; i++, s--) {
                int wFact = fact[s];
                int quot = k / wFact;
                int v = getRem(nums, quot);
                ans += nums[v];
                nums[v] = 0;
                k = k % wFact;
            }
            return ans;
        }

        private int getRem(int[] nums, int idx) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0 && idx == 0) return i;
                if (nums[i] != 0) idx--;
            }
            return -1;
        }
    }
}
