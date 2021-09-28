package com.switchcase.ps.leetcode

import spock.lang.Specification

class Permutations2_47Test extends Specification {

    def "test"() {
        given:
        Permutations2_47.Solution solution = new Permutations2_47.Solution();

        when:
        def result = solution.permuteUnique(nums as int[])

        then:
        result.sort() == exp.sort()

        where:
        nums                        || exp
        [1,2,3]                     || [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        [2,2,1,1]                   || [[1,1,2,2],[1,2,1,2],[1,2,2,1],[2,1,1,2],[2,1,2,1],[2,2,1,1]]
        [1,1,2]                     || [[1,1,2],
                                        [1,2,1],
                                        [2,1,1]]





    }
}
