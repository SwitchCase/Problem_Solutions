package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class NonOverlappingIntervals435Test extends Specification {

    @Unroll
    def "test"() {
        given:
        NonOverlappingIntervals435.Solution solution = new NonOverlappingIntervals435.Solution();

        when:
        def result = solution.eraseOverlapIntervals(input as int[][])

        then:
        expectation == result

        where:
        expectation || input
        7           || [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
        1           || [[1,2],[2,3],[3,4],[1,3]]
        2           || [[1,2],[1,2],[1,2]]
        0           || [[1,2],[2,3]]
        2           || [[1,2],[1,3],[1,4]]


    }
}
