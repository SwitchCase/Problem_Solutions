package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class CarPooling1094 {

    class Solution {
        public boolean carPooling(int[][] trips, int capacity) {
            Arrays.sort(trips, Comparator.comparingInt(v -> v[1]));
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(v -> v[2]));

            int c = 0;
            for (int i = 0; i < trips.length; i++) {
                while(!pq.isEmpty()) {
                    int[] trip = pq.peek();
                    if (trip[2] <= trips[i][1]) {
                        pq.poll();
                        c -= trip[0];
                    } else break;
                }
                if (c + trips[i][0] <= capacity) {
                    pq.add(trips[i]);
                    c += trips[i][0];
                } else return false;
            }
            return true;
        }
    }
}

