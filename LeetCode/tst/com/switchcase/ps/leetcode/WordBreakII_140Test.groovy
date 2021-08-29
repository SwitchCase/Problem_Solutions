package com.switchcase.ps.leetcode

import spock.lang.Specification

class WordBreakII_140Test extends Specification {

    def "test"() {
        given:
        WordBreakII_140.Solution solution = new WordBreakII_140.Solution();

        when:
        def result = solution.wordBreak(input, dict)

        then:
        exp.sort() == result.sort()

        where:
        input               | dict                                           || exp
        "catsanddog"        | ["cat","cats","and","sand","dog"]              || ["cats and dog","cat sand dog"]
        "pineapplepenapple" | ["apple","pen","applepen","pine","pineapple"]  || ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
        "cats"              | ["cat", "cats"]                                || ["cats"]
    }
}
