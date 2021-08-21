package com.switchcase.ps.leetcode;

public class AddBinary_67 {
    static class Solution {
        public String addBinary(String a, String b) {
            String A = new StringBuilder(a.length() > b.length() ? a : b).reverse().toString(); // A is larger
            String B = new StringBuilder(a.length() > b.length() ? b : a).reverse().toString(); //B is smaller
            StringBuilder ans = new StringBuilder();
            boolean carry = false;
            int i = 0;
            for (; i < B.length(); i++) {
                if (A.charAt(i) == B.charAt(i) ) {
                    if (A.charAt(i) == '0') {
                        if (carry) {
                            carry = false;
                            ans.append('1');
                        } else ans.append('0');
                    } else {
                        if (carry) {
                            ans.append('1');
                        } else {
                            carry = true;
                            ans.append('0');
                        }
                    }
                } else {
                    if (carry) {
                        ans.append('0');
                    } else {
                        ans.append('1');
                    }
                }
            }
            for (; i < A.length(); i++) {
                if (carry) {
                    if (A.charAt(i) =='0') {
                        carry = false;
                        ans.append('1');
                    } else {
                        ans.append('0');
                    }
                } else {
                    ans.append(A.charAt(i));
                }
            }
            if (carry) ans.append('1');
            return ans.reverse().toString();
        }
    }
}
