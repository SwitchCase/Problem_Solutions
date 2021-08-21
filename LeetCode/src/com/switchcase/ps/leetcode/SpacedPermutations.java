package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class SpacedPermutations {
    static class Solution {
        int calls = 0;
        List<int[]> solve(int n) {
            calls = 0;
            int L = 2*n;
            int[] start = new int[L];
            List<int[]> ans = new ArrayList<>();
            Arrays.fill(start, 0);
            for (int i = 0; i + n + 1 < L; i++) {
                start[i] = n;
                start[i + n + 1] = n;
                List<int[]> perms = permutate(start, L,n - 1);
                ans.addAll(perms);
                start[i] = 0;
                start[i + n + 1] = 0;
            }
            System.out.println("Total calls for " + n + " is " + calls);
            return ans;
        }

        private List<int[]> permutate(int[] start, int L, int v) {
            calls++;
            if (v == 0) {
                return Arrays.asList(start.clone());
            }
            List<int[]> ans = new ArrayList<>();
            for(int i = 0; i < L - v - 1; i++) {
                if (start[i] == 0 && start[i+v+1] == 0) {
                    start[i] = v;
                    start[i + v + 1] = v;
                    ans.addAll(permutate(start, L, v - 1));
                    start[i] = 0;
                    start[i+ v + 1] = 0;
                }
            }
            return ans;
        }
    }
}
