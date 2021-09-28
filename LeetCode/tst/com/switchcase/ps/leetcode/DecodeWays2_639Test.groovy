package com.switchcase.ps.leetcode

import spock.lang.Specification

class DecodeWays2_639Test extends Specification {

    def "test"() {
        given:
        DecodeWays2_639.Solution solution = new DecodeWays2_639.Solution()

        when:
        def result = solution.numDecodings(input)

        then:
        result == exp

        where:
        exp         || input
        9           || "*"
        18          || "1*"
        15          || "2*"
        96          || "**"
        11          || "*1"
        2           || "*0"
        291868912   || "*********"
        96390955    || "******************************************************"
        972607479   || "*****************************************************************************************"
    }
}
