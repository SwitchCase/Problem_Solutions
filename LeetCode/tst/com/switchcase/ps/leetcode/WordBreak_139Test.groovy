package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class WordBreak_139Test extends Specification {

    @Unroll
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
        true     | "walmart"        || ["w", "al", "m", "mart", "art"]
        true     | "aaaaaa"         || ["aa", "aaa"]
        false    | "aaaaaa"         || ["aaaa", "aaba"]
        true     | "aaasdasdasdasda"|| ["aaaa", "aaaaa", "asda", "as", "da", "sd", "aaa", "a", "b", "s", "d"]
        true     | "aaasdasdasdasda"|| ["a", "aa", "aaa", "aas", "aaasd", "aaasda", "da", "sda", "dasda" ]
        true     | "aasdasdaqwqwrfqdwasdasdasdwq" || ["a", "s", "d", "q", "w", "r", "f"]
    }
}

