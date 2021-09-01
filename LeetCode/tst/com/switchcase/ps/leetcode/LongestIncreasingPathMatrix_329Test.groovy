package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class LongestIncreasingPathMatrix_329Test extends Specification {

    @Unroll
    def "test"() {
        given:
        LongestIncreasingPathMatrix_329.Solution solution = new LongestIncreasingPathMatrix_329.Solution();

        when:
        def result = solution.longestIncreasingPath(matrix as int[][])

        then:
        exp == result

        where:
        exp         || matrix
        4           || [[9,9,4],[6,6,8],[2,1,1]]
        4           || [[3,4,5],[3,2,6],[2,2,1]]
        1           || [[1]]
    }
}
