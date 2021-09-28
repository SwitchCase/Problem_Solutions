package com.switchcase.ps.leetcode

import spock.lang.Specification

class PalindromePartitioning3_1278Test extends Specification {

    def "test"() {
        given:
        PalindromePartitioning3_1278.Solution solution = new PalindromePartitioning3_1278.Solution()

        when:
        def result = solution.palindromePartition(str, k)

        then:
        result == exp

        where:
        exp     | k         || str
        1       | 2         || "abc"
        0       | 3         || "aabbc"
        0       | 8         || "leetcode"
    }
}
