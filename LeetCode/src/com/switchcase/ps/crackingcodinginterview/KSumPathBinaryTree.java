package com.switchcase.ps.crackingcodinginterview;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;
import java.util.stream.Collectors;

public class KSumPathBinaryTree {
    static int count = 0;
    static class Node {
        Node left;
        Node right;
        int val;

        Node(int v) {
            this.val = v;
        }
    }

    class Path {
        List<Node> nodes;
        int sum;
    }

    List<Path> allPaths(Node node, int sum) {
        List<Path> paths = new ArrayList<>();
        paths.addAll(allSelfPaths(node, node.left, sum));
        paths.addAll(allSelfPaths(node, node.right, sum));
        List<Node> self = new ArrayList<>();
        self.add(node);
        Path selfPath = new Path();
        selfPath.nodes = self;
        selfPath.sum = node.val;
        paths.add(selfPath);
        for (Path path : paths) {
            count++;
            if (path.sum == sum) {
                printPath(path);
            }
        }
        return paths;
    }

    private List<Path> allSelfPaths(Node node, Node child, int sum) {
        List<Path> paths = new ArrayList<>();
        if (child != null) {

            List<Path> childPaths = allPaths(child, sum);
            for(int i = 0; i < childPaths.size(); i++) {
                Path p = childPaths.get(i);
                Path newP = new Path();
                newP.sum = p.sum + node.val;
                newP.nodes = new ArrayList<>(p.nodes);
                newP.nodes.add(node);
                paths.add(newP);
            }
        }
        return paths;
    }

    private void printPath(Path path) {
        String toStr = path.nodes.stream().map(n -> Integer.toString(n.val)).collect(Collectors.joining(" "));
        System.out.println(toStr);
    }


    void printAllPaths(Node node, int sum) {
        allPaths(node, sum);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(3);
        root.left.left = new Node(2);
        root.left.right = new Node(1);
        root.left.right.left = new Node(1);
        root.right = new Node(-1);
        root.right.left = new Node(4);
        root.right.left.left = new Node(1);
        root.right.left.right = new Node(2);
        root.right.right = new Node(5);
        root.right.right.right = new Node(2);
        KSumPathBinaryTree ans = new KSumPathBinaryTree();
        ans.printAllPaths(root, 5);


        root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(1);
        root.left.right = new Node(2);

        root.right = new Node(-1);
        root.right.left = new Node(3);
        root.right.left.left = new Node(2);
        root.right.left.right = new Node(5);
        KSumPathBinaryTree ans2 = new KSumPathBinaryTree();
        ans2.printAllPaths(root, 3);
    }
}
