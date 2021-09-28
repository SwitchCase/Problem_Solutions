package com.switchcase.ps.leetcode;

public class BestTimeToBuySellStock3_123 {

    static class Solution {
        public int maxProfit(int[] prices) {
            int[] sProfit = new int[prices.length + 1];
            int[] eProfit = new int[prices.length + 1];

            int smallest = prices[0];
            int best = 0;
            sProfit[0] = best;
            for (int i = 1; i < prices.length; i++) {
                if (best < prices[i] - smallest) {
                    best = prices[i] - smallest;
                }
                sProfit[i] = best;
                if (smallest > prices[i]) {
                    smallest = prices[i];
                }
            }

            int largest = prices[prices.length - 1];
            best = 0;
            eProfit[prices.length - 1] = best;
            for (int i = prices.length - 2; i>=0; i--) {
                if (best < largest - prices[i]) {
                    best = largest - prices[i];
                }
                eProfit[i] = best;
                if (largest < prices[i]) {
                    largest = prices[i];
                }
            }
            int ans = 0;
            for (int i = 0; i < prices.length; i++) {
                ans = Math.max(ans, sProfit[i] + eProfit[i+1]);
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().maxProfit(new int[] {7,6,4,3,1}));
        System.out.println(new Solution().maxProfit(new int[] {3,3,5,0,0,3,1,4}));
        System.out.println(new Solution().maxProfit(new int[] {1,2,3,4,5}));
        System.out.println(new Solution().maxProfit(new int[] {3,7,0,5,2,12,6,4,9}));
    }
}
