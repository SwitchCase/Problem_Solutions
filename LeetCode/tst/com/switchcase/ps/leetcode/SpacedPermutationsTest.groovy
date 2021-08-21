package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class SpacedPermutationsTest extends Specification {

    @Unroll
    def test() {
        given:
        SpacedPermutations.Solution solution = new SpacedPermutations.Solution()

        when:
        def ans = solution.solve(n)

        then:
        println(ans.size())

        where:
        n << [1,2,3,4,5,6,7,8,9,10,11]
    }
}
