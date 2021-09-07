package com.switchcase.ps.interviews

import spock.lang.Specification
import spock.lang.Unroll

class CalculateMathExpressionTest extends Specification {

    @Unroll
    def "test"() {
        given:
        CalculateMathExpression calculator = new CalculateMathExpression();

        when:
        def result = calculator.calculate(input)

        then:
        exp == result

        where:
        exp     || input
        6       || "2-(3-6)+1"
        -6      || "5-(7+6-(3+4)+2)-3"
        -4      || "5-(7+6-(3+4)+2)-3+(((7+2)+(6-9)-(6-9)-5)-4)+2"
        10      || "3+7+0-0+1-1"
        10      || "3-7+4-0+1-1+10"

    }
}
