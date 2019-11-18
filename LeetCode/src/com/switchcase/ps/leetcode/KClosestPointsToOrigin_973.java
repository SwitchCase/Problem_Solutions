package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * https://leetcode.com/problems/k-closest-points-to-origin/
 */
public class KClosestPointsToOrigin_973 {
    static class Solution {
        Random random = new Random();
        public int[][] kClosest(int[][] P, int K) {
            Point[] points = new Point[P.length];
            for (int i = 0; i < P.length; i++) {
                int x = P[i][0];
                int y = P[i][1];
                points[i] = (new Point(x, y, 1L*x*x + 1L*y*y));
            }
            int Kpos = KthLargest(points, K);
            int[][] result = new int[K][2];
            for (int i = 0; i < K; i++) {
                result[i][0] = points[i].x;
                result[i][1] = points[i].y;
            }
            return result;
        }

        private int KthLargest(Point[] points, int k) {
            int lo = 0, hi = points.length;
            while(lo < hi) {
                int pivPos = partition(points, lo, hi);
                if (pivPos == k) {
                    return pivPos;
                }
                else if (pivPos > k) {
                    hi = pivPos;
                } else {
                    lo = pivPos + 1;
                }
            }
            return lo;
        }

        private int partition(Point[] points, int lo, int hi) {
            int pivPos = random.nextInt(hi - lo) + lo;
            long pivot = points[pivPos].sqDist;
            swap(points, pivPos, hi - 1);
            int i = lo;
            for (int j = lo; j < hi; j++) {
                if (points[j].sqDist < pivot) {
                    swap(points, i, j);
                    i++;
                }
            }
            swap(points, i, hi - 1);
            return i;
        }

        private void swap(Point[] nums, int a, int b) {
            Point tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }

        class Point {
            int x, y;
            long sqDist;
            Point(int x, int y, long dist) {
                this.x = x;
                this.y = y;
                this.sqDist = dist;
            }
        }
    }
}
