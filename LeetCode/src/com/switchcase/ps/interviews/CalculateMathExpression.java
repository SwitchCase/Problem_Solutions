package com.switchcase.ps.interviews;

import java.util.*;

public class CalculateMathExpression {

    public int calculate(String input) {
        List<String> list = new ArrayList<>();
        String curr = "";
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) < '0' || input.charAt(i) > '9') {
                list.add(input.charAt(i) + "");
            } else {
                while (i < input.length() && input.charAt(i) >= '0' && input.charAt(i) <= '9') {
                    curr += input.charAt(i);
                    i++;
                }
                list.add(curr);
                curr = "";
                i--;
            }
        }

        return getNextOperand(list, 0).left;
    }

    private PII getNextOperand(List<String> list, int sIdx) {
        List<String> internal = new ArrayList<>();
        for (int i = sIdx; i < list.size(); i++) {
            if (")".equals(list.get(i))) {
                return new PII(calculateList(internal, 0, internal.size() - 1), i);
            } else if ("(".equals(list.get(i))) {
                PII val = getNextOperand(list, i + 1);
                int ans = val.left;
                int nextIdx = val.right;
                internal.add(Integer.toString(ans));
                i = nextIdx;
            } else {
                internal.add(list.get(i));
            }
        }
        return new PII(calculateList(internal, 0, internal.size() - 1), list.size());
    }

    private int calculateList(List<String> list, int sIdx, int eIdx) {
        int ans = 0;
        for(int i = sIdx; i < list.size() && i <= eIdx; i++) {
            if ("+".equals(list.get(i)) || "-".equals(list.get(i))) {
                int next = Integer.parseInt(list.get(i + 1));
                if ("-".equals(list.get(i))) {
                    ans = ans - next;
                } else {
                    ans = ans + next;
                }
                i++;
            } else {
                ans = Integer.parseInt(list.get(i));
            }
        }
        return ans;
    }

    class PII {
        Integer left;
        Integer right;

        PII(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

}
