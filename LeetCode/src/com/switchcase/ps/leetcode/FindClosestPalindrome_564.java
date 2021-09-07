package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/find-the-closest-palindrome/
 */
public class FindClosestPalindrome_564 {

    class Solution {
        public String nearestPalindromic(String n) {
            long input = Long.parseLong(n);
            String ans = "";
            long ansLong = Long.MAX_VALUE;
            long bestDiff = Long.MAX_VALUE;

            if (input <= 10) {
                if (input == 0) return "1";
                return Long.toString(input - 1);
            }

            String firstPart = n.substring(0, (n.length()+1)/2);
            long asLong = Long.parseLong(firstPart);
            for (int i = -1; i <= 1; i++) {
                long val = asLong + i;
                long pVal = oddLength(val);
                long diff = Math.abs(pVal - input);
                if (diff < bestDiff && pVal != input) {
                    ansLong = pVal;
                    ans = Long.toString(pVal);
                    bestDiff = Math.abs(pVal - input);
                }
                pVal = evenLength(val);
                diff = Math.abs(pVal - input);
                if (diff < bestDiff && pVal != input) {
                    ansLong = pVal;
                    ans = Long.toString(pVal);
                    bestDiff = Math.abs(pVal - input);
                }
            }

            for (long i = input - 10; i<=input + 10; i++) {
                if (isPalindrome(i)) {
                    if (Math.abs(i-input) < bestDiff && i != input) {
                        bestDiff = Math.abs(i-input);
                        ans = Long.toString(i);
                        ansLong = i;
                    } else if (Math.abs(i-input) == bestDiff && i < ansLong) {
                        ansLong = i;
                        bestDiff = Math.abs(i-input);
                        ans = Long.toString(i);
                    }
                }
            }

            return ans;
        }

        private boolean isPalindrome(long val) {
            if (val < 10) return true;
            String str = Long.toString(val);
            for (int i = str.length()/2 - 1, k = 1 + (str.length() % 2) ; i>=0; i--, k+=2) {
                if (str.charAt(i) != str.charAt(i+k)) {
                    return false;
                }
            }
            return true;
        }

        private long oddLength(long val) {
            String str = Long.toString(val);
            String ans = str;
            for (int i = str.length() - 2; i >= 0; i--) {
                ans += str.charAt(i);
            }
            return Long.parseLong(ans);
        }

        private long evenLength(long val) {
            String str = Long.toString(val);
            String ans = str;
            for (int i = str.length() - 1; i >= 0; i--) {
                ans += str.charAt(i);
            }
            return Long.parseLong(ans);
        }
    }
}
