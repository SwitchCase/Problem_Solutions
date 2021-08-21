package com.switchcase.ps.crackingcodinginterview;

import lombok.Data;

import java.util.*;

public class ExpressionCombos {

    static class Solution {

        @Data
        class Key {
            int idx;
            int target;

            public Key(int idx, int target) {
                this.idx = idx;
                this.target = target;
            }
        }

        public int count(String input, int val) {
            char[] arr = input.toCharArray();
            Map<Key, List<List<Integer>>> dp = new HashMap<>();
            List<List<Integer>> ans = count2(arr, 0, val, dp);
            for (List<Integer> a : ans) {
                System.out.println(a);
            }
            return ans.size();
        }

        private List<List<Integer>> count2(char[] arr, int idx, int currTarget, Map<Key, List<List<Integer>>> dp) {
            List<List<Integer>> results = new ArrayList<>();
            if (idx >= arr.length) {
                return results;
            }
            if (idx == arr.length - 1) {
                int v = arr[idx] - '0';
                if (currTarget + v == 0) {
                    results.add(Arrays.asList(-v));
                    return results;
                }
                if (currTarget - v == 0) {
                    results.add(Arrays.asList(v));
                    return results;
                }
                return results;
            }
            Key key = new Key(idx, currTarget);
            if (dp.containsKey(key)) {
                return dp.get(key);
            }
            StringBuilder str = new StringBuilder();
            int v = 0;
            for (int i = idx; i < arr.length; i++) {
                v = v * 10 + (arr[i] - '0');
                str.append(arr[i]);
                List<List<Integer>> ans = count2(arr, i + 1, currTarget - v, dp);
                for(List<Integer> a : ans) {
                    List<Integer> clone = new ArrayList<>();
                    clone.add(v);
                    clone.addAll(a);
                    results.add(clone);
                }
                ans = count2(arr, i + 1, v - currTarget, dp);
                for(List<Integer> a : ans) {
                    List<Integer> clone = new ArrayList<>();
                    clone.add(-v);
                    clone.addAll(a);
                    results.add(clone);
                }
            }
            dp.put(key, results);
            return results;
        }

        private int count(char[] arr, int target, int idx, int currTarget, Map<Key, Integer> dp, String curr) {
            if (idx >= arr.length) {
                if (currTarget == 0) {
                    System.out.println(curr);
                    return 1;
                }
                return 0;
            }
            Key key = new Key(idx, currTarget);
            if (dp.containsKey(key)) {
                return dp.get(key);
            }
            int v = 0;
            int ans = 0;
            StringBuilder str = new StringBuilder();
            for (int i = idx; i < arr.length; i++) {
                v = v * 10 + (arr[i] - '0');
                str.append(arr[i]);
                ans += count(arr, target, i + 1, currTarget - v, dp, curr + str + "+");
                if (currTarget != v) ans += count(arr, target, i + 1, v - currTarget, dp, curr + str + "-");
            }
            dp.put(key, ans);
            return ans;
        }
    }
}
