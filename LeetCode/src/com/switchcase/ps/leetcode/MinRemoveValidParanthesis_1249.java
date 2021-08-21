package com.switchcase.ps.leetcode;

public class MinRemoveValidParanthesis_1249 {

    class Solution {
        public String minRemoveToMakeValid(String s) {
            // remove all extra ')' chars
            String forward = remove(s, '(', ')');
            // remove all extra '(' but for it to reuse the previous function we need to run it in revers
            String reversed = remove(new StringBuilder(forward).reverse().toString(), ')', '(');
            return new StringBuilder(reversed).reverse().toString();
        }

        // removes any extra close characters.
        private String remove(String s, char open, char close) {
            int openCount = 0, closeCount = 0;
            StringBuilder sb = new StringBuilder();
            char[] array = s.toCharArray();
            for (int i = 0; i < array.length; i++) {
                if (array[i] == open) {
                    openCount++;
                }
                else if (array[i] == close) {
                    if (openCount > closeCount) {
                        closeCount++;
                    } else continue;
                }
                sb.append(array[i]);
            }
            return sb.toString();
        }
    }
}
