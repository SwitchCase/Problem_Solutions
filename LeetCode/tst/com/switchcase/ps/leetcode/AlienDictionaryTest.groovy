package com.switchcase.ps.leetcode

import spock.lang.Specification

import java.awt.TexturePaint

class AlienDictionaryTest extends Specification {

    def test() {
        given:
        AlienDictionary.Solution solution = new AlienDictionary.Solution();

        when:
        def ans = solution.alienOrder(input as String[])

        then:
        ans == exp

        where:
        exp         || input
        "wertf"     || ["wrt","wrf","er","ett","rftt"]
    }
}
