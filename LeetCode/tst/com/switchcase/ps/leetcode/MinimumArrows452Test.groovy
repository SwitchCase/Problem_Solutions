package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class MinimumArrows452Test extends Specification {

    @Unroll
    def "Test"() {
        given:
        MinimumArrows452.Solution solution = new MinimumArrows452.Solution()

        when:
        def result = solution.findMinArrowShots(input as int[][])

        then:
        expectation == result

        where:
        expectation || input
        4           || [[1,2],[3,4],[5,6],[7,8]]
        2           || [[1,2],[2,4],[3,6],[2,8]]
        2           || [[1,2],[2,3],[3,4],[4,5]]
        2           || [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]


    }
}
