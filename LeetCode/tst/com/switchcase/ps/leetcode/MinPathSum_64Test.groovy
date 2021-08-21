package com.switchcase.ps.leetcode

import spock.lang.Specification

class MinPathSum_64Test extends Specification {

    def test() {
        given:
        MinPathSum_64.Solution solution = new MinPathSum_64.Solution();

        when:
        def ans = solution.minPathSum(grid as int[][])

        then:
        ans == expected

        where:
        grid = [
                [1,3,1],
                [1,5,1],
                [4,2,1]
        ]
        expected = 7

    }
}
