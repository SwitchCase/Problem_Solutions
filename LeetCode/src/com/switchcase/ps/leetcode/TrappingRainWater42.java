package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

/**
 * https://leetcode.com/problems/trapping-rain-water/
 */
public class TrappingRainWater42 {
    static class Solution {
        public int trap(int[] height) {
            int minV = 0, minIdx = 0;
            int ans = 0;
            for (int i = 0; i < height.length; i++) {
                int currH = height[i];
                if (minV > 0 && currH >= minV) {
                    ans += calculate(height, minIdx, i);
                    minV = currH;
                    minIdx = i;
                } else if (minV == 0) {
                    minV = currH;
                    minIdx = i;
                }
            }
            if (minIdx < height.length - 1) {
                int[] arr = new int[height.length - minIdx];
                for (int i = height.length - 1, j = 0; i >= minIdx; i--, j++) {
                    arr[j] = height[i];
                }
                ans += trap(arr);
            }

            return ans;
        }

        int calculate(int[] h, int sidx, int eidx) {
            if (eidx < h.length) {
                int mn = Math.min(h[sidx], h[eidx]);
                int area = (eidx - sidx - 1) * mn;
                for (int i = sidx + 1; i < eidx; i++) {
                    area -= h[i];
                }
                return area;
            }
            return 0;

        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().trap(new int[] {4,2,3}));
    }
}
