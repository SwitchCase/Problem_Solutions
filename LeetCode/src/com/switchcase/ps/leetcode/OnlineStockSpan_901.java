package com.switchcase.ps.leetcode;

import java.util.*;

public class OnlineStockSpan_901 {

    static class StockSpanner {

        private final Deque<int[]> deque;
        private int days;

        public StockSpanner() {
            this.deque = new ArrayDeque<>();
            this.deque.offerFirst(new int[]{Integer.MAX_VALUE, 0});
            this.days = 0;
        }

        public int next(int price) {
            int ans = 1;
            days++;
            while(!deque.isEmpty() && deque.peekLast()[0] < price) {
                deque.pollLast();
            }
            if (!deque.isEmpty() && deque.peekLast()[0] >= price) {
                if (deque.peekLast()[0] > price) {
                    ans = days - deque.peekLast()[1];
                } else {
                    for (Iterator<int[]> it = deque.descendingIterator(); it.hasNext(); ) {
                        int[] v = it.next();
                        if (v[0] == price) continue;
                        else {
                            ans = days - v[1];
                            break;
                        }
                    }
                }
            }
            deque.offerLast(new int[]{price, days});
            return ans;
        }
    }

    public static void main(String[] args) {
        StockSpanner sol = new StockSpanner();
        int[] inp = new int[] {1, 79, 34, 21, 34, 16, 59, 63, 72, 5};
        List<Integer> ans = new ArrayList<>();
        for (int v : inp) {
            ans.add(sol.next(v));
        }
        System.out.println(ans);
    }


}
