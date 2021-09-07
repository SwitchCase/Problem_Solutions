package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class FindClosestPalindrome_564Test extends Specification {

    @Unroll
    def "test"() {
        given:
        FindClosestPalindrome_564.Solution solution = new FindClosestPalindrome_564.Solution()

        when:
        def result = solution.nearestPalindromic(input)

        then:
        exp == result

        where:
        input                 || exp
        "1000"                || "999"
        "11"                  || "9"
        "0"                   || "1"
        "1"                   || "0"
        "2"                   || "1"
        "10"                  || "9"
        "12"                  || "11"
        "15"                  || "11"
        "16"                  || "11"
        "21"                  || "22"
        "101"                 || "99"
        "100"                 || "99"
        "99"                  || "101"
        "500000"              || "500005"
        "1723091591"          || "1723113271"
        "807045053224792883"  || "807045053350540708"
        "99999999999"         || "100000000001"
        "123"                 || "121"
    }
}
