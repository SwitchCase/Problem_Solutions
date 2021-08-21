package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.List;

public class IntegerToEnglishWords_273 {
    static class Solution {
        private static final String[] BASE = new String[]{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        private static final String[] TENS = new String[]{ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        private static final String[] HUNDREDS = new String[] {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


        public String numberToWords(int num) {
            if (num == 0) return "Zero";
            StringBuilder sb = new StringBuilder();
            String[] words = new String[]{"", "Thousand", "Million", "Billion"};
            List<String> joiner = new ArrayList<>();
            for (int i = 3, start = 1_000_000_000; i >= 0; i--, start /= 1000) {
                int v = num/start;
                if (v > 0) {
                    joiner.add(toEnglish(v));
                    joiner.add(words[i]);
                }
                num%=start;
            }
            return String.join(" ", joiner).trim();

        }

        String toEnglish(int v) {
            StringBuilder sb = new StringBuilder();
            int h = v/100;
            int tb = v % 100;
            if (h == 0) {
                return base10(tb);
            }
            String ans = String.join(" ", base(h), "Hundred", base10(tb));
            return ans.trim();
        }

        String base10(int v) {
            int a = v / 10;
            if (a == 1) {
                return TENS[v%10];
            } else {
                String part1 = HUNDREDS[a];
                String part2 = base(v % 10);
                String ans = String.join(" ", part1, part2);
                return ans.trim();
            }
        }

        String base(int a) {
            return BASE[a];
        }
    }
}
