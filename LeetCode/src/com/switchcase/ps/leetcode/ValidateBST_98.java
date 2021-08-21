package com.switchcase.ps.leetcode;

public class ValidateBST_98 {

    /**
     * Definition for a binary tree node.
     */

     public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode(int x) { val = x; }
      }

    class Solution {
        public boolean isValidBST(TreeNode root) {
            return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
        }

        private boolean validate(TreeNode root, long gtThan, long lsThan) {
            if (root == null) return true;
            if (root.val > gtThan &&  root.val < lsThan) {
                boolean ans = true;
                if (root.left != null) {
                    ans = ans && validate(root.left, gtThan, root.val);
                }
                if (root.right != null) {
                    ans = ans && validate(root.right, root.val, lsThan);
                }
                return ans;
            } else {
                return false;
            }
        }
    }
}
