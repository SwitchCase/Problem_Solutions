package com.switchcase.ps.leetcode

import spock.lang.Specification

class MaxPointsOnLine149Test extends Specification {

    def "test"() {
        given:
        MaxPointsOnLine149.Solution solution = new MaxPointsOnLine149.Solution();

        when:
        def result = solution.maxPoints(points as int[][])

        then:
        expectation == result

        where:
        expectation || points
        3           || [[1,1],[2,2],[3,3]]
        4           || [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
        1           || [[0,1]]
    }
}
