package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.Map;

public class MinSwapsToMakeSeqIncreasing_801 {
    class Solution {

        class Tuple {
            int pos;
            int A;
            Tuple(int pos, int A) {
                this.pos = pos;
                this.A = A;

            }

            @Override
            public int hashCode() {
                int hash = 7;
                hash = 1001 * pos;
                hash = 997 * hash + A * 97;
                return hash;
            }

            @Override
            public boolean equals(Object o) {
                if (!(o instanceof Tuple)) return false;
                Tuple to = (Tuple) o;
                return to.pos == pos && to.A == A;
            }
        }

        public int minSwap(int[] A, int[] B) {
            return recurse(A, B, 0, -1, -1, new HashMap<>());
        }

        private int recurse(int[] A, int[] B, int pos, int pA, int pB, Map<Tuple, Integer> dp) {
            if (pos >= A.length) return 0;
            Tuple key = new Tuple(pos, pA);
            if (dp.containsKey(key)) {
                return dp.get(key);
            }
            int ans = 1000000;
            if (A[pos] > pA && B[pos] > pB) {
                ans = Math.min(ans, recurse(A, B, pos + 1, A[pos], B[pos], dp));
            }
            if (A[pos] > pB && B[pos] > pA) {
                ans = Math.min(ans, 1 + recurse(A, B, pos + 1, B[pos], A[pos], dp));
            }
            dp.put(key, ans);
            return ans;
        }
    }
}
