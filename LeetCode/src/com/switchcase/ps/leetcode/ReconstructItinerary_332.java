package com.switchcase.ps.leetcode;

import java.util.*;

public class ReconstructItinerary_332 {
    class Solution {

        class Ticket {
            String from;
            String to;
            int idx;

            public Ticket(String from, String to, int idx) {
                this.from = from;
                this.to = to;
                this.idx = idx;
            }
        }

        public List<String> findItinerary(List<List<String>> tickets) {
            Map<String, List<Ticket>> ticketMap = new HashMap<>();
            for (int i = 0; i < tickets.size(); i++) {
                String from = tickets.get(i).get(0);
                String to = tickets.get(i).get(1);
                ticketMap.putIfAbsent(from, new ArrayList<>());
                ticketMap.get(from).add(new Ticket(from, to, i));
            }

            for (Map.Entry<String, List<Ticket>> entry : ticketMap.entrySet()) {
                entry.getValue().sort(Comparator.comparing(t -> t.to));
            }

            return getBestPath(ticketMap, tickets, "JFK", new boolean[tickets.size()], 0, new ArrayList<String>() {{add("JFK");}});
        }

        private List<String> getBestPath(Map<String, List<Ticket>> ticketMap, List<List<String>> tickets, String lastDest, boolean[] visited, int done, List<String> pathSoFar) {
            if (done == tickets.size()) {
                return new ArrayList<>(pathSoFar);
            }
            List<Ticket> candidates = ticketMap.getOrDefault(lastDest, new ArrayList<>());
            List<String> newPath = new ArrayList<>(pathSoFar);
            List<String> bestPath = null;
            for (Ticket ticket : candidates) {
                if (visited[ticket.idx]) {
                    continue;
                }
                String next = ticket.to;
                visited[ticket.idx] = true;
                newPath.add(next);
                List<String> path = getBestPath(ticketMap, tickets, next, visited, done + 1, newPath);
                visited[ticket.idx] = false;
                newPath.remove(newPath.size() - 1);
                if (path != null) {
                    bestPath = path;
                    break;
                }
            }

            return bestPath;
        }
    }
}

