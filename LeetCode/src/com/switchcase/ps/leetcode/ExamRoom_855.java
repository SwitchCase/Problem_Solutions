package com.switchcase.ps.leetcode;

import java.util.PriorityQueue;

public class ExamRoom_855 {

    static class ExamRoom {

        PriorityQueue<Interval> pq;
        int N;

        class Interval {
            int s, e, dist;
            Interval(int s, int e) {
                this.s = s;
                this.e = e;
                if (s == -1) {
                    this.dist = e;
                } else if (e == N) {
                    this.dist = N - 1 - s;
                } else {
                    this.dist = (e - s)/2;
                }
            }
        }

        public ExamRoom(int N) {
            this.N = N;
            this.pq = new PriorityQueue<>((Interval a, Interval b) -> a.dist != b.dist ? b.dist - a.dist : Integer.compare(a.s, b.s));
            pq.add(new Interval(-1, N));
        }

        public int seat() {
            Interval interval = pq.poll();
            int seat;
            if (interval.s == -1) {
                seat = 0;
            } else if (interval.e == this.N) {
                seat = N - 1;
            } else {
                seat = (interval.e + interval.s) / 2;
            }
            pq.add(new Interval(interval.s, seat));
            pq.add(new Interval(seat, interval.e));

            return seat;
        }

        public void leave(int p) {
            Interval start = null;
            Interval end = null;
            for (Interval interval : pq) {
                if (interval.e == p) {
                    start = interval;
                }
                if (interval.s == p) {
                    end = interval;
                }
            }
            pq.remove(start);
            pq.remove(end);
            pq.add(new Interval(start.s, end.e));
        }
    }

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

}
