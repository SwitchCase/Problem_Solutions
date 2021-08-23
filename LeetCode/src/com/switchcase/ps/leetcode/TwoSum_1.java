package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class TwoSum_1 {

    public static void main(String... args) {
        System.out.println("Target: 12, Output: " + Arrays.toString(new Solution().twoSum(new int[] {6,3, -1, -5, 8, 17}, 12)));
    }

    static class Solution {
        public int[] twoSum(int[] nums, int target) {
             Map<Integer, Integer> map = new HashMap<>();
             for (int i = 0; i < nums.length; i++) {
                 map.put(nums[i], i);
             }
             for (int i = 0; i < nums.length; i++) {
                 int a = nums[i];
                 int reqdVal = target - a;
                 if (map.containsKey(reqdVal) && map.get(reqdVal) != i) {
                     return new int[] {i, map.get(reqdVal)};
                 }
             }
             return new int[] {};
        }
    }
}
