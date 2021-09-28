package com.switchcase.ps.leetcode

import spock.lang.Specification

class ShortestPathBinMatrix_1091Test extends Specification {

    def test() {
        given:
        ShortestPathBinMatrix_1091.Solution solution = new ShortestPathBinMatrix_1091.Solution();

        when:
        def ans = solution.shortestPathBinaryMatrix(grid as int[][])

        then:
        ans == exp

        where:
        exp     || grid
        10      || [[0,0, 0,0], [1, 1, 1, 0], [0, 0, 0, 0], [0, 1, 1, 1], [0, 0,0,0] ]
        7       || [[0,0,0], [1, 1, 0], [0, 0, 0], [0, 1, 1], [0,0,0] ]
        25      || [[0,1,1,1,1,1,1,1],
                    [0,1,1,0,0,0,0,0],
                    [0,1,0,1,1,1,1,0],
                    [0,1,0,1,1,1,1,0],
                    [0,1,1,0,0,1,1,0],
                    [0,1,1,1,1,0,1,0],
                    [0,0,0,0,0,1,1,0],
                    [1,1,1,1,1,1,1,0]]

    }

}
