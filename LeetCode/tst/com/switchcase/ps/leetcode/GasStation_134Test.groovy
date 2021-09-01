package com.switchcase.ps.leetcode

import spock.lang.Specification

class GasStation_134Test extends Specification {

    def "test"() {
        given:
        GasStation_134.Solution solution = new GasStation_134.Solution()

        when:
        def result = solution.canCompleteCircuit(gas as int[], cost as int[])

        then:
        exp == result

        where:
        exp        | gas                            || cost
        3          | [1,2,3,4,5]                    || [3,4,5,1,2]
        -1         | [2,3,4]                        || [3,4,3]
    }
}
