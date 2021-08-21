package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class NextPermutation_31Test extends Specification {

    @Unroll
    def test() {
        given:
        NextPermutation_31.Solution solution = new NextPermutation_31.Solution()

        when:
        def ans = solution.testHelper(nums as int[])

        then:
        ans == exp

        where:
        nums            || exp
        [1,5,1]         || [5,1,1]
        [3,1,3,3]       || [3,3,1,3]
        [6,4,1,2,5]     || [6,4,1,5,2]
        [5,4,3,2,1]     || [1,2,3,4,5]
        [1,1]           || [1,1]
        [1,2]           || [2,1]
        [2,1]           || [1,2]

    }
}
