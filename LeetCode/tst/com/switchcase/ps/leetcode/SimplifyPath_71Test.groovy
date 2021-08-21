package com.switchcase.ps.leetcode

import spock.lang.Specification

class SimplifyPath_71Test extends Specification {

    def test() {
        given:
        SimplifyPath_71.Solution solution = new SimplifyPath_71.Solution();

        when:
        def ans = solution.simplifyPath(input)

        then:
        ans == exp

        where:
        input                   || exp
        "/home/"                || "/home"
        "/../"                  || "/"
        "/home//foo/"           || "/home/foo"
        "/a/./b/../../c/"       || "/c"
        "/a/../../b/../c//.//"  || "/c"
        "/a//b////c/d//././/.." || "/a/b/c"
        "/../../../../../../.." || "/"
        "///////a/////.."       || "/"
    }
}
