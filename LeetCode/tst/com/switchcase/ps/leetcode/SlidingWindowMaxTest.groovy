package com.switchcase.ps.leetcode

import spock.lang.Specification

class SlidingWindowMaxTest extends Specification {

    def "test"() {
        given:
        SlidingWindowMax.Solution solution = new SlidingWindowMax.Solution()

        when:
        def result = solution.maxSlidingWindow(a as int[], k)

        then:
        exp == result

        where:
        k   |  a                                || exp
        3   | [10,9,8,7,6,5,4,3,2,1]            || [10,9,8,7,6,5,4,3]
        3   | [1, 3, -1, -3, 5, 3,6, 7]         || [3,3,5,5,6,7]
    }
}
