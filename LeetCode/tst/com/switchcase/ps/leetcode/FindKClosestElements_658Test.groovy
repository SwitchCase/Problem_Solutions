package com.switchcase.ps.leetcode

import spock.lang.Specification

class FindKClosestElements_658Test extends Specification {

    def "test"() {
        given:
        FindKClosestElements_658.Solution solution = new FindKClosestElements_658.Solution()

        when:
        def result = solution.findClosestElements(arr as int[], k, x)

        then:
        result == exp

        where:
        k       | x         | exp                               || arr
        4       | 3         | [1,2,3,4]                         || [1,2,3,4,5]
        4       | -1        | [1,2,3,4]                         || [1,2,3,4,5]

    }
}
