import java.util.*;

public class CycleDetection {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int V = in.nextInt();
		int E = in.nextInt();
		ArrayList<Integer>[] adj = (ArrayList<Integer>[]) (new ArrayList[V]);
		for (int i = 0; i < V; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < E; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			adj[a].add(b);
			adj[b].add(a);
		}
		determineCycles(adj);		
	}
	public static void determineCycles(ArrayList<Integer>[] adj) {
		boolean[] inPath = new boolean[adj.length];
		boolean[] visited = new boolean[adj.length];
		if (!isCyclic(adj, 0, inPath, visited)) {
			System.out.println("Good");
		}
		else {
			System.out.println("Bad");
		}
	}
	public static boolean isCyclic(ArrayList<Integer>[] adj, 
		int cursor, 
		boolean[] inPath, 
		boolean[] visited) {
		if (inPath[cursor]) {
			return true;
		}
		else if (visited[cursor]) {
			return false;
		}
		else {
			inPath[cursor] = true;
			visited[cursor] = true;
			for (int neighbor : adj[cursor]) {
				if (isCyclic(adj, cursor, inPath, visited)) {
					return true;
				}
			}
			inPath[cursor] = false;
			return false;
		}
	}
	public static class Pair {
		int first;
		int second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}
