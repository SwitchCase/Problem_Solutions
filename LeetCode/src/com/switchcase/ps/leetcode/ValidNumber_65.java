package com.switchcase.ps.leetcode;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ValidNumber_65 {

    //Passed all.
    static class Solution_Regex {
        private static final Pattern PATTERN = Pattern.compile("^(\\+|-)?((\\d+\\.)|(\\.\\d+)|(\\d+)|(\\d+\\.\\d+))?(((\\d+\\.)|(\\.\\d+)|(\\d+)|(\\d+\\.\\d+))e(\\+|-)?\\d+)?$");
        public boolean isNumber(String s) {
            if (s.trim().isEmpty() || s.matches(".*\\..*\\..*")) {
                return false;
            }
            Matcher matcher = PATTERN.matcher(s.trim());
            return matcher.matches();
        }
    }

    static class Solution {

        enum State {
            START(new Character[]{}),
            SIGN(new Character[]{'+', '-'}),
            E(new Character[]{'e'}),
            INT(new Character[]{'0','1', '2', '3', '4', '5', '6', '7', '8', '9'}),
            DOT(new Character[]{'.'}),
            OTHERS(new Character[]{});

            Set<Character> valid;

            State(Character[] valid) {
                this.valid = new HashSet<>(Arrays.asList(valid));
            }

            static State of(Character c) {
                if (SIGN.valid.contains(c)) {
                    return SIGN;
                } else if (E.valid.contains(c)) {
                    return E;
                } else if (INT.valid.contains(c)) {
                    return INT;
                } else if (DOT.valid.contains(c)) {
                    return DOT;
                } else {
                    return OTHERS;
                }
            }
        }

        public boolean isNumber(String s) {
            s = s.trim();
            if (s.isEmpty()) return false;
            State prev = State.START;
            int signCount = 0;
            int ePos = -1;
            int dotCount = 0;
            int dotPos = -1;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                State now = State.of(c);
                boolean allowed = false;
                switch (now) {
                    case E:
                        if (ePos == -1) {
                            ePos = i;
                        } else {
                            return false;
                        }
                        break;
                    case SIGN:
                        signCount++;
                        break;
                    case DOT:
                        dotCount++;
                        dotPos = i;
                        break;
                    case OTHERS:
                        return false;
                }

                if ((dotCount > 1 || signCount > 2) || (ePos >=0 && dotPos > ePos)) {
                    return false;
                }

                switch (prev) {
                    case START:
                        allowed = (now == State.INT || now == State.SIGN || now == State.DOT);
                        break;
                    case E:
                        allowed = (now == State.INT || now == State.SIGN) && (i > 1);
                        break;
                    case SIGN:
                        allowed = now == State.INT || now == State.DOT;
                        break;
                    case INT:
                        allowed = now == State.INT || now == State.DOT || now == State.E;
                        break;
                    case DOT:
                        allowed = (now == State.INT || (now == State.E && i > 1 && State.of(s.charAt(i - 2)) == State.INT));
                        break;
                }
                if (!allowed) {
                    return false;
                }
                prev = now;
            }

            switch (prev) {
                case E:
                case SIGN:
                    return false;
                case INT:
                    return true;
                case DOT:
                    if (s.length() > 1) {
                        State pre = State.of(s.charAt(s.length() - 2));
                        return pre == State.INT;
                    }
                    return false;
            }
            return true;
        }
    }

    public static void main(String[] args) {
        String[] inputs = new String[]{
                "  ",
                "-.",
                "12.1412.1e1",
                "56..6e5340",
                "1e+6",
                ".2e81",
                "134-2.1",
                ".",
                "e8",
                "1e8",
                "-.e7",
                ".1",
                "-.1",
                ".e7",
                " 0 ",
                "1.e3",
                "0",
                "123",
                "123.2",
                "123451.2123",
                "abc",
                "de12",
                "12a2",
                "12e1",
                "912e-2",
                "1213.23423e-2",
                "1213.23423e-2.0",
                "1213.23423e2.0",
                "1213e2.0",
                "-1213.23423e-2",
        };
        for (String s : inputs) {
            boolean correct = verify(s);
            boolean ans = new Solution().isNumber(s);
            if (ans != correct)
                System.out.println("WA FOR: Q: " + s + " : " +correct + " but was: " + ans);

        }
    }

   static boolean verify(String s) {
        try {
            Double.parseDouble(s.trim());
            return true;
        } catch (Exception e) {
            return false;
        }
    }


}
