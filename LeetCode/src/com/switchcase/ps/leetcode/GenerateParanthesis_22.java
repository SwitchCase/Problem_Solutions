package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.List;

public class GenerateParanthesis_22 {

    class Solution {
        public List<String> generateParenthesis(int n) {
            List<String> out = new ArrayList<>();
            recurse("", n, 0, 0, out);
            return out;
        }

        private void recurse(String soFar, int n, int open, int close, List<String> out) {
            if (open == close && open == n) {
                out.add(soFar);
                return;
            }
            if (open < n) {
                recurse(soFar + "(", n, open + 1, close, out);
            }
            if (open > close) {
                recurse(soFar + ")", n, open, close + 1, out);
            }
        }
    }
}
