package com.switchcase.ps.leetcode;

import java.util.Arrays;

/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/
 */
public class LargestRectangleInHistogram_84 {
    static class Solution {
        public int largestRectangleArea(int[] heights) {
            if (heights.length == 0) return 0;
            if (heights.length == 1) return heights[0];
            int N = heights.length;
            int[] right = new int[N];
            int[] left = new int[N];

            right[N-1] = N;
            //calc right:
            for (int i = N-2; i >=0; i--) {
                int p = i + 1;
                while(p < N && heights[p] >= heights[i]) {
                    p = right[p];
                }
                right[i] = p;
            }

            // calc left:
            left[0] = -1;
            for (int i = 1; i < N; i++) {
                int p = i - 1;
                while (p >= 0 && heights[p] >= heights[i]) {
                    p = left[p];
                }
                left[i] = p;
            }

            //System.out.println(" Right: " + Arrays.toString(right) + " left : " + Arrays.toString(left));
            int ans = 0;

            for (int i = 0; i < N; i++) {
                ans = Math.max(ans, heights[i] * (right[i] - left[i] - 1));
            }
            return ans;
        }
    }

    public static void main(String[]  args) {
        System.out.println(new Solution().largestRectangleArea(new int[] {6, 5, 6, 2, 3, 2, 1, 1}));
        System.out.println(new Solution().largestRectangleArea(new int[] {2,1,5,6,2,3}));
    }
}
