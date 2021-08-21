package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class BestTimeToBuySellStock3_123 {

    static class Solution {
        public int maxProfit(int[] prices) {

            if (prices.length == 0) return 0;
            int[] sProfit = new int[prices.length];
            int[] eProfit = new int[prices.length];

            int ans = 0;
            int mx = prices[0];
            int b = 0;
            sProfit[0] = 0;
            for (int i = 1; i < prices.length; i++) {
                b = Math.max(b, prices[i] - mx);
                sProfit[i] = b;
                ans = Math.max(ans, b);
                mx = Math.min(mx, prices[i]);
            }
            mx = prices[prices.length - 1];
            b = 0;
            eProfit[prices.length-1] = 0;
            for (int i = prices.length - 2; i >=0; i--) {
                b = Math.max(b, mx - prices[i]);
                eProfit[i] = b;
                ans = Math.max(ans, b);
                mx = Math.max(mx, prices[i]);
            }

            for (int i = 1; i < prices.length - 2; i++) {
                ans = Math.max(ans, sProfit[i] + eProfit[i + 1]);
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
