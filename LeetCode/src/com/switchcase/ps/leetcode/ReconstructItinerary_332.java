package com.switchcase.ps.leetcode;

import java.awt.image.AreaAveragingScaleFilter;
import java.util.*;

public class ReconstructItinerary_332 {
    class Solution {

        class Ticket implements Comparable<Ticket> {
            String from;
            String to;
            int id;
            Ticket(String from, String to, int id) {
                this.from = from;
                this.to = to;
                this.id = id;
            }

            @Override
            public int compareTo(Ticket o) {
                return this.to.compareTo(o.to);
            }
        }

        public List<String> findItinerary(List<List<String>> T) {
            List<Ticket> tickets = new ArrayList<>();
            for (int i = 0; i < T.size(); i++) {
                tickets.add(new Ticket(T.get(i).get(0), T.get(i).get(1), i));
            }

            Map<String, List<Ticket>> graph = new HashMap<>();
            for (Ticket ticket : tickets) {
                graph.putIfAbsent(ticket.from, new ArrayList<>());
                graph.get(ticket.from).add(ticket);
            }

            for (String k : graph.keySet()) {
                graph.get(k).sort(Ticket::compareTo);
            }

            List<String> path = new ArrayList<>();
            path.add("JFK");

            return path(graph, path, new boolean[T.size()], T.size(), 0);

        }

        private List<String> path(Map<String, List<Ticket>> graph, List<String> path, boolean[] visited, int n, int comp) {
            if (comp == n) return path;
            String last = path.get(path.size() - 1);
            List<String> ans = null;
            for (Ticket next : graph.getOrDefault(last, new ArrayList<>())) {
                if (visited[next.id]) continue;
                List<String> newPath = new ArrayList<>(path);
                newPath.add(next.to);
                visited[next.id] = true;
                List<String> ansPath = path(graph, newPath, visited, n, comp + 1);
                visited[next.id] = false;
                if (ansPath == null) continue;
                ans = ansPath;
                break;
            }
            return ans;
        }
    }
}
