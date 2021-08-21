package com.switchcase.ps.leetcode;

import java.util.*;

public class PalindromPermutation2_267 {

    class Solution {
        public List<String> generatePalindromes(String s) {
            int[] counts = new int[256];
            Arrays.fill(counts, 0);
            Set<Character> uniq = new HashSet<>();
            for (int i = 0; i < s.length(); i++) {
                uniq.add(s.charAt(i));
                counts[s.charAt(i)]++;
            }

            List<String> ans = new ArrayList<>();

            if (s.length() % 2 == 0) {
                List<String> halves = getHalf(counts, uniq);
                for(String h : halves) {
                    String rev = new StringBuilder(h).reverse().toString();
                    ans.add(h + rev);
                }
            } else {
                for (char c : uniq) {
                    counts[c]--;
                    List<String> halves = getHalf(counts, uniq);
                    for(String h : halves) {
                        String rev = new StringBuilder(h).append(c).reverse().toString();
                        ans.add(h + rev);
                    }
                    counts[c]++;

                }
            }
            return ans;
        }

        private List<String> getHalf(int[] counts, Set<Character> uniq) {
            int reqLength = 0;
            for (Character c : uniq) {
                if (counts[c] % 2 != 0) {
                    return new ArrayList<>();
                }
                reqLength += (counts[c] / 2);
            }
            Set<String> all = new HashSet<>();
            generate(counts, uniq, reqLength, "", all);
            return new ArrayList<>(all);
        }

        private void generate(int[] counts, Set<Character> uniq, int len, String soFar, Set<String> all) {
            if (len == soFar.length()) {
                all.add(soFar);
                return;
            }
            for (Character c : uniq) {
                if (counts[c] / 2 > 0) {
                    String newSoFar = soFar;
                    newSoFar += c;
                    counts[c] -= 2;
                    generate(counts, uniq, len, newSoFar, all);
                    counts[c] += 2;
                }
            }
        }
    }
}
