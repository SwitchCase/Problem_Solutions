package com.switchcase.ps.crackingcodinginterview

import spock.lang.Specification

class ExpressionCombosTest extends Specification {

    def test() {
        given:
        ExpressionCombos.Solution solution = new ExpressionCombos.Solution();

        when:
        def ans = solution.count(input, val)

        then:
        ans == exp

        where:
        input   | val    || exp

        "1234"  | 4      || 1
        "123456789" | 100 || 11
        "4"     | 4      || 1
    }
}
