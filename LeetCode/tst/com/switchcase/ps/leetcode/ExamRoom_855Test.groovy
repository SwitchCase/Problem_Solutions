package com.switchcase.ps.leetcode

import spock.lang.Specification

class ExamRoom_855Test extends Specification {

    def test() {
        given:
        int N = 10;
        ExamRoom_855.ExamRoom room = new ExamRoom_855.ExamRoom(N)

        when:
        def ans = room.seat()
        then:
        ans == 0

        when:
        ans = room.seat()
        then:
        ans == N - 1

        when:
        ans = room.seat()
        then:
        ans == 4

        when:
        ans = room.seat()
        then:
        ans == 2

        when:
        room.leave(4)
        then:
        noExceptionThrown()

        when:
        ans = room.seat()
        then:
        ans == 5
    }

    def test2() {
        given:
        int N = 8;
        ExamRoom_855.ExamRoom room = new ExamRoom_855.ExamRoom(N)

        when:
        def ans = room.seat()
        then:
        ans == 0

        when:
        ans = room.seat()
        then:
        ans == 7

        when:
        ans = room.seat()
        then:
        ans == 3

        when:
        room.leave(0)
        then:
        noExceptionThrown()

        when:
        room.leave(7)
        then:
        noExceptionThrown()

        when:
        ans = room.seat()
        then:
        ans == 7

        when:
        ans = room.seat()
        then:
        ans == 0

        when:
        ans = room.seat()
        then:
        ans == 5

        when:
        ans = room.seat()
        then:
        ans == 1

        when:
        ans = room.seat()
        then:
        ans == 2

        when:
        ans = room.seat()
        then:
        ans == 4

        when:
        ans = room.seat()
        then:
        ans == 6
    }

}
