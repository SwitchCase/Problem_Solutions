package com.switchcase.ps.leetcode

import spock.lang.Specification

class MaxSum3NonOverlappingSubarray_689Test extends Specification {

    def test0() {
        given:
        MaxSum3NonOverlappingSubarray_689.Solution solution = new MaxSum3NonOverlappingSubarray_689.Solution();

        def input = [4, 3, 2, 1];

        when:
        def ans = solution.maxSumOfThreeSubarrays(input as int[], 1);

        then:
        ans == [0, 1, 2]
    }

    def test() {
        given:
        MaxSum3NonOverlappingSubarray_689.Solution solution = new MaxSum3NonOverlappingSubarray_689.Solution();

        when:
        def ans = solution.maxSumOfThreeSubarrays([1, 2, 1, 2, 6, 7, 5, 1] as int[], 2);

        then:
        ans == [0, 3, 5]
    }

    def test2() {
        given:
        MaxSum3NonOverlappingSubarray_689.Solution solution = new MaxSum3NonOverlappingSubarray_689.Solution();

        int[] input = new int[10000];
        for (int i = 0; i < 10000; i++) input[i] = i;

        when:
        def ans = solution.maxSumOfThreeSubarrays(input, 1000);

        then:
        ans == [7000, 8000, 9000]
    }

    def test4() {
        given:
        MaxSum3NonOverlappingSubarray_689.Solution solution = new MaxSum3NonOverlappingSubarray_689.Solution();

        int[] input = [1,2,1,2,1,2,1,2,1];

        when:
        def ans = solution.maxSumOfThreeSubarrays(input, 2);

        then:
        ans == [0,2,4]
    }


}
