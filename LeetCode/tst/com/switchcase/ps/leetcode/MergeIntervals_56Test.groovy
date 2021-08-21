package com.switchcase.ps.leetcode

import spock.lang.Specification

class MergeIntervals_56Test extends Specification {

    def test() {
        given:
        MergeIntervals_56.Solution solution = new MergeIntervals_56.Solution();

        when:
        int[][] ans = solution.merge(input as int[][])

        then:
        ans == (expected as int[][])

        where:
        input || expected
        [[1,9],[2,4],[7,9],[6,7]] || [[1,9]]
        [[1,3],[2,6],[8,10],[15,18]] || [[1,6],[8,10],[15,18]]
        [[1,4],[4,5]] ||  [[1,5]]
    }

}
