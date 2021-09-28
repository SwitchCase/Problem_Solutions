package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.List;

public class GenerateParanthesis_22 {

    class Solution {
        public List<String> generateParenthesis(int n) {
            List<String> ans = new ArrayList<>();
            recurse(n, 0, 0, 0, "", ans);
            return ans;
        }

        private void recurse(int n, int open, int closed, int done, String sofar, List<String> out) {
            if (done == 2 * n) {
                out.add(sofar);
                return;
            }

            if (open < n) {
                recurse(n, open + 1, closed, done + 1, sofar + "(", out);
            }
            if (open > closed) {
                recurse(n, open, closed + 1, done + 1, sofar + ")", out);
            }
        }
    }
}
