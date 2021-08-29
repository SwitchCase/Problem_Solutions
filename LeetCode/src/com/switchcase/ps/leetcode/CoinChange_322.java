package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.Map;

public class CoinChange_322 {

     class Solution {

        private Map<Integer, Integer> dp = new HashMap<>();

        public int coinChange(int[] coins, int amount) {
            dp.clear();
            dp.put(0,0);
            int ans = recurse(coins, amount);
            if (ans >= 100000000) {
                return -1;
            }
            return ans;
        }

        private int recurse(int[] coins, int amount) {
            if (amount < 0) {
                return 100000000;
            }
            if (dp.containsKey(amount)) {
                return dp.get(amount);
            }

            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < coins.length; i++) {
                ans = Math.min(ans, 1 + recurse(coins, amount - coins[i]));
            }
            dp.put(amount, ans);
            return ans;
        }
    }
}
