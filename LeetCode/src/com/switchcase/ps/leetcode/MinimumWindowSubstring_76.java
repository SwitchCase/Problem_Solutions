package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * https://leetcode.com/problems/minimum-window-substring/
 */
public class MinimumWindowSubstring_76 {
    static class Solution {
        public String minWindow(String s, String t) {
           Map<Character, Integer> tCounts = new HashMap<>();
           for (char c: t.toCharArray()) {
               tCounts.putIfAbsent(c, 0);
               tCounts.put(c, tCounts.get(c) + 1);
           }
           Map<Character, Integer> running = new HashMap<>();
           int start = 0, end = 0;
           int shortest = Integer.MAX_VALUE;
           String ans = "";

           while (start <= end) {
               while (end < s.length() && !satisfied(running, tCounts)) {
                   running.putIfAbsent(s.charAt(end), 0);
                   running.put(s.charAt(end), running.get(s.charAt(end)) + 1);
                   end++;
               }
               while (start < s.length() && satisfied(running, tCounts)) {
                   int length = end - start;
                   if (shortest > length) {
                       shortest = length;
                       ans = s.substring(start, end);
                   }
                   char sChar = s.charAt(start);
                   running.put(sChar, running.get(sChar) - 1);
                   start ++;
               }
               if (end >= s.length()) {
                   break;
               }

           }
           return ans;
        }

        private boolean satisfied(Map<Character, Integer> running, Map<Character, Integer> tCounts) {
            for (Map.Entry<Character, Integer> entry : tCounts.entrySet()) {
                char key = entry.getKey();
                if (running.getOrDefault(key, 0) < entry.getValue()) {
                    return false;
                }
            }
            return true;
        }
    }

    static class SolutionSub {
        public String minWindow(String s, String t) {
            int[] counts = new int[256];
            int[] reqs = new int[256];
            Arrays.fill(counts, 0);
            Arrays.fill(reqs, 0);
            for (int i = 0; i < t.length(); i++) {
                reqs[t.charAt(i)]++;
            }
            int start = 0, end = 0;
            int count = 0;
            int best = 100000, bs = -1, be = -1;
            while (end < s.length()) {
                //update counts and see if all requirements are met.
                char eChar = s.charAt(end);
                if (reqs[eChar] > 0 && reqs[eChar] > counts[eChar]) {
                    count++;
                }
                counts[eChar]++;


                //try to shorten substring.
                while (start <= end && count == t.length()) {
                    char sChar = s.charAt(start);
                    if (best > (end - start + 1)) {
                        best = end - start + 1;
                        bs = start;
                        be = end;
                    }
                    counts[sChar]--;
                    if (reqs[sChar] > 0 && reqs[sChar] > counts[sChar]) {
                        count--;
                    }
                    start++;
                }
                end++;
            }
            if (bs != -1) {
                return s.substring(bs, be + 1);
            }
            return "";
        }
    }


    public static void main(String[] args) {
        String[][] kases = new String[][]{
                {"ADOBECODEBANC", "ABC"},
                {"ABABABABASABASASBABSSSSSCBA", "ABC"}
        };
        for (int i = 0; i < kases.length; i++) {
            System.out.println("For Case: " + Arrays.toString(kases[i]) + " ans = " + new Solution().minWindow(kases[i][0], kases[i][1]));
        }
    }

}
