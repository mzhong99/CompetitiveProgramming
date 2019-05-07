import java.util.*;
// trying to learn kruskals from handbook here
// matthew zhong
public class RoadwayCameras {
	static class Edge {
		int p1, p2;
		double l;
		Edge(int p1, int p2, double l) {
			this.p1 = p1;
			this.p2 = p2;
			this.l = l;
		}
	}
	static double solve(int V, Edge[] edges) {
		// sort by decreasing length
		Arrays.sort(edges, new Comparator<Edge>() {
			public int compare(Edge e1, Edge e2) {
				return (int) Math.signum(e1.l - e2.l);
			}
		});
		int c[] = new int[V];
		for (int i = 0; i < c.length; i++) {
			c[i] = i;
		}
		double len = 0;
		// greedy algorithm unions by picking shortest lengths first
		for (int i = 0; i < edges.length; i++) {
			Edge e = edges[i];
			if (c[e.p1] != c[e.p2]) {  // if edges are in different clusters
				len += e.l;        // add to min spanning length
				int c2 = c[e.p2];  // union the clusters
				for (int j = 0; j < c.length; j++) {
					if (c[j] == c2) {
						c[j] = c[e.p1];
					}
				}
			}
		}
		return len;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int E = in.nextInt();
		Edge[] edges = new Edge[E];
		for (int i = 0; i < E; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int l = in.nextInt();
			edges[i] = new Edge(a, b, l);
		}
		System.out.println(solve(N, edges));
	}
}

