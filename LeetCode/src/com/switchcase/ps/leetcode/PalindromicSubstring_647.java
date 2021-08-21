package com.switchcase.ps.leetcode;

public class PalindromicSubstring_647 {

    static class Solution {
        public int countSubstrings(String s) {

            char[] array = s.toCharArray();

            int ans = 0;
            for (int i = 0; i < s.length(); i++) {
                ans +=1;
                int j = 1;
                //odd
                while (i + j < s.length() && i - j >= 0) {
                    if (array[i+j] == array[i - j]) ans++;
                    else break;
                    j++;
                }
                j = 1;
                //even:
                if (i+j < s.length() && array[i+j] == array[i]) {
                    int k = 0;
                    while(i-k >=0 && i+j+k <s.length()) {
                        if(array[i-k] == array[i+j+k]) ans++;
                        else break;
                        k++;
                    }
                }
            }
            return ans;
        }
    }
}
