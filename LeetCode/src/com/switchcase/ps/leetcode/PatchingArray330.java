package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class PatchingArray330 {
    private static class Solution {

        public int minPatches(int[] input, int n) {
            List<Integer> list = new ArrayList<>();
            list.add(0);
            list.addAll(Arrays.stream(input).boxed().collect(Collectors.toList()));
            if (input[input.length - 1] < n) {
                list.add(n);
            }

            long covered = 0;
            int patch=0;
            int idx = 1;

            while(idx < list.size() && covered < n) {
                while (covered + 1 < list.get(idx) && covered < n) {
                    patch++;
                    covered += covered + 1;
                }
                covered += list.get(idx);
                idx++;
            }
            return patch;
        }
    }
}

