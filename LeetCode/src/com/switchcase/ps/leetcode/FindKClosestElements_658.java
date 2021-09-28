package com.switchcase.ps.leetcode;

import java.util.LinkedList;
import java.util.List;

public class FindKClosestElements_658 {
    class Solution {
        public List<Integer> findClosestElements(int[] arr, int k, int x) {
            int idxClosest = search(arr, x);
            int pIdx = idxClosest;
            int nIdx = idxClosest - 1;

            LinkedList<Integer> ans = new LinkedList<>();
            for (int i = 0; i < k; i++) {
                int pdiff = Integer.MAX_VALUE;
                int ndiff = Integer.MAX_VALUE;
                if (pIdx < arr.length) {
                    pdiff = Math.abs(x - arr[pIdx]);
                }
                if (nIdx >= 0) {
                    ndiff = Math.abs(x - arr[nIdx]);
                }
                if (pdiff < ndiff) {
                    ans.addLast(arr[pIdx]);
                    pIdx++;
                } else {
                    ans.addFirst(arr[nIdx]);
                    nIdx--;
                }
            }
            return ans;
        }

        //will find target or return idx of first num > target.
        private int search(int[] arr, int target) {
            int lo = 0, hi = arr.length;
            while (lo < hi) {
                int mid = (hi + lo) / 2;
                if (arr[mid] < target) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            return lo;
        }
    }
}
