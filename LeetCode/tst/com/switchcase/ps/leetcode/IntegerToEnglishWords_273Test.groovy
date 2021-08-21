package com.switchcase.ps.leetcode

import spock.lang.Specification

class IntegerToEnglishWords_273Test extends Specification {

    def test() {
        given:
        IntegerToEnglishWords_273.Solution solution = new IntegerToEnglishWords_273.Solution()

        when:
        def ans = solution.numberToWords(num)

        then:
        ans == exp

        where:
        num          || exp
        0            || "Zero"
        7            || "Seven"
        39           || "Thirty Nine"
        201067       || "Two Hundred One Thousand Sixty Seven"
        2000_000_000 || "Two Billion"
        2000_000_001 || "Two Billion One"
    }
}
