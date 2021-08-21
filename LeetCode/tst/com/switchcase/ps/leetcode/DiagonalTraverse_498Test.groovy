package com.switchcase.ps.leetcode

import spock.lang.Specification

class DiagonalTraverse_498Test extends Specification {

    def test() {
        given:
        DiagonalTraverse_498.Solution solution = new DiagonalTraverse_498.Solution();

        when:
        def ans = solution.findDiagonalOrder(matrix as int[][])

        then:
        ans == exp

        where:
        exp                             || matrix
        [1,2,4,7,5,3,6,8,9]             || [[1,2,3],[4,5,6],[7,8,9]]
        [1,2,4,7,5,3,10,6,8,9,11,12]    || [[1,2,3,10],[4,5,6,11],[7,8,9,12]]
    }
}
