package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class KthLargestElement215Test extends Specification {

    @Unroll
    def "test"() {
        given:
        KthLargestElement215.Solution solution = new KthLargestElement215.Solution()

        when:
        def result = solution.findKthLargest(nums as int[], k)

        then:
        exp == result

        where:

        exp     | k     || nums
        4       | 4     || [3,2,3,1,2,4,5,5,6]
        5       | 2     || [3,2,1,5,6,4]

    }
}
