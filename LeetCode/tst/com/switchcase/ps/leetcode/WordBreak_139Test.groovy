package com.switchcase.ps.leetcode

import spock.lang.Specification

class WordBreak_139Test extends Specification {

    def test() {
        given:
        WordBreak_139.Solution solution = new WordBreak_139.Solution();

        when:
        def ans = solution.wordBreak(input, list)

        then:
        ans == expected

        where:
        expected | input            || list
        true     | "leetcode"       || ["leet", "code"]
        true     | "applepenapple"  || ["apple", "pen"]
    }
}
