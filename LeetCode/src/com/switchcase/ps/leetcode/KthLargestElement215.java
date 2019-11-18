package com.switchcase.ps.leetcode;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Random;

/**
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 */
public class KthLargestElement215 {
    class SolutionPQ {
        public int findKthLargest(int[] nums, int k) {
            PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);

            for (int n : nums) {
                if (pq.size() >= k) {
                    if (pq.peek() < n) {
                        pq.poll();
                        pq.add(n);
                    }
                } else {
                    pq.add(n);
                }
            }
            return pq.poll();
        }
    }

    static class Solution {

        Random rand = new Random();
        public int findKthLargest(int[] nums, int k) {
            int lo = 0;
            int hi = nums.length;
            int lookingFor = nums.length - k ;
            while(lo < hi) {
                int pos = partition(nums, lo, hi);
                if (pos == lookingFor) {
                    return nums[pos];
                }
                if (pos < lookingFor) {
                    lo = pos + 1;
                } else {
                    hi = pos;
                }
            }
            return nums[lo];
        }

        //returns position of pivot
        //lo inclusive, hi not inclusive.
        //random makes a big diff here otherwise there are specific cases that can make the algo behave inefficiently.
        private int partition(int[] nums, int lo, int hi) {
            int pivPos = rand.nextInt(hi - lo) + lo;
            swap(nums, pivPos, hi - 1);
            int pivot = nums[hi - 1];
            int i = lo;
            for (int j = lo; j < hi; j++) {
                if (nums[j] < pivot) {
                    swap(nums, i, j);
                    i++;
                }
            }
            swap(nums, i, hi - 1);
            return i;
        }

        private void swap(int[] nums, int a, int b) {
            int tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {3,2,3,1,2,4,5,5,6};
        System.out.println(sol.findKthLargest(arr, 4));
    }
}
