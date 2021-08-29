package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/trapping-rain-water/
 */
public class TrappingRainWater42 {
    static class Solution {
        public int trap(int[] height) {
            if (height.length <= 1) {
                return 0;
            }
            int anchor = -1;
            int anchorIdx = -1;
            int ans = 0;

            for(int i = 0; i < height.length; i++) {
                if (height[i] > 0 && anchor == -1) {
                    anchor = height[i];
                    anchorIdx = i;
                } else if (height[i] > 0 && anchor != -1) {
                    if (height[i] >= anchor) {
                        ans += trapCalculate(height, anchorIdx, i);
                        anchor = height[i];
                        anchorIdx = i;
                    }
                }
            }

            int rem = height.length - anchorIdx;
            if (rem == 1) {
                return ans;
            }
            int[] nH = new int[rem];
            for (int i = 0, j = height.length - 1; i < rem; i++, j--) {
                nH[i] = height[j];
            }
            ans += trap(nH);

            return ans;
        }

        private int trapCalculate(int[] height, int sIdx, int eIdx) {
            int ans = 0;
            for (int i = sIdx + 1; i < eIdx; i++) {
                ans += height[i];
            }
            return Math.min(height[sIdx], height[eIdx]) * (eIdx - sIdx - 1) - ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(new Solution().trap(new int[] {4,2,3}));
    }
}
