#include <bits/stdc++.h>
using namespace std;
struct edge {
	int p1, p2;
	double l;
	edge(int p1, int p2, double l) {
		this->p1 = p2;
		this->p2 = p2;
		this->l = l;
	}
	bool operator<(edge &rhs) {
		return rhs.l - this->l < 0;
	}
	bool operator==(edge &rhs) {
		return abs(rhs.l - this->l) < 0.000001;
	}
	bool operator>(edge &rhs) {
		return rhs.l - this->l > 0;
	}
};
double solve(int V, vector<edge> &edges) {
	sort(edges.rbegin(), edges.rend());
	int* c = new int[V];
	for (int i = 0; i < V; i++) {
		c[i] = i;
	}
	double len = 0;
	for (int i = 0; i < edges.size(); i++) {
		edge e = edges[i];
		if (c[e.p1] != c[e.p2]) {             // if p1 and p2 are in different clusters
			cout << "here" << endl;
			len = e.l;
			int c2 = c[e.p2];             // union p1 and p2 into same cluster
			for (int j = 0; j < V; j++) { // union all others originally connected to p2
				if (c[j] == c2) {
					c[j] = c[e.p1];
				}
			}
		}
	}
	delete [] c;
	return len;
}
int main() {
	int V, E;
	cin >> V >> E;
	vector<edge> edges = vector<edge>();
	for (int e = 0; e < E; e++) {
		int p1, p2;
		double l;
		cin >> p1 >> p2 >> l;
		edges.push_back(edge(p1, p2, l));
	}
	for (int e = 0; e < E; e++) {
		cout << e << ": " << edges[e].p1 << " " << edges[e].p2 << " " << edges[e].l << endl;
	}
	cout << solve(V, edges) << endl;
}
