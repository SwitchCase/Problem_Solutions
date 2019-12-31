package com.switchcase.ps.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
public class LongestSubstringWithoutRepeat_3 {

    static class Solution {

        public int lengthOfLongestSubstring(String s) {
            Map<Character, Integer> map = new HashMap<>();
            int longest = 0;
            int i, j;
            for (i = 0, j = 0; j < s.length(); j++) {
                if (map.containsKey(s.charAt(j)) && map.get(s.charAt(j)) >= i) {
                    longest = Math.max(longest, j - i);
                    i = map.get(s.charAt(j)) + 1;
                    map.put(s.charAt(j), j);
                } else {
                    map.put(s.charAt(j), j);
                }
            }
            longest = Math.max(longest, j - i);
            return longest;
        }

    }

    static class SolutionPassesNonOptimal {

        public int lengthOfLongestSubstring(String s) {
            String[] dp = new String[s.length() + 4];
            for(int i = 0; i < s.length() + 4; i++) dp[i] = "-1";
            longestSubString(dp, s, 0);
            String longest = "";
            for (int i = 0; i < dp.length; i++) {
                if (dp[i].equals("-1")) continue;
                longest = longest.length() > dp[i].length()? longest : dp[i];
            }
            System.out.println(longest);
            return longest.length();
        }

        private String longestSubString(String[] dp, String s, int startPos) {
            if (startPos >= s.length()) {
                return "";
            }
            if (!dp[startPos].equals("-1")) return dp[startPos];
            String longest = longestSubString(dp, s, startPos + 1);
            if (longest.contains("" + s.charAt(startPos))) {
                Set<Character> chars = new HashSet<>();
                for (int j = startPos; j < s.length(); j++) {
                    if (chars.contains(s.charAt(j))) {
                        String str = chars.stream().map(c -> "" + c).collect(Collectors.joining(""));
                        return (dp[startPos] = str);
                    } else chars.add(s.charAt(j));
                }
                return dp[startPos] = "" + s.charAt(startPos);

            } else {
                return (dp[startPos] = "" + s.charAt(startPos) + longest);
            }
        }
    }

    public static void main(String[] args) {
        String[] cases = {
                "abcb", //3
                "cdd", //2
                "abcabcbb", //3
                "bbbbb", //1
                "", //0
                "pwwkew", //3
                "a", //1
                "asdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtygasdaasfwy5uj6uwb45tgrefawerc3w5y3w64uw456tgrafREgwv4g7u8bwerw3t3y53jioeahjorgihaerhtyg", //13
                "dvdf" //3
         };

        for (String s : cases) {
            System.out.println("Case: " + s + " : " + new Solution().lengthOfLongestSubstring(s));
        }
    }
}
