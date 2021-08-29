package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

@Unroll
class TrappingRainWater42Test extends Specification {

    def "test"() {
        given:
        TrappingRainWater42.Solution solution = new TrappingRainWater42.Solution()

        when:
        def result = solution.trap(input as int[])

        then:
        expectation == result

        where:
        expectation || input
        1           || [4, 2, 3]
        6           || [0,1,0,2,1,0,1,3,2,1,2,1]
        9           || [4,2,0,3,2,5]
        0           || [0]
    }

}
