package com.switchcase.ps.leetcode

import spock.lang.Specification

class BSTIterator_173Test extends Specification {

    def test() {
        given:
        BSTIterator_173.TreeNode root = new BSTIterator_173.TreeNode(7);
        root.left = new BSTIterator_173.TreeNode(3);
        root.right = new BSTIterator_173.TreeNode(15);
        root.right.left = new BSTIterator_173.TreeNode(9);
        root.right.right = new BSTIterator_173.TreeNode(20);

        when:
        BSTIterator_173.BSTIterator iterator = new BSTIterator_173.BSTIterator(root)

        then:
        iterator.next() == 3
        iterator.next() == 7
        iterator.hasNext()
        iterator.hasNext()
        iterator.next() == 9
        iterator.hasNext()
        iterator.hasNext()
        iterator.next() == 15
        iterator.hasNext()
        iterator.hasNext()
        iterator.next() == 20
        !iterator.hasNext()
    }
}
