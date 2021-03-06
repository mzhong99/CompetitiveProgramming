#include <bits/stdc++.h>
using namespace std;
int main() {
	int V, E;
	cin >> V >> E;
	unordered_map<string, int> name_to_idx = unordered_map<string, int>();
	string* idx_to_name = new string[V];
	string name;
	for (int v = 0; v < V; v++) {
		cin >> name;
		name_to_idx[name] = v;
		idx_to_name[v] = name;
	}
	string name1, name2;
	vector<int>* neighbors = new vector<int>[V];
	for (int e = 0; e < E; e++) {
		cin >> name1 >> name2;
		int name1_idx = name_to_idx[name1];
		int name2_idx = name_to_idx[name2];
		neighbors[name1_idx].push_back(name2_idx);
		neighbors[name2_idx].push_back(name1_idx);
	}
	vector<int> nearest_group = vector<int>();
	stack<int> dfs = stack<int>();
	string start;
	cin >> start;
	int start_idx = name_to_idx[start];
	dfs.push(start_idx);
	unordered_set<int> seen = unordered_set<int>();
	seen.insert(start_idx);
	while (!dfs.empty()) {
		int curr = dfs.top();
		cout << idx_to_name[curr] << endl;
		dfs.pop();
		for (int neighbor : neighbors[curr]) {
			if (seen.find(neighbor) == seen.end()) {
				seen.insert(neighbor);
				dfs.push(neighbor);
			}
		}
	}
	if (seen.size() == 1) {
		cout << "none" << endl;
	}
	else {
		for (int possible : seen) {
			if (possible != start_idx) {
				cout << idx_to_name[possible] << endl;
			}
		}
	}
}
