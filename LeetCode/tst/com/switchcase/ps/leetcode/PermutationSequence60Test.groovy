package com.switchcase.ps.leetcode

import spock.lang.Specification

class PermutationSequence60Test extends Specification {

    def "test"() {
        given:
        PermutationSequence60.Solution solution = new PermutationSequence60.Solution()

        when:
        def result = solution.getPermutation(n, k)

        then:
        result == exp

        where:
        n   | k     || exp
        4   | 11    || "2413"
        4   | 24    || "4321"
        4   | 1     || "1234"
        1   | 1     || "1"
        3   | 6     || "321"
    }
}

