package com.switchcase.ps.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class BinaryTreeRightSideView_199 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int x) {
            val = x;
        }
    }

    class Solution {
        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> ans = new ArrayList<>();

            if (root == null) return ans;

            LinkedList<TreeNode> level0 = new LinkedList<>();
            LinkedList<TreeNode> level1 = new LinkedList<>();
            level1.add(root);

            while(true) {
                if (level0.isEmpty()) {
                    if (level1.isEmpty()) {
                        break;
                    }
                    ans.add(level1.getLast().val);
                    level0 = level1;
                    level1 = new LinkedList<>();
                }
                TreeNode top = level0.pollFirst();
                if (top.left != null) {
                    level1.addLast(top.left);
                }
                if (top.right != null) {
                    level1.addLast(top.right);
                }
            }
            return ans;
        }
    }
}
