package com.switchcase.ps.leetcode;

import java.math.BigInteger;
import java.util.Arrays;

/**
 * https://leetcode.com/problems/find-the-closest-palindrome/
 */
public class FindClosestPalindrome_564 {

    static class Solution {
        public String nearestPalindromic(String n) {
            if (n.length() == 1) {
                if (n.equals("0")) return "1";
                else return Long.toString(Long.parseLong(n) - 1);
            }
            String sameDigit = find(n);
            String op2 = all9s(n.length() - 1);
            String op3 = only1dot1(n.length() - 1);
            String op4 = all9s(n.length() + 1);
            String op5 = only1dot1(n.length() + 1);
            return best(n, new String[] {sameDigit, op2, op3, op4, op5});
        }

        private String all9s(int n) {
            char[] array = new char[n];
            Arrays.fill(array, '9');
            return new String(array);
        }

        private String only1dot1(int n) {
            char[] array = new char[n];
            Arrays.fill(array, '0');
            array[0] = array[n - 1] = '1';
            return new String(array);
        }

        private String best(String op, String[] cand) {
            String delta = "99999999999999999999";
            String best = "";
            for (String can : cand) {
                if (!can.equals(op)) {
                    String absDiff = absDiff(op, can);
                    int compare = greater(delta, absDiff);
                    if (compare > 0) {
                        best = can;
                        delta = absDiff;
                    } else if (compare == 0) {
                        if (greater(best, can) > 0) {
                            best = can;
                        }
                    }
                }
            }
            return best;
        }

        // -1 if s1 < s2; +1 s1 > s2 and 0 if s1 == s2
        private int greater(String s1, String s2) {
            int n = Math.max(s1.length(), s2.length());
            s1 = String.format("%1$" + n + "s", s1).replace(' ', '0');
            s2 = String.format("%1$" + n + "s", s2).replace(' ', '0');
            return s1.compareTo(s2);
        }

        private String absDiff(String s1, String s2) {
            BigInteger s1bi = new BigInteger(s1);
            BigInteger s2bi = new BigInteger(s2);
            return s1bi.subtract(s2bi).abs().toString();
        }


        private String find(String n) {
            long ll = Long.parseLong(n.substring(0, n.length() / 2));

            if ( n.length() % 2 == 0) {
                return best(n, new String[] {   toPalindrome(ll + 1, ""),
                                                toPalindrome(ll, ""),
                                                toPalindrome(ll - 1, "")});
            } else {
                String piv = "" + n.charAt((n.length() - 1) / 2);
                String op1 = toPalindrome(ll + 1, piv);
                String op2 = toPalindrome(ll - 1, piv);
                long pivLL = Long.parseLong(piv);
                String op3 = toPalindrome(ll, Long.toString((pivLL + 1) % 10));
                String op4 = toPalindrome(ll, Long.toString((pivLL + 9) % 10));
                String op5 = toPalindrome(ll, piv);
                return best(n, new String[] {op1, op2, op3, op4, op5});
            }
        }

        private String toPalindrome(Long ll, String piv) {
            StringBuffer buff = new StringBuffer(ll.toString());
            return buff.toString() + piv + buff.reverse().toString();
        }
    }

    public static void main(String[] args) {
        String[] cases = new String[] {
                "807045053224792883",
                "230",
                "0",
                "9",
                "2",
                "123",
                "100000000",
                "99999999999",
                "9999998",
                "9999999998",
                "1723091591"
        };
        for (String kase : cases) {
            System.out.println(kase + " -> " + new Solution().nearestPalindromic(kase));
        }
    }
}
