package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class ValidPalindrome2_680Test extends Specification {

    @Unroll
    def test() {
        given:
        ValidPalindrome2_680.Solution solution = new ValidPalindrome2_680.Solution()

        when:
        def ans = solution.validPalindrome(input)

        then:
        ans == exp

        where:
        exp     || input
        true    || "abccdba"
        true    || "bcba"
        true    || "abcdcba"
        true    || "abcdcbaa"
        false   || "abc"
    }
}
