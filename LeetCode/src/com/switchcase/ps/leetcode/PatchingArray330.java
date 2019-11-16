package com.switchcase.ps.leetcode;

public class PatchingArray330 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        //int[] input = {1, 2, 31, 33};
        //int n = 2147483647;
        //int n = 1023;
        int[] input = {1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94};
        int n = 20;

        //int[] input = {1, 2, 2, 2, 2};
        //int n = 16;
        System.out.println("Ans is" + solution.minPatches(input, n));
    }

    private static class Solution {

        public int minPatches(int[] input, int n) {
            int idx = 0, ans = 0;
            if (input.length > 0 && input[0] == 1) {
                idx = 1;
            } else ans++;
            long s = 1L;
            long t = (idx < input.length)? input[idx] : n;
            boolean completed = false;
            boolean last = t == n;

            while(!completed && s < n) {
                if (s < t) {
                    if (s+1 == t) {
                        if (last) {
                            ans++;
                            completed = true;
                        }
                        s+=t;
                        idx++;
                        t = (idx < input.length)? Math.min(input[idx], n) : n;
                        if (t == n) last = true;
                        continue;
                    }
                    if (last) {
                        long diff = t - s;
                        if (s > diff) {
                            ans++;
                            completed = true;
                            continue;
                        }
                    }
                    long p2 = s+1;
                    do  {
                        s += p2;
                        ans++;
                        p2 = s + 1;
                    } while (s + p2 <= t);
                } else {
                    if (last) {
                        completed = true;
                    }
                    s+=t;
                    idx++;
                    t = (idx < input.length)? Math.min(input[idx], n) : n;
                    if (t == n) last = true;
                }
            }
            return ans;
        }
    }
}

