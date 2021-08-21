package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

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

        class QNode {
            TreeNode node;
            int level;
            QNode(TreeNode node, int level) {
                this.node = node;
                this.level = level;
            }
        }

        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> ans = new ArrayList<>();
            if (root == null) return ans;
            Queue<QNode> queue = new ArrayDeque<>();
            queue.add(new QNode(root, 0));
            QNode last = new QNode(root, 0);



            while(!queue.isEmpty()) {
                QNode qn = queue.poll();
                if (qn.level != last.level) {
                    ans.add(last.node.val);
                }
                last = qn;
                TreeNode node = qn.node;
                if (node.left != null) queue.add(new QNode(node.left, qn.level + 1));
                if (node.right != null) queue.add(new QNode(node.right, qn.level + 1));
            }
            ans.add(last.node.val);
            return ans;
        }
    }
}
