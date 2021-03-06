#include <bits/stdc++.h>
using namespace std;

struct edge {
	
	int p1;
	int p2;
	int length;
	
	edge(int p1, int p2, int length) {
		this->p1 = p1;
		this->p2 = p2;
		this->length = length;
	}

	edge() {
		p1 = -1;
		p2 = -1;
		length = -1;
	}

	bool operator==(edge &other) {
		return this->length == other.length;
	}

	bool operator>(edge &other) {
		return this->length > other.length;
	}

	bool operator<(edge &other) {
		return this->length < other.length;
	}

};

int main() {
	
	int V, E;
	cin >> V >> E;

	vector<edge> edges = vector<edge>();
	
	int p1, p2, length;
	
	for (int e = 0; e < E; e++) {
		cin >> p1 >> p2 >> length;
		edges.push_back(edge(p1, p2, length));
	}

	int* vertex_sets = new int[V];
	vector<edge> mst = vector<edge>();
	
	for (int v = 0; v < V; v++) {
		vertex_sets[v] = v; // all start in their own set
	}
	
	sort(edges.begin(), edges.end());
	// for (edge ed : edges) {
	// 	cout << ed.p1 << " " << ed.p2 << " " << ed.length << endl;
	// }

	bool* is_in_set = new bool[V];
	for (int v = 0; v < V; v++) {
		is_in_set[v] = false;
	}

	unordered_set<int> seen = unordered_set<int>();

	for (edge ed : edges) {
		
		if (vertex_sets[ed.p1] == vertex_sets[ed.p2]) {
			continue;
		}
		else {
			mst.push_back(ed);
			seen.insert(ed.p1);
			seen.insert(ed.p2);
			int old_set = vertex_sets[ed.p2];
			vertex_sets[ed.p2] = vertex_sets[ed.p1];
			for (int v = 0; v < V; v++) {
				if (vertex_sets[v] == old_set) {
					vertex_sets[v] = vertex_sets[ed.p1];
				}
			}
		}
	}

	if (seen.size() != V) {
		cout << "not possible" << endl;
	}

	long mst_length = 0;
	for (edge &ed : mst) {
		mst_length += (long) ed.length;
	}
	cout << mst_length << endl;

	delete [] is_in_set;

}
