#include <bits/stdc++.h>
using namespace std;

// approach this problem instead as a DAG,
// such that goal state has no edges pointing away from it

int S;
vector<int> adj[101];
vector<int> frontier;

void Build() {
    int A; cin >> S >> A;
    while (A != -1) {
        string line; getline(cin, line);
        stringstream ss; ss << line;
        int B; ss >> B;
        while (!ss.fail()) {
            adj[B].push_back(A);
            ss >> B;
        }
        cin >> A;
    }
    frontier.push_back(S);
}

bool Solve() {
    if (adj[frontier.back()].empty()) {
        for (int node : frontier) {
            cout << node << " ";
        }
        cout << endl;
        return true;
    }
    for (int neighbor : adj[frontier.back()]) {
        frontier.push_back(neighbor);
        if (Solve()) {
            return true;
        }
        frontier.pop_back();
    }
    return false;
}

int main() {
    Build();
    Solve();
    return 0;
}
