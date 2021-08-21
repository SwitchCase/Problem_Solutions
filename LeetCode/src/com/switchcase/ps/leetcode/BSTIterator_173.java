package com.switchcase.ps.leetcode;

import java.util.Stack;


public class BSTIterator_173 {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int x) {
            val = x;
        }
    }

    static class BSTIteratorLazy {

        private final Stack<TreeNode> stack;
        private final TreeNode root;
        private boolean initialized;

        public BSTIteratorLazy(TreeNode root) {
            this.root = root;
            stack = new Stack<>();
            this.initialized = false;
        }

        private TreeNode doNext() {
            if(stack.isEmpty()) return null;
            TreeNode result = stack.pop();
            if (result.right != null) leftChildren(stack, result.right);
            return result;
        }

        private void leftChildren(Stack<TreeNode> stack, TreeNode node) {
            if (node == null) return;
            stack.push(node);
            while(node.left != null) {
                stack.push(node.left);
                node = node.left;
            }
        }

        /**
         * @return the next smallest number
         */
        public int next() {
            return doNext().val;
        }

        /**
         * @return whether we have a next smallest number
         */
        public boolean hasNext() {
            if(!initialized) {
                leftChildren(stack, root);
                initialized = true;
            }
            return !stack.isEmpty();
        }
    }

    static class BSTIterator {

        private final Stack<TreeNode> stack;

        public BSTIterator(TreeNode root) {
            stack = new Stack<>();
            leftChildren(stack, root);
        }

        private TreeNode doNext() {
            if(stack.isEmpty()) return null;
            TreeNode result = stack.pop();
            if (result.right != null) leftChildren(stack, result.right);
            return result;
        }

        private void leftChildren(Stack<TreeNode> stack, TreeNode node) {
            if (node == null) return;
            stack.push(node);
            while(node.left != null) {
                stack.push(node.left);
                node = node.left;
            }
        }

        /**
         * @return the next smallest number
         */
        public int next() {
            return doNext().val;
        }

        /**
         * @return whether we have a next smallest number
         */
        public boolean hasNext() {
            return !stack.isEmpty();
        }
    }
}
