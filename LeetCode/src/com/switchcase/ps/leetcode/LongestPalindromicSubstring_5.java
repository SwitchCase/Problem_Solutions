package com.switchcase.ps.leetcode;

/**
 * https://leetcode.com/problems/longest-palindromic-substring/
 */
public class LongestPalindromicSubstring_5 {
    static class Solution {
        public String longestPalindrome(String s) {
            String ans = "";
            int n = s.length();
            for (int i = 0; i < n; i++) {
                //s[i] is center:
                String oddPalindrome = getOddPalindrome(s, i);
                String evenPalindrome = getEvenPalindrome(s, i);
                if (oddPalindrome.length() > evenPalindrome.length() && oddPalindrome.length() > ans.length()) {
                    ans = oddPalindrome;
                } else if (evenPalindrome.length() > oddPalindrome.length() && evenPalindrome.length() > ans.length()) {
                    ans = evenPalindrome;
                }
            }
            return ans;
        }

        private String getEvenPalindrome(String s, int i) {
            int j = i;
            int k = i + 1;
            int n = s.length();
            while (j >= 0 && k < n && s.charAt(j) == s.charAt(k)) {
                j--;
                k++;
            }
            return s.substring(j+1, k);
        }

        private String getOddPalindrome(String s, int idx) {
            int j = idx - 1;
            int k = idx + 1;
            int n = s.length();
            while (j >= 0 && k < n && s.charAt(j) == s.charAt(k)) {
                j--;
                k++;
            }
            return s.substring(j+1, k);
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.longestPalindrome("babadaba"));
    }
}
