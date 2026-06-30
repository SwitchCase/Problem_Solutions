package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.Map;

public class PermutationInString_567 {

    class Solution {
        public boolean checkInclusion(String s2, String s1) {
            if (s2.length() > s1.length()) return false;
            int N = s2.length();
            Map<Character, Integer> s2Freq = new HashMap<>();
            for (char c : s2.toCharArray()) {
                s2Freq.putIfAbsent(c, 0);
                s2Freq.compute(c, (k,v) -> v + 1);
            }

            Map<Character, Integer> currFreq = new HashMap<>();

            for (int i = 0; i < N; i++) {
                char c = s1.charAt(i);
                currFreq.putIfAbsent(c, 0);
                currFreq.compute(c, (k,v) -> v + 1);
            }

            if (s2Freq.equals(currFreq)) {
                return true;
            }

            for (int i = 1, j = N; j < s1.length(); i++, j++) {
                char toRemove = s1.charAt(i-1);
                char toAdd = s1.charAt(j);
                currFreq.compute(toRemove, (k,v) -> v - 1);
                if (currFreq.get(toRemove) == 0) {
                    currFreq.remove(toRemove);
                }
                currFreq.putIfAbsent(toAdd, 0);
                currFreq.compute(toAdd, (k,v) -> v + 1);
                if (s2Freq.equals(currFreq)) {
                    return true;
                }
            }
            return false;
        }

    }
}
