package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MinimumArrows452 {

    class Solution {

        public int findMinArrowShots(int[][] input) {
            List<Point> points = new ArrayList<>();
            for (int i = 0; i < input.length; i++) {
                int[] p = input[i];
                points.add(new Point(p[0], p[1]));
            }

            points.sort(Comparator.comparingInt((Point a) -> a.s).reversed());
            int start = 0;
            int next = 1;
            int arrows = 0;
            while( start < points.size()) {
                while (next < points.size() && (points.get(next).s <= points.get(start).s && points.get(next).e >= points.get(start).s)) {
                    next++;
                }
                start = next;
                arrows++;
            }
            return arrows;
        }

        class Point {
            int s;
            int e;

            Point(int s, int e) {
                this.s = s;
                this.e = e;
            }
        }
    }
}
