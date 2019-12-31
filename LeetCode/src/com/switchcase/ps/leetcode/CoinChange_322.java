package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.Map;

public class CoinChange_322 {

    static class Solution {
        Map<Integer, Integer> dp = new HashMap<>();
        public int coinChange(int[] coins, int amount) {
            if (amount == 0) return 0;
            recurse(coins, amount);
            int ans = dp.getOrDefault(amount, -1);
            if (ans == 10000000) {
                return -1;
            }
            return ans;
        }

        private int recurse(int[] coins, int amount) {
            if (dp.containsKey(amount)) return dp.get(amount);
            int ans = 10000000;
            for (int i = 0; i < coins.length; i++) {
                int newA = amount - coins[i];
                if (newA > 0 ) {
                    ans = Math.min(ans, 1 + recurse(coins, newA));
                } else if (newA == 0) {
                    ans = Math.min(ans, 1);
                }
            }
            dp.put(amount, ans);
            return ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().coinChange(new int[] {1, 2, 5}, 11));
    }
}
