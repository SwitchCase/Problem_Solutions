package com.switchcase.ps.leetcode

import spock.lang.Specification

class ExclusiveTimeFunction_636Test extends Specification {

    def test() {
        given:
        ExclusiveTimeFunction_636.Solution solution = new ExclusiveTimeFunction_636.Solution();
        int n = 1
        def lst = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]

        when:
        def ans = solution.exclusiveTime(n, lst)

        then:
        ans == [8] as int[]
    }

    def test2() {
        given:
        ExclusiveTimeFunction_636.Solution solution = new ExclusiveTimeFunction_636.Solution();
        int n = 2
        def lst = ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]

        when:
        def ans = solution.exclusiveTime(n, lst)

        then:
        ans == [8, 1] as int[]
    }

    def test3() {
        given:
        ExclusiveTimeFunction_636.Solution solution = new ExclusiveTimeFunction_636.Solution();
        int n = 2
        def lst = ["0:start:0","1:start:2","1:end:5","0:end:6"]

        when:
        def ans = solution.exclusiveTime(n, lst)

        then:
        ans == [3, 4] as int[]
    }
}
