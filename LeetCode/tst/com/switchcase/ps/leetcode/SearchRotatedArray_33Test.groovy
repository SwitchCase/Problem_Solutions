package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class SearchRotatedArray_33Test extends Specification {

    @Unroll
    def "test"() {
        given:
        SearchRotatedArray_33.Solution solution = new SearchRotatedArray_33.Solution()

        when:
        def result = solution.search(nums as int[], target)

        then:
        exp == result

        where:
        exp     | target     || nums
        -1      | 0          || [5,1,3]
        3       | 232        || [120, 199, 201, 232, 1,3, 11, 99, 102, 105]
        8       | 3          || [2,2,2,2,2,2,2,2,3,2,2,2,2]
        //0       | 2          || [2,2,2,2,2,2,2,2,2,2,2,2,2]
        -1      | 1          || [2,2,2,2,2,2,2,2,3,2,2,2,2]
        0       | 0          || [0]
        -1      | 1          || [0]
    }
}
