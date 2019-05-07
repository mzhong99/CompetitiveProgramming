import java.util.*;

public class breadfirst {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		int E = in.nextInt();
		int S = in.nextInt();
		int B = in.nextInt();
		
		ArrayList<Integer> adj[] = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			adj[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < E; i++) {
			int a = in.nextInt();
	 		int b = in.nextInt();
			adj[a].add(b);
			adj[b].add(a);
		}

		ArrayDeque<Integer> queue = new ArrayDeque<Integer>();
		queue.add(S);
		
		boolean seen[] = new boolean[N];
		for (int i = 0; i < N; i++) {
			seen[i] = false;
		}

		int dists[] = new int[N];
		
		seen[S] = true;
		dists[S] = 0;

		while (queue.size() != 0) {
			int cursor = queue.poll();
			if (cursor == B) {
				break;
			}
			for (int neigh : adj[cursor]) {
				if (!seen[neigh]) {
					seen[neigh] = true;
					dists[neigh] = dists[cursor] + 1;
					queue.add(neigh);
				}
			}
		}
		System.out.printf("%d %d\n", (dists[B] % 6 != 0 ? 1 : 0) + (dists[B] / 6), dists[B]); 
	}
}
