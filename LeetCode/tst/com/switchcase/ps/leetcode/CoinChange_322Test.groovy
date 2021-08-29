package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class CoinChange_322Test extends Specification {

    @Unroll
    def "test"() {
        given:
        CoinChange_322.Solution solution = new CoinChange_322.Solution()

        when:
        def result = solution.coinChange(coins as int[], amount)

        then:
        exp == result

        where:
        exp         | amount        || coins
        3           | 11            || [1,2,5]
        -1          | 2             || [3, 5]
        0           | 0             || [1,2,5]
        1           | 1             || [1]
        100         | 100           || [1]

    }
}
