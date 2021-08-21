package com.switchcase.ps.leetcode;

public class ValidPalindrome_125 {
    class Solution {
        private boolean isAlphaNumeric(char c) {
            return c>='a' && c<='z' || c>='0' && c <='9';
        }

        public boolean isPalindrome(String s) {
            s = s.toLowerCase();
            int i = 0, j = s.length()- 1;
            while (i < j) {
                if (!isAlphaNumeric(s.charAt(i))) {
                    i++;
                    continue;
                }
                if (!isAlphaNumeric(s.charAt(j))) {
                    j--;
                    continue;
                }
                if (s.charAt(i) == s.charAt(j)) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            }
            return true;
        }
    }
}
