package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class CarPooling1094 {

    class Solution {
        public boolean carPooling(int[][] trips, int capacity) {
            trips = Arrays.stream(trips)
                    .sorted(Comparator.comparingInt(array -> array[1]))
                    .collect(Collectors.toList())
                    .toArray(new int[0][0]);

            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt((int[] array) -> array[2]));
            int filled = 0;
            for (int i = 0; i < trips.length; i++) {
                int p = trips[i][0];
                int frm = trips[i][1];
                while (!pq.isEmpty() && pq.peek()[2] <= frm) {
                    int[] cleared = pq.poll();
                    filled -= cleared[0];
                }
                if (filled + p <= capacity) {
                    filled += p;
                    pq.add(trips[i]);
                } else {
                    return false;
                }
            }
            return true;
        }
    }
}

