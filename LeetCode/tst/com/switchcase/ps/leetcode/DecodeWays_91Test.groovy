package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class DecodeWays_91Test extends Specification {

    @Unroll
    def "test"() {
        given:
        DecodeWays_91.Solution solution = new DecodeWays_91.Solution()

        when:
        def result = solution.numDecodings(str)

        then:
        exp == result

        where:
        exp         || str
        0           || "0"
        0           || "00"
        0           || "00000000000000000000000000000"
        0           || "100"
        1           || "1"
        1           || "9"
        1           || "99"
        2           || "11"
        3           || "111"
    }
}
