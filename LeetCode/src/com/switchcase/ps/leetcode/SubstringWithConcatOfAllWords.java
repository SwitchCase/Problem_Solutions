package com.switchcase.ps.leetcode;

import java.lang.reflect.Array;
import java.util.*;

/**
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 */
public class SubstringWithConcatOfAllWords {

    static class Solution {
        public List<Integer> findSubstring(String s, String[] words) {
            if (s.isEmpty() || words.length == 0) {
                return new ArrayList<>();
            }
            int[] locations = new int[s.length()];
            int N = words.length;
            int K = words[0].length();
            int L = s.length() - K + 1;

            Map<String, Integer> map = new HashMap<>();

            for (int i = 0; i < words.length; i++) {
                map.put(words[i], i);
            }

            //maybe do substring by hand to make it more efficient.
            StringBuilder stringBuilder = new StringBuilder(K);
            stringBuilder.append(" ");
            stringBuilder.append(s.substring(0, K-1));

            for (int i = 0; i + K <= s.length(); i++) {
                char newChar = s.charAt(i + K - 1);
                stringBuilder.deleteCharAt(0);
                stringBuilder.append(newChar);
                String wrd = stringBuilder.toString();
                if (map.containsKey(wrd)) {
                    int whichWord = map.get(wrd);
                    locations[i] = whichWord;
                } else {
                    locations[i] = -1;
                }
            }

            int[] req = new int[words.length];
            Arrays.fill(req, 0);
            for (int i = 0; i < words.length; i++) {
                int whichWord = map.get(words[i]);
                req[whichWord]++;
            }
            List<Integer> ans = new ArrayList<>();
            //the time complexity of below is K * W/K = O(W) (W = length of 's').
            for (int attempt = 0; attempt < K; attempt++) {
                int start = attempt, end = attempt;
                int count = 0;
                int[] counts = new int[words.length];
                Arrays.fill(counts, 0);
                while (end < L) {
                    int whichWordEnd = locations[end];
                    if (whichWordEnd != -1 && req[whichWordEnd] > counts[whichWordEnd]) {
                        count++;
                    }
                    if (whichWordEnd != -1)
                        counts[whichWordEnd]++;
                    while (start <= end && count == words.length) {
                        int whichWordStart = locations[start];
                        //verify
                        if (whichWordStart != -1 && req[whichWordStart] == counts[whichWordStart]) {
                            int length = end - start + K;
                            if (length == N * K) {
                                ans.add(start);
                            }
                        }
                        if (whichWordStart != -1) {
                            counts[whichWordStart]--;
                            if (req[whichWordStart] > counts[whichWordStart]) {
                                count--;
                            }
                        }
                        start+=K;
                    }
                    end+=K;
                }
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(new Solution().findSubstring("barfoothebarfooman",
                new String[] {"foo", "bar"}).toArray()));
    }
}
