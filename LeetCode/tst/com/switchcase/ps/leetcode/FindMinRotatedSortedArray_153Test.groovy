package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class FindMinRotatedSortedArray_153Test extends Specification {

    @Unroll
    def "test"() {
        given:
        FindMinRotatedSortedArray_153.Solution solution = new FindMinRotatedSortedArray_153.Solution()

        when:
        def result = solution.findMin(nums as int[])

        then:
        exp == result

        where:
        exp     || nums
        1       || [4,5,1,2,3]
        1       || [5,5,1,1,1,1,5]
        11      || [11,13,15,17]
        1       || [3,4,5,1,2]


    }
}
