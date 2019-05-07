#include <bits/stdc++.h>
using namespace std;

int N, Q;
unordered_map<string, vector<string>> adj;
vector<string> queries;

void Build() {
    for (int n = 0; n < N; n++) {
        string p1, p2; cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }
    for (int q = 0; q < Q; q++) {
        string query; cin >> query;
        queries.push_back(query);
    }
}

void SolveOnce(string& start_query) {
    map<int, set<string>> tree;
    unordered_set<string> seen;
    
    queue<pair<int, string>> frontier;
    frontier.push({0, start_query});
    seen.insert(start_query);
    tree[0].insert(start_query);

    while (!frontier.empty()) {
        pair<int, string> curr = frontier.front(); frontier.pop();
        int dist = curr.first;
        string query = curr.second;
        for (string& neighbor : adj[query]) {
            if (seen.find(neighbor) == seen.end()) {
                seen.insert(neighbor);
                tree[dist + 1].insert(neighbor);
                frontier.push({dist + 1, neighbor});
            }
        }
    }

    for (auto it = tree.begin(); it != tree.end(); it++) {
        if (it->first > 0) {
            cout << it->first << " ";
        }
        for (string probe : it->second) {
            cout << probe << " ";
        }
        cout << endl;
    }
}

void Solve() {
    for (int q = 0; q < Q; q++) {
        SolveOnce(queries[q]);
    }
}

int main() {
    cin >> N >> Q;
    Build();
    Solve();
    return 0;
}
