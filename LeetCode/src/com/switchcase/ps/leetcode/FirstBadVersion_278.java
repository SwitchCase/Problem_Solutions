package com.switchcase.ps.leetcode;

import java.util.Arrays;

public class FirstBadVersion_278 {

    /* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

    static class Solution extends VersionControl {
        public Solution(int badVersion) {
            super(badVersion);
        }

        public int firstBadVersion(int n) {
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo)/2;
                if(isBadVersion(mid)) hi = mid;
                else lo = mid + 1;
            }
            return lo;
        }
    }

    static class VersionControl {
        private final int badVersion;
        private VersionControl(int badVersion) {
            this.badVersion = badVersion;
        }

        protected boolean isBadVersion(int in) {
            if (in >= badVersion) return true;
            else return false;
        }
    }

    public static void main(String[] args) {
        int[][] kases = new int[][]{ {10, 4}, {1000, 1}, {1000, 1000}, {1, 0}};
        for (int i = 0; i < kases.length; i++) {
            System.out.println("For Case: " + Arrays.toString(kases[i]) + " ans = " + new Solution(kases[i][1]).firstBadVersion(kases[i][0]));
        }
    }
}
