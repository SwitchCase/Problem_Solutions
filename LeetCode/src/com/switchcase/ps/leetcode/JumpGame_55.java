package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * https://leetcode.com/problems/jump-game/
 */
public class JumpGame_55 {
    class Solution {
        public boolean canJump(int[] nums) {
            int reach = 0;
            for (int i = 0; i<nums.length; i++) {
                if (i > reach) return false;
                reach = Math.max(reach, i + nums[i]);
            }
            return true;
        }
    }

    //O(N^2) not acceptable.
    class SolutionDP_NonOptimal {
        Map<Integer, Boolean> dp = new HashMap<>();
        public boolean canJump(int[] nums) {
            int n = nums.length - 1;
            dp.put(n, true);
            return possible(nums, 0, n);
        }


        private boolean possible(int[] nums, int pos, int end) {
            if (dp.containsKey(pos)) return dp.get(pos);
            int n = nums[pos];
            boolean poss = false;
            if (n >= end || pos == end) {
                poss = true;
            } else {
                for (int i = 1; i <= n; i++) {
                    if (pos + i > end) break;
                    if (pos + i == end) {
                        poss = true;
                        break;
                    } else {
                        poss = possible(nums, pos + i, end);
                        if (poss) break;
                    }
                }
            }
            dp.put(pos, poss);
            return poss;
        }
    }
}
