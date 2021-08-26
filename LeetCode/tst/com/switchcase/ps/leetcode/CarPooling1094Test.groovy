package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class CarPooling1094Test extends Specification {

    @Unroll
    def "Test"() {
        given:
        CarPooling1094.Solution solution = new CarPooling1094.Solution();

        when:
        def result = solution.carPooling(trips as int[][], capacity)

        then:
        exp == result

        where:
        exp     | capacity  || trips
        false   | 4         || [[2,1,5],[3,3,7]]
        true    | 5         || [[2,1,5],[3,3,7]]
        true    | 3         || [[2,1,5],[3,5,7]]
        true    | 11        || [[3,2,7],[3,7,9],[8,3,9]]

    }
}
