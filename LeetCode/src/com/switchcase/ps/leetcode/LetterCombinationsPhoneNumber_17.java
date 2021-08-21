package com.switchcase.ps.leetcode;

import java.util.*;

public class LetterCombinationsPhoneNumber_17 {

    class Solution {
        Map<Character, String> mapping;

        Solution() {
            this.mapping = new HashMap<>();
            mapping.put('2',"abc");
            mapping.put('3', "def");
            mapping.put('4', "ghi");
            mapping.put('5', "jkl");
            mapping.put('6', "mno");
            mapping.put('7', "pqrs");
            mapping.put('8', "tuv");
            mapping.put('9', "wxyz");


        }
        public List<String> letterCombinations(String digits) {
            List<String> out = new ArrayList<>();
            if (digits.isEmpty()) return out;
            recurse(digits, 0 , "", out);
            return out;
        }

        private void recurse(String digits, int idx, String soFar, List<String> out) {
            if (idx >= digits.length()) {
                out.add(soFar);
                return;
            }
            Character c = digits.charAt(idx);
            String letters = mapping.get(c);
            for (Character character : letters.toCharArray()) {
                recurse(digits, idx + 1, soFar + character, out);
            }
        }
    }
}
