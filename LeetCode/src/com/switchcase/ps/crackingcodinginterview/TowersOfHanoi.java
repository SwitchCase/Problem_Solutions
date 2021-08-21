package com.switchcase.ps.crackingcodinginterview;

import java.util.Stack;

public class TowersOfHanoi {

    private static class Tower {
        private final Stack<Integer> towerData;
        private final int idx;

        private Tower(int idx) {
            this.towerData = new Stack<>();
            this.idx = idx;
        }

        private Tower addToTop(int n) {
            if (!towerData.isEmpty() && towerData.peek() <= n) {
                throw new IllegalArgumentException("Cannot add " + n + " to tower: " + idx + " when peek is " + towerData.peek());
            }
            towerData.add(n);
            return this;
        }

        private Tower removeTop(int n) {
            if (towerData.isEmpty() || towerData.peek() != n) {
                throw new IllegalArgumentException("Cannot remove " + n + " to tower: " + idx + " when peek is " + towerData.peek());
            }
            towerData.pop();
            return this;
        }

        private Tower moveDisks(int n, Tower buffer, Tower destination) {
            if ( n > 0) {
                moveDisks(n - 1, destination, buffer);
                System.out.println("Move " + n + " from " + this.idx + " to " + destination.idx);
                this.removeTop(n);
                destination.addToTop(n);
                buffer.moveDisks(n - 1, this, destination);
            }
            return this;
        }

        public String toString() {
            return towerData.toString();
        }
    }

    public static void main(String[] args) {
        int n = 4;
        Tower src = new Tower(0);
        for (int i = n; i > 0; i--) src.addToTop(i);

        Tower buff = new Tower(1);
        Tower destination = new Tower(2);
        src.moveDisks(n, buff, destination);

        System.out.println("End State: ");
        System.out.println("Source: " + src.toString());
        System.out.println("Buff : " + buff.toString());
        System.out.println("Dest : " + destination.toString());
    }
}
