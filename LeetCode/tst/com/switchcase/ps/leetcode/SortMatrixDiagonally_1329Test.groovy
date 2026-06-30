package com.switchcase.ps.leetcode

import spock.lang.Specification

class SortMatrixDiagonally_1329Test extends Specification {

    def "diagonalSort_SingleElementMatrix"() {
        given:
        int[][] mat = [[1]]
        int[][] expected = [[1]]
        SortMatrixDiagonally_1329.Solution solution = new SortMatrixDiagonally_1329().new Solution()

        expect:
        solution.diagonalSort(mat) == expected
    }

    def "diagonalSort_AlreadySortedMatrix"() {
        given:
        int[][] mat = [
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]
        ]
        int[][] expected = [
                [1, 2, 3],
                [4, 5, 6],
                [7, 8, 9]
        ]
        SortMatrixDiagonally_1329.Solution solution = new SortMatrixDiagonally_1329().new Solution()

        expect:
        solution.diagonalSort(mat) == expected
    }

    def "diagonalSort_UnsortedMatrix"() {
        given:
        int[][] mat = [
                [3, 3, 1],
                [2, 2, 1],
                [1, 1, 1]
        ]
        int[][] expected = [
                [1, 1, 1],
                [1, 2, 3],
                [1, 2, 3]
        ]
        SortMatrixDiagonally_1329.Solution solution = new SortMatrixDiagonally_1329().new Solution()

        expect:
        solution.diagonalSort(mat) == expected
    }

    def "diagonalSort_RectangularMatrix"() {
        given:
        int[][] mat = [
                [11, 25, 66, 1],
                [23, 55, 17, 45],
                [75, 31, 36, 44]
        ]
        int[][] expected = [
                [11, 17, 45, 1],
                [23, 55, 25, 66],
                [75, 31, 36, 44]
        ]
        SortMatrixDiagonally_1329.Solution solution = new SortMatrixDiagonally_1329().new Solution()

        expect:
        solution.diagonalSort(mat) == expected
    }

    def "diagonalSort_EmptyMatrix"() {
        given:
        int[][] mat = []
        int[][] expected = []
        SortMatrixDiagonally_1329.Solution solution = new SortMatrixDiagonally_1329().new Solution()

        expect:
        solution.diagonalSort(mat) == expected
    }
}