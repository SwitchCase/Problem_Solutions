package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class MaxProductSubarray_152Test extends Specification {

    @Unroll
    def "test"() {
        given:
        MaxProductSubarray_152.Solution solution = new MaxProductSubarray_152.Solution()

        when:
        def result = solution.maxProduct(nums as int[])

        then:
        result == exp

        where:
        exp         || nums
        6           || [2,3,-2,4]
        0           || [-2,0,-1]
        32          || [-2, -2, -1, -2, -2, -2]
        8           || [-2, -2, 0, -2, -2, 2]
        48          || [-2, 4, 2, -1, 3, -1, -1, -1]
        0           || [-9, 0, -123123, 0, -12312, 0, -7]
        -7          || [-7]

    }

}
