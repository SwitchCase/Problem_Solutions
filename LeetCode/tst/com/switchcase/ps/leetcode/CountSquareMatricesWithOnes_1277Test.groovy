package com.switchcase.ps.leetcode

import spock.lang.Specification

class CountSquareMatricesWithOnes_1277Test extends Specification {

    def "test"() {
        given:
        CountSquareMatricesWithOnes_1277.Solution solution = new CountSquareMatricesWithOnes_1277.Solution()

        when:
        def result = solution.countSquares(matrix as int[][])

        then:
        result == exp

        where:
        exp     || matrix
        15      || [[0,1,1,1],[1,1,1,1],[0,1,1,1]]
        7       || [[1,0,1],[1,1,0],[1,1,0]]
    }

}
