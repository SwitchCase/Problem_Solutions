package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class SplitArrayIntoConsSeq_659Test extends Specification {

    @Unroll
    def "test"() {
        given:
        SplitArrayIntoConsSeq_659.Solution solution = new SplitArrayIntoConsSeq_659.Solution();

        when:
        def result = solution.isPossible(nums as int[])

        then:
        result == exp

        where:
        exp     || nums
        true    || [1, 2, 3, 4, 5, 5, 6, 7]
        false   || [1, 2, 3, 4, 4, 5]
        true    || [4,5,6,7,7,8,8,9,10,11]
        false   || [2,3,9,10,10,11,11,12,13,14]
        true    || [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 9]
        true    || [1, 2, 3, 4]
        false   || [1, 2, 5, 6, 7]
    }
}
