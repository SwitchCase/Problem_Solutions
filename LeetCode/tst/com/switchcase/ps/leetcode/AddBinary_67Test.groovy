package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

import java.awt.TexturePaint

class AddBinary_67Test extends Specification {

    @Unroll
    def test() {
        given:
        AddBinary_67.Solution solution = new AddBinary_67.Solution();

        when:
        def ans = solution.addBinary(a, b)

        then:
        ans == exp

        where:
        a       | b       || exp
        "10111" | "101"   || "11100"
        "111"   | "10010" || "11001"
        "111"   | "1"     || "1000"
        "0"     | "0"     || "0"
        "1"     | "0"     || "1"
        "1"     | "1"     || "10"
    }
}
