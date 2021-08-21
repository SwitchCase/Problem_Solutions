package com.switchcase.ps.leetcode

import spock.lang.Specification

class PalindromicSubstring_647Test extends Specification {

    def test() {
        given:
        PalindromicSubstring_647.Solution solution = new PalindromicSubstring_647.Solution();

        when:
        def ans = solution.countSubstrings(input)

        then:
        ans == exp

        where:
        input       || exp
        "abc"       || 3
        "aaa"       || 6
        "ababa"     || 9
        "hello"     || 6

    }
}
