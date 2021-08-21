package com.switchcase.ps.leetcode;

import java.util.Stack;

public class AsteroidCollision_735 {

    static class Solution {
        public int[] asteroidCollision(int[] asteroids) {
            if (asteroids.length <= 1) return asteroids;
            Stack<Integer> stack = new Stack<>();
            stack.push(asteroids[0]);
            for (int i = 1; i < asteroids.length; i++) {
                boolean add = true;
                while(!stack.isEmpty() && different(stack.peek(), asteroids[i])) {
                    if (Math.abs(stack.peek()) > Math.abs(asteroids[i])) {
                        add = false;
                        break;
                    }
                    if (Math.abs(stack.peek()) == Math.abs(asteroids[i])) {
                        stack.pop();
                        add = false;
                        break;
                    }
                    else {
                        stack.pop();
                        add = true;
                    }
                }
                if(add) stack.push(asteroids[i]);
            }
            int[] ans = new int[stack.size()];
            int idx = stack.size() - 1;
            while(!stack.isEmpty()) {
                ans[idx--] = stack.pop();
            }
            return ans;

        }

        private boolean different(Integer peek, int asteroid) {
            return peek > 0 && asteroid < 0;
        }
    }
}
