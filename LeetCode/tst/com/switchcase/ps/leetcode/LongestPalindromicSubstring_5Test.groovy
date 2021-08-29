package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class LongestPalindromicSubstring_5Test extends Specification {

    @Unroll
    def "test"() {
        given:
        LongestPalindromicSubstring_5.Solution solution = new LongestPalindromicSubstring_5.Solution();

        when:
        def result = solution.longestPalindrome(str)

        then:
        exp == result

        where:
        str              || exp
        "babadaba"       || "abadaba"
        "babad"          || "bab"
        "cbbd"           || "bb"
        "abc"            || "a"
        "a"              || "a"

    }

}
