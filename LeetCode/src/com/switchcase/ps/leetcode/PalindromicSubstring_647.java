package com.switchcase.ps.leetcode;

public class PalindromicSubstring_647 {

    class Solution {
        public int countSubstrings(String s) {
            int ans = s.length();
            char[] array = s.toCharArray();

            for (int i = 0; i < array.length; i++) {
                //odd
                for (int j = i - 1, k = i + 1; j>=0 && k < s.length(); j--,k++) {
                    if (array[j] == array[k]) {
                        ans++;
                    } else {
                        break;
                    }
                }

                //even

                for (int j = i - 1, k = i; j >= 0 && k < s.length(); j--,k++) {
                    if (array[j] == array[k]) {
                        ans++;
                    } else {
                        break;
                    }
                }
            }
            return ans;
        }
    }
}
