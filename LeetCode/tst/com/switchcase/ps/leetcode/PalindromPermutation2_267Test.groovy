package com.switchcase.ps.leetcode

import spock.lang.Specification

class PalindromPermutation2_267Test extends Specification {

    def test() {
        given:
        PalindromPermutation2_267.Solution solution = new PalindromPermutation2_267.Solution();

        when:
        def ans = solution.generatePalindromes(input)

        then:
        ans == exp

        where:
        input       || exp
        "abc"       || []
        "abba"      || ["abba", "baab"]
        "abcba"     || ["abcba", "bacab"]
        "abbc"      || []
        "aaaaccbbe" || ["caabebaac", "cbaaeaabc", "aacbebcaa", "abcaeacba", "bacaeacab", "cabaeabac", "aabcecbaa", "acbaeabca",
                        "abacecaba", "acabebaca", "baacecaab", "bcaaeaacb"]


    }

}
