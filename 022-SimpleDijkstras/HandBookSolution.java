import java.util.*;

public class HandBookSolution {
    
    static final long INF = Long.MAX_VALUE;
    
    static class Entry implements Comparable {
        
        public int index;
        public long distance;
        
        public Entry(long d, int i) {
            distance = d;
            index = i;
        }

        public int compareTo(Object o) {
            
            Entry e = (Entry)o;
            
            if (distance != e.distance) {
                return (int)(distance - e.distance);
            }

            return index - e.index;
        }
    }

    static class Edge {
        
        public int index;
        public long length;
        
        public Edge(int i, long l) {
            index = i;
            length = l;
        }
    }

    static ArrayList<Edge> adj[];

    static void dijkstra(int N, int start, int goal) {
        
        final long dist[] = new long[N];
        Arrays.fill(dist, INF);
        
        dist[start] = 0;
        
        int prev[] = new int[N];
        
        Queue<Entry> frontier = new PriorityQueue<Entry>(dist.length);
        frontier.offer(new Entry(0, start));
        
        while (!frontier.isEmpty()) {
            
            Entry e = frontier.poll();
            int u = e.index;

            if (u == goal) {
                break;
            }

            if (dist[u] < e.distance) {
                continue;
            }

            for (Edge edge : adj[u]) {

                long uv = edge.length;
                int v = edge.index;

                if (dist[u] + uv < dist[v]) {

                    prev[v] = u;
                    dist[v] = dist[u] + uv;
                    frontier.offer(new Entry(dist[v], v));
                
                }
            }
        }

        System.out.println(dist[goal]);

    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        
        int N = in.nextInt();
        int E = in.nextInt();
        int S = in.nextInt();
        int T = in.nextInt();
        
        adj = (ArrayList<Edge>[])new ArrayList[N];
        
        for (int n = 0; n < N; n++) {
            adj[n] = new ArrayList<Edge>();
        }

        for (int e = 0; e < E; e++) {
            
            int a = in.nextInt();
            int b = in.nextInt();
            long w = (long)in.nextInt();
            
            adj[a].add(new Edge(b, w));
            adj[b].add(new Edge(a, w));

        }

        dijkstra(N, S, T);
    }
}
