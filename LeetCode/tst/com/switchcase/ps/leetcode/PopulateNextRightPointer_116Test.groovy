package com.switchcase.ps.leetcode

import spock.lang.Specification

class PopulateNextRightPointer_116Test extends Specification {

    def test1() {
        given:
        PopulateNextRightPointer_116.Solution solution = new PopulateNextRightPointer_116.Solution()
        PopulateNextRightPointer_116.Node root = build([1,2,3,4,5,null,6,7,null,null,null,null, null, null,8], 0);

        when:
        def result = solution.connect(root)

        then:
        result.left.left.left.next.val == 8

    }

    PopulateNextRightPointer_116.Node build(List<Integer> integers, int pos) {
        if (integers.get(pos) == null) {
            return null;
        }

        PopulateNextRightPointer_116.Node root = new PopulateNextRightPointer_116.Node(integers.get(pos));
        if (2*pos + 1 < integers.size()) {
            root.left = build(integers, 2*pos + 1);
        }

        if (2*pos + 2 < integers.size()) {
            root.right = build(integers, 2*pos + 2);
        }
        return root;
    }
}
