package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class PatchingArray330Test extends Specification {

    @Unroll
    def "test"() {
        given:
        PatchingArray330.Solution solution = new PatchingArray330.Solution();

        when:
        def result = solution.minPatches(input as int[], N)

        then:
        result == expectation

        where:
        expectation | N          || input
        1           | 20         || [1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94]
        2           | 47         || [1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94]
        2           | 81         || [1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94]
        2           | 120        || [1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94]
        2           | 20         || [1,5,10]
        0           | 5          || [1,2,2]
        28          | 2147483647 || [1,2,31,33]
    }

}
