package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Random;

/**
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */
public class SearchRotatedArray_33 {
    static class Solution {
        public int search(int[] nums, int target) {
            if (nums.length == 0) return -1;
            int piv = findPivot(nums);
            int res = search(nums, target, 0, piv + 1);
            if (res == -1) {
                return search(nums, target, piv + 1, nums.length);
            }
            return res;
        }

        //end is non inclusive.
        int search(int[] nums, int target, int start, int end) {
            while(end > start) {
                int mid = start + (end - start)/ 2;
                if (nums[mid] == target) {
                    return mid;
                }
                else if (nums[mid] > target) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
            }
            return -1;
        }

        int findPivot(int[] nums) {
            int s = 0;
            int e = nums.length;
            while (e > s) {
                int mid = s + (e - s)/2;
                if (mid + 1 < nums.length && nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                else if (nums[mid] > nums[s]) {
                    s = mid;
                } else if (nums[mid] < nums[e - 1]){
                    e = mid;
                } else { //equals!
                    for (int i = s; i < e; i++) {
                        if (i + 1 < nums.length && nums[i] > nums[i + 1]) return i;
                    }
                    return 0;
                }
            }
            return s;
        }
    }

    public static void main(String[] args) {
        int[][] cases = {
                {2, 2, 2, 2,2,2,2,2, 3,2,2,2,2},
                {120, 199, 201, 232, 1,3, 11, 99, 102, 105},
                {1, 2},
                {1},
                {-1},
                {0},
                {2},
                {-3, 0, 4, 5, 7},
                {5, 1},
                {4,5,6,7,0,1,2},
                {4,5,6,7,0,1,2},
                {3, 1},
                {3,1,2}
        };
        Random rand = new Random();
        for (int i = 0; i < cases.length; i++){
            int[] kase = cases[i];
            int ans = rand.nextInt(kase.length);
            int target = kase[ans];
            System.out.println("Input: " + Arrays.toString(kase) + ", target = " + target + " ; output: " + new Solution().search(kase, target) +" expected: " + ans);
        }
    }
}
