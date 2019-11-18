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
                String tmp = findLongest(s, i);
                longest = longest.length() < tmp.length() ? tmp : longest;
            }
            return longest;
        }

        private String findLongest(String s, int pos) {
            String longest = "" + s.charAt(pos);
            int n = s.length();
            //odd length:
            int left = pos - 1;
            int right = pos + 1;
            String tmp = longestPalidrome(s, left, right);
            longest = longest.length() < tmp.length() ? tmp : longest;

            //leftwards even:
            left = pos -1;
            if (left >=0 && s.charAt(left) == s.charAt(pos)) {
                left--;
                right = pos + 1;
                tmp = longestPalidrome(s, left, right);
                longest = longest.length() < tmp.length() ? tmp : longest;
            }

            //rightwards even:
            right = pos + 1;
            if (right < n && s.charAt(right) == s.charAt(pos)) {
                right++;
                left = pos - 1;
                tmp = longestPalidrome(s, left, right);
                longest = longest.length() < tmp.length() ? tmp : longest;
            }
            return longest;
        }

        private String longestPalidrome(String s, int left, int right) {
            String longest = "";
            int n = s.length();
            while (left < right && left >=0 && right < n) {
                if (s.charAt(left) == s.charAt(right)) {
                    left--;
                    right++;
                } else break;
            }
            if (left+1 < n && left + 1 >=0 && right <= n)
                longest = s.substring(left+1, right);

            return longest;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestPalindrome("babadaba"));
    }
}
