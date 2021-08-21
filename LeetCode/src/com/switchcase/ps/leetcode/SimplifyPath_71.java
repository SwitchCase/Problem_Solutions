package com.switchcase.ps.leetcode;

import java.util.Stack;

public class SimplifyPath_71 {
    static class Solution {
        public String simplifyPath(String path) {
            Stack<String> curr = new Stack<>();
            String[] tokens = path.split("/");
            for (int i = 0; i < tokens.length; i++) {
                if (tokens[i].isEmpty() || tokens[i].equals(".")) continue;
                if (tokens[i].equals("..")) {
                    if (!curr.isEmpty()) curr.pop();
                } else {
                    curr.push(tokens[i]);
                }
            }
            String[] arr = new String[curr.size()];
            int idx = arr.length - 1;
            while(!curr.isEmpty()) {
                arr[idx--] = curr.pop();
            }
            return "/" + String.join("/", arr);
        }
    }
}
