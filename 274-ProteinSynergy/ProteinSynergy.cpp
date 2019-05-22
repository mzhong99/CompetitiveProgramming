#include <bits/stdc++.h>
using namespace std;

int E, Q;
unordered_map<string, vector<pair<string, int>>> adj;
vector<string> queries;

void Build() {
    cin >> E >> Q;
    for (int e = 0; e < E; e++) {
        string a, b; cin >> a >> b;
        int cost; cin >> cost;
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }
    for (int q = 0; q < Q; q++) {
        string query; cin >> query;
        queries.push_back(query);
    }
}

void SolveOnce(string& startProteinKey) {
    priority_queue<pair<int, string>> frontier;
    unordered_map<string, int> costToReach;
    unordered_set<string> seen;

    frontier.push({0, startProteinKey});
    
    while (!frontier.empty()) {
        pair<int, string> curr = frontier.top(); frontier.pop();
        int costSoFar = curr.first * -1;
        string proteinKey = curr.second;
        
        if (seen.find(proteinKey) == seen.end()) {
            seen.insert(proteinKey);
            cout << proteinKey << " ";
        }
        else {
            continue;
        }

        for (pair<string, int>& neighbor : adj[proteinKey]) {
            string neighborKey = neighbor.first;
            int neighborCost = neighbor.second;
            if (costToReach.find(neighborKey) == costToReach.end()) {
                costToReach[neighborKey] = neighborCost + costSoFar;
                frontier.push({-1 * costToReach[neighborKey], neighborKey});
            }
            else if (neighborCost + costSoFar < costToReach[neighborKey]) {
                costToReach[neighborKey] = neighborCost + costSoFar;
                frontier.push({-1 * costToReach[neighborKey], neighborKey});
            }
        }
    }

    cout << endl;
}

void Solve() {
    for (string& protein : queries) {
        SolveOnce(protein);
    }
}

int main() {
    Build();
    Solve();
    return 0;
}
