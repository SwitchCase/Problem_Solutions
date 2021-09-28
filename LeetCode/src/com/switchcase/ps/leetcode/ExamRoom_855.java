package com.switchcase.ps.leetcode;

import java.util.Comparator;
import java.util.TreeSet;

public class ExamRoom_855 {

    class ExamRoom {

        TreeSet<Interval> pq;
        TreeSet<Integer> taken;
        int N;

        class Interval {

            int start, end;
            int nextSeatDist; //dist from start for the next seat.

            //end is non inclusive.
            Interval(int start, int end) {
                this.start = start;
                this.end = end;
                if (start == -1) {
                    this.nextSeatDist = end;
                } else if (end == N) {
                    this.nextSeatDist = N - 1 - start;
                } else {
                    this.nextSeatDist = (end - start) / 2;
                }
            }

            // this is for TreeSet remove (Object o) method.
            public boolean equals(Interval i) {
                return this.start == i.start && this.end == i.end;
            }
        }

        public ExamRoom(int N) {
            this.pq = new TreeSet<>(Comparator.comparing((Interval i) -> i.nextSeatDist).reversed()
                    .thenComparing(i -> i.start));
            this.taken = new TreeSet<>();
            this.pq.add(new Interval(-1, N));
            this.N = N;
        }

        public int seat() {
            Interval top = pq.pollFirst();
            int seat;
            if (top.start == -1) {
                seat = 0;
                pq.add(new Interval(seat, top.end));
            } else if (top.end == N) {
                seat = N - 1;
                pq.add(new Interval(top.start, seat));
            } else {
                seat = (top.end + top.start) / 2;
                pq.add(new Interval(top.start, seat));
                pq.add(new Interval(seat, top.end));
            }
            taken.add(seat);
            return seat;
        }

        public void leave(int p) {
            int s = taken.lower(p) == null ? -1 : taken.lower(p);
            int e = taken.higher(p) == null ? N : taken.higher(p);
            pq.remove(new Interval(s, p));
            pq.remove(new Interval(p, e));
            pq.add(new Interval(s, e));
            taken.remove(p);
        }
    }
}
