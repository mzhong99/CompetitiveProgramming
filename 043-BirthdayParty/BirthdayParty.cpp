#include <bits/stdc++.h>
using namespace std;

int P, C;
vector<vector<int>> connections;

void BuildOnce() {
    connections = vector<vector<int>>(P + 1);
    for (int c = 0; c < C; c++) {
        int a, b; cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
}

void SolveOnce() {
    for (int p = 1; p <= P; p++) {
        if (connections[p].size() == 1) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    cin >> P >> C;
    while (P != 0 && C != 0) {
        BuildOnce();
        SolveOnce();
        cin >> P >> C;
    }
}
