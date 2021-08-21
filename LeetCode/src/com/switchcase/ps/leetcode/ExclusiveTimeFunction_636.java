package com.switchcase.ps.leetcode;

import java.util.*;

public class ExclusiveTimeFunction_636 {
    static class Solution {
        enum State {
            Start,
            End
        }

        class Data {
            State state;
            int time;
            int id;

            Data(String str) {
                String[] tokens = str.split(":");
                this.id = Integer.parseInt(tokens[0]);
                this.state = tokens[1].equals("start") ? State.Start : State.End;
                this.time = Integer.parseInt(tokens[2]) + (this.state == State.End ? 1 : 0);
            }
        }

        public int[] exclusiveTime(int n, List<String> logs) {
            int[] ans  = new int[n];
            Arrays.fill(ans,0);

            Stack<Data> stack = new Stack<>();
            stack.push(new Data(logs.get(0)));

            for(int i = 1; i < logs.size(); i++) {
                Data data = new Data(logs.get(i));
                if (data.state == State.End && !stack.isEmpty()) {
                    Data last = new Data(logs.get(i - 1));
                    int diff = data.time - last.time;
                    ans[data.id] += diff;
                } else if (data.state == State.Start) {
                    if (!stack.isEmpty()) {
                        Data last = new Data(logs.get(i - 1));
                        Data top = stack.peek();
                        int diff = data.time - last.time;
                        ans[top.id] += diff;
                    }
                    stack.push(data);
                }
            }
            return ans;
        }
    }
}
