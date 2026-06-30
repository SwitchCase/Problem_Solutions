package com.switchcase.ps.leetcode

import spock.lang.Specification

class PermutationInString_567Test extends Specification {

    def test() {
        given:
        def sut = new PermutationInString_567.Solution()

        when:
        def result = sut.checkInclusion(s1, s2)

        then:
        result == expected

        where:
        s1   | s2               || expected
        "ab" | "eidbaooo"       || true
    }
}
