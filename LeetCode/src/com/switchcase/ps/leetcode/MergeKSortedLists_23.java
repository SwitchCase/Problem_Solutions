package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class MergeKSortedLists_23 {

    /**
     * Definition for singly-linked list.
     */
     public class ListNode {
          int val;
          ListNode next;
          ListNode(int x) { val = x; }
      }

    class Solution {
        public ListNode mergeKLists(ListNode[] lists) {
            ListNode root = null;
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
            for (int i = 0; i < lists.length; i++) {
                if (lists[i] != null) {
                    pq.add(new int[]{lists[i].val, i});
                }
            }
            ListNode tail = null;
            while (!pq.isEmpty()) {
                int[] val = pq.poll();
                ListNode node = lists[val[1]];
                if (node == null) continue;
                if (root == null) {
                    root = new ListNode(node.val);
                    tail = root;
                } else {
                    tail.next = new ListNode(node.val);
                    tail = tail.next;
                }
                if (node.next != null) {
                    pq.add(new int[]{node.next.val, val[1]});
                    lists[val[1]] = node.next;
                }
            }
            return root;
        }
    }
}
