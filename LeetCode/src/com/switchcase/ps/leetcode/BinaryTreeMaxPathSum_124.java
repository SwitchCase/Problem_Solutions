package com.switchcase.ps.leetcode;

public class BinaryTreeMaxPathSum_124 {

    /**
     * Definition for a binary tree node.
     *
     */
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    class Solution {

        public int maxPathSum(TreeNode root) {
            int[] ans = compute(root);
            return Math.max(ans[0], ans[1]);
        }

        private int[] compute(TreeNode root) {
            int best = root.val, incl = root.val;
            int[] left = null;
            if (root.left != null) {
                left = compute(root.left);
                best = Math.max(best, left[0]);
                best = Math.max(best, left[1] + root.val);
                incl = Math.max(incl, left[1] + root.val);
            }
            int[] right = null;
            if (root.right != null) {
                right = compute(root.right);
                best = Math.max(best, right[0]);
                best = Math.max(best, right[1] + root.val);
                incl = Math.max(incl, right[1] + root.val);
            }
            best = Math.max(best, incl);
            if (root.right != null && root.left != null) {
                best = Math.max(best, left[1] + root.val + right[1]);
            }

            return new int[] {best, incl};
        }
    }
}
