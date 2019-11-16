package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.Map;

public class MaxPointsOnLine149 {

    class Solution {
        public int maxPoints(int[][] points) {
            int n = points.length;
            int ans = 0;

            for (int i = 0; i < n; i++) {
                Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();
                int same = 0;
                int tans = 0;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    int dx = points[i][0] - points[j][0];
                    int dy = points[i][1] - points[j][1];
                    if (dx == 0 && dy ==0) {
                        same++;
                        continue;
                    }
                    int gcd = gcd(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                    Pair<Integer, Integer> pair = new Pair<>(dx, dy);
                    if (map.containsKey(pair)) {
                        map.put(pair, map.get(pair) + 1);
                    } else {
                        map.put(pair, 1);
                    }
                    tans = Math.max(tans, map.get(pair));
                }
                ans = Math.max(ans, tans + same + 1);
            }
            return ans;
        }

        int gcd(int a, int b) {
            if (b == 0) return a;
            else return gcd(b, a%b);
        }

        class Pair<K, V> {
            K v1;
            V v2;

            Pair(K v1, V v2) {
                this.v1 = v1;
                this.v2 = v2;
            }

            @Override
            public boolean equals(Object o) {
                Pair other = (Pair) o;
                return v1.equals(other.v1) && v2.equals(other.v2);
            }

            @Override
            public int hashCode() {
                return v1.hashCode() + v2.hashCode();
            }
        }
    }
}
