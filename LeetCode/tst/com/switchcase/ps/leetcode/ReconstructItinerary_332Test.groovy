package com.switchcase.ps.leetcode

import spock.lang.Specification

class ReconstructItinerary_332Test extends Specification {

    def test() {
        given:
        ReconstructItinerary_332.Solution sol = new ReconstructItinerary_332.Solution();

        when:
        def ans = sol.findItinerary(input)

        then:
        ans == expAns

        where:
        expAns || input
        ["JFK", "LHR", "SFO", "SJC", "MUC", "JFK", "MUC", "LHR"] || [["MUC", "LHR"], ["JFK", "MUC"], ["MUC", "JFK"], ["JFK", "LHR"], ["SJC", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
        ["JFK", "MUC", "LHR", "SFO", "SJC"] || [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]

    }

}
