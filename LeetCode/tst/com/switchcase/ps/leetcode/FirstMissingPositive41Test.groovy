package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class FirstMissingPositive41Test extends Specification {

    @Unroll
    def "test"() {
        given:
        FirstMissingPositive41.Solution solution = new FirstMissingPositive41.Solution()

        when:
        def result = solution.firstMissingPositive(nums as int[])

        then:
        exp == result

        where:
        exp     || nums
        2       || [1,3]
        3       || [1,2]
        2       || [1]
        1       || [45]
        1       || [-1]
        1       || [0]
        1       || [-1, -1]
        1       || [0, 0]
        8       || [-3, 0, 4, 5, 7, 2, 1, 3, 6, 9, 10]
    }

}
