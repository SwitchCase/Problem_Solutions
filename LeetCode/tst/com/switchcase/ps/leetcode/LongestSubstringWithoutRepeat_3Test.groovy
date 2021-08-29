package com.switchcase.ps.leetcode

import spock.lang.Specification
import spock.lang.Unroll

class LongestSubstringWithoutRepeat_3Test extends Specification {

    @Unroll
    def "test"() {
        given:
        LongestSubstringWithoutRepeat_3.Solution solution = new LongestSubstringWithoutRepeat_3.Solution();

        when:
        def result = solution.lengthOfLongestSubstring(input)

        then:
        exp == result

        where:
        exp     || input
        3       || "abcb"
        2       || "cdd"
        1       || "bbbbb"
        13      || "asdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtyg"
        3       || "dvdf"
        0       || ""
        1       || "a"
        1       || "aa"
    }

}
