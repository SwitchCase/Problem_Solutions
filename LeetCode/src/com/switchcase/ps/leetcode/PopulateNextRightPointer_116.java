package com.switchcase.ps.leetcode;

import java.util.ArrayDeque;
import java.util.Queue;

public class PopulateNextRightPointer_116 {
    static class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node() {}

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }

    class Solution {
        public Node connect(Node root) {
            if (root == null) {
                return null;
            }
           bfs(root);
            return root;
        }

        class State {
            Node root;
            Node parent;
            boolean rootIsLeft;

            public State(Node root, Node parent, boolean rootIsLeft) {
                this.root = root;
                this.parent = parent;
                this.rootIsLeft = rootIsLeft;
            }
        }

        private void bfs(Node root) {
            Queue<State> q = new ArrayDeque<>();
            q.add(new State(root,null, true));
            while(!q.isEmpty()) {
                State top = q.poll();
                addNext(top.root, top.parent, top.rootIsLeft);
                if (top.root.left != null) {
                    q.add(new State(top.root.left, top.root, true));
                }
                if (top.root.right != null) {
                    q.add(new State(top.root.right, top.root, false));
                }
            }
        }

        private void addNext(Node root, Node parent, boolean rootIsLeft) {
            if (parent != null) {
                if (rootIsLeft) {
                    if (parent.right != null) {
                        root.next = parent.right;
                    } else {
                        root.next = getNextForRightNode(parent);
                    }
                } else {
                    root.next = getNextForRightNode(parent);
                }
            }
        }

        private Node getNextForRightNode(Node parent) {
            if (parent == null) {
                return null;
            }
            Node nextWithChild = null;
            while (parent.next != null) {
                if (hasChild(parent.next)) {
                    nextWithChild = parent.next;
                    break;
                } else {
                    parent = parent.next;
                }
            }
            if (nextWithChild != null) {
                if (nextWithChild.left != null) {
                    return nextWithChild.left;
                } else {
                    return nextWithChild.right;
                }
            }
            return null;
        }

        private boolean hasChild(Node node) {
            return node.left != null || node.right != null;
        }
    }
}
