package com.switchcase.ps.leetcode;

import java.util.*;
import java.util.stream.Collectors;

public class MaxPointsOnLine149 {

    class Solution {
        public int maxPoints(int[][] points) {
            if (points.length == 1) {
                return 1;
            }

            Map<List<Integer>, Set<List<Integer>>> lineMap = new HashMap<>();

            for (int i = 0; i < points.length; i++) {
                for (int j = i + 1; j < points.length; j++) {
                    int mn = points[i][1] - points[j][1];
                    int md = points[i][0] - points[j][0];
                    int mgcd = gcd(Math.abs(mn), Math.abs(md));
                    mn /= mgcd;
                    md /= mgcd;
                    if (mn < 0 && md < 0) {
                        mn = -mn;
                        md = -md;
                    }
                    int cn = (points[i][1] * md) - (mn * points[i][0]);
                    int[] line = new int[]{mn, md, cn};
                    lineMap.putIfAbsent(asList(line), new HashSet<>());
                    lineMap.get(asList(line)).add(asList(points[i]));
                    lineMap.get(asList(line)).add(asList(points[j]));
                }
            }
            int max = 0;
            for (Map.Entry<List<Integer>, Set<List<Integer>>> entry : lineMap.entrySet()) {
                max = Math.max(max, entry.getValue().size());
            }
            return max;
        }

        List<Integer> asList(int[] array) {
            return Arrays.stream(array).boxed().collect(Collectors.toList());
        }

        int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        }
    }
}
