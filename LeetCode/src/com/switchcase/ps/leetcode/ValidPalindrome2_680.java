package com.switchcase.ps.leetcode;

public class ValidPalindrome2_680 {
    static class Solution {
        public boolean validPalindrome(String s) {
            int i = 0, j = s.length() -1;
            while (i < j) {
                if (s.charAt(i) != s.charAt(j)) {
                    return check(s, i, j - 1) || check(s, i+1, j);
                } else {
                    i++;
                    j--;
                }
            }
            return true;
        }

        private boolean check(String s, int i, int j) {
            while (i < j) {
                if (s.charAt(i) != s.charAt(j)) return false;
                i++;
                j--;
            }
            return true;
        }
    }
    static class SolutionCrap {
        public boolean validPalindrome(String s) {
            if (s == null || s.length() == 0) return true;
            return check(s) || doubleCheck(s);
        }

        private boolean doubleCheck(String s) {
            if (s.length() % 2 == 0) {
                //even string- test for odd palindrome:
                int[] p = new int[] {s.length()/2 - 1, s.length()/2};
                int fcount = 0;
                for (int c : p) {
                    int i = c - 1;
                    int j = c + 1;
                    int count = 0;
                    while (i >= 0 && j < s.length()) {
                        if (count == 0 && s.charAt(i) != s.charAt(j)) {
                            if (j + 1 < s.length() && s.charAt(i) == s.charAt(j + 1)) {
                                count++;
                                j++;
                            } else if (i - 1 >= 0 && s.charAt(i-1) == s.charAt(j)) {
                                count++;
                                i--;
                            } else {
                                fcount++;
                                break;
                            }
                        } else if (count != 0 && s.charAt(i) != s.charAt(j)) {
                            fcount++;
                            break;
                        }
                        i--;
                        j++;
                    }
                }
                if (fcount <= 1) return true;
                else return false;
            } else {
                //odd string- test for even palindrome:
                int[] p = new int[] {s.length()/2 - 1, s.length()/2};
                int fcount = 0;
                for (int c : p) {
                    int i = c;
                    int j = c + 1;
                    int count = 0;
                    while (i >= 0 && j < s.length()) {
                        if (count == 0 && s.charAt(i) != s.charAt(j)) {
                            if (j + 1 < s.length() && s.charAt(i) == s.charAt(j + 1)) {
                                count++;
                                j++;
                            } else if (i - 1 >= 0 && s.charAt(i-1) == s.charAt(j)) {
                                count++;
                                i--;
                            } else {
                                fcount++;
                                break;
                            }
                        } else if (count != 0 && s.charAt(i) != s.charAt(j)){
                            fcount++;
                            break;
                        }
                        i--;
                        j++;
                    }
                }
                if (fcount <= 1) return true;
                else return false;
            }
        }

        private boolean check(String s) {
            int i = s.length()/2 - 1;
            int j = i + 1 + (s.length() % 2);
            while (i >= 0 && j< s.length()) {
                if (s.charAt(i) != s.charAt(j)) return false;
                i--;
                j++;
            }
            return true;
        }
    }
}
