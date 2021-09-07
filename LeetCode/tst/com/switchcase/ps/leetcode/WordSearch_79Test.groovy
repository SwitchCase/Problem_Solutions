package com.switchcase.ps.leetcode

import spock.lang.Specification

class WordSearch_79Test extends Specification {

    def "test"() {
        given:
        WordSearch_79.Solution solution = new WordSearch_79.Solution()

        when:
        def result = solution.exist(board as char[][], word)

        then:
        result == exp

        where:

        exp     | word              || board
        true    | "ABCESEEEFSAD"    || [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
        true    | "ABCCED"          || [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    }
}
