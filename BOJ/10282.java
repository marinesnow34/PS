import java.util.*;
import java.io.*;

public class Main {
    static class Node {
        int cost, vertex;
        Node(int cost, int vertex) {
            this.cost = cost;
            this.vertex = vertex;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            List<List<Node>> cpus = new ArrayList<>(n + 1);
            for (int i = 0; i <= n; i++) {
                cpus.add(new ArrayList<>());
            }

            for (int i = 0; i < d; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int s = Integer.parseInt(st.nextToken());
                cpus.get(b).add(new Node(s, a));
            }

            int[] visit = new int[n + 1];
            Arrays.fill(visit, Integer.MAX_VALUE);

            Queue<Node> q = new PriorityQueue<>(Comparator.comparingInt(node -> node.cost));
            q.add(new Node(0, c));
            visit[c] = 0;

            int cnt = 0, max = 0;

            while (!q.isEmpty()) {
                Node now = q.poll();

                if (visit[now.vertex] < now.cost) continue;

                cnt++;
                max = now.cost;

                for (Node next : cpus.get(now.vertex)) {
                    int newCost = now.cost + next.cost;
                    if (visit[next.vertex] > newCost) {
                        visit[next.vertex] = newCost;
                        q.add(new Node(newCost, next.vertex));
                    }
                }
            }
            pw.printf("%d %d\n", cnt, max);
        }

        br.close();
        pw.flush();
        pw.close();
    }
}
