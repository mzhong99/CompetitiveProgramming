#include <bits/stdc++.h>
using namespace std;

int P, C;
vector<unordered_set<int>> connections;
vector<pair<int, int>> edges;

bool FloodFill() {
    unordered_set<int> seen;
    stack<int> dfs;
    seen.insert(1);
    dfs.push(1);
    while (!dfs.empty()) {
        int p = dfs.top(); dfs.pop();
        for (int neighbor : connections[p]) {
            if (seen.find(neighbor) == seen.end()) {
                dfs.push(neighbor);
                seen.insert(neighbor);
            }
        }
    }
    return seen.size() == P;
}

void SolveOnce() {
    connections = vector<unordered_set<int>>(P + 1);
    edges = vector<pair<int, int>>(C);
    for (int c = 0; c < C; c++) {
        int a, b; cin >> a >> b;
        connections[a].insert(b);
        connections[b].insert(a);
        edges.push_back({a, b});
    }
    for (pair<int, int>& edge : edges) {
        connections[edge.first].erase(edge.second);
        connections[edge.second].erase(edge.first);
        if (!FloodFill()) {
            cout << "Yes" << endl;
            return;
        }
        connections[edge.first].insert(edge.second);
        connections[edge.second].insert(edge.first);
    }
    cout << "No" << endl;
}

int main() {
    cin >> P >> C;
    while (P != 0 && C != 0) {
        SolveOnce();
        cin >> P >> C;
    }
    return 0;
}
