package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 */
public class LongestPalindromicSubstring_5 {
    //brute force O(N^3) will not work.
    static class Solution {
        public String longestPalindrome(String s) {
            String longest = "";
            for (int i = 0; i < s.length(); i++) {
                for (int j = 1; j <= s.length(); j++) {
                    String check = s.substring(i, i + j);
                    if (isPalindrome(check)) {
                        if (longest.length() < check.length()) {
                            longest = check;
                        }
                    }
                }
            }
            return longest;
        }
        boolean isPalindrome(String s) {
            int left = 0, right = s.length() - 1;
            while (left < right) {
                if (s.charAt(left) == s.charAt(right)) {
                    left++;
                    right--;
                } else return false;
            }
            return true;
        }
    }
}
