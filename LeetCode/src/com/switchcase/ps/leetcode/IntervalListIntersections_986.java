package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.List;

public class IntervalListIntersections_986 {

    class Solution {
        public int[][] intervalIntersection(int[][] A, int[][] B) {
            if (A.length == 0 || B.length == 0) return new int[][]{};
            int sizeA = A.length;
            int sizeB = B.length;
            List<int[]> ans = new ArrayList<>();

            int idxA = 0, idxB = 0;

            while(idxA < sizeA && idxB < sizeB) {
                int[] merged = merged(A[idxA], B[idxB]);
                if (merged != null) {
                    ans.add(merged);
                }
                if (A[idxA][1] < B[idxB][1]) idxA++;
                else idxB++;
            }
            int[][] array = new int[ans.size()][2];
            ans.toArray(array);
            return array;
        }

        int[] merged(int[] A, int[] B) {
            int min = Math.max(A[0], B[0]);
            int max = Math.min(A[1], B[1]);
            if (min <= max) {
                return new int[]{min, max};
            } else return null;
        }
    }

}
