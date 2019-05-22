#include <bits/stdc++.h>
using namespace std;

struct Trapezoid {
    int m_b1;
    int m_b2;
    int m_height;
    Trapezoid(int b1, int b2, int height) {
        m_b1 = b1;
        m_b2 = b2;
        m_height = height;
    }
    long long cost() {
        return (m_b1 + m_b2) * m_height; // 2 cents per trapezoid, so *2 /2
    }
};

void PrintAdjacency(unordered_map<int, vector<Trapezoid>>& adj) {
    cout << "{" << endl;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        cout << "    [ ";
        for (Trapezoid& trapezoid : it->second) {
            cout << "{" << trapezoid.m_b1 << ", " << trapezoid.m_b2 << ", " << trapezoid.m_height << "} ";
        }
        cout << "]" << endl;
    }
    cout << "}" << endl;
}

void Solve(int N) {
    vector<Trapezoid> trapezoids;
    unordered_map<int, vector<Trapezoid>> adj;
    unordered_map<int, long long> costs;
    for (int n = 0; n < N; n++) {
        int b1, b2, height; cin >> b1 >> b2 >> height;
        trapezoids.push_back(Trapezoid(b1, b2, height));
        trapezoids.push_back(Trapezoid(b2, b1, height));
    }
    for (int i = 0; i < trapezoids.size(); i++) {
        for (int j = i + 1; j < trapezoids.size(); j++) {
            int b1 = trapezoids[i].m_b2;
            int b2 = trapezoids[j].m_b1;
            Trapezoid next_trapezoid = trapezoids[j];
            if (b1 == b2) {
                adj[b2].push_back(next_trapezoid);
            }
        }
    }
    // PrintAdjacency(adj);
    int S, G; cin >> S >> G;
    priority_queue<pair<long long, int>> frontier;
    frontier.push({0, S});
    costs[S] = 0;
    while (!frontier.empty()) {
        pair<long long, int> curr = frontier.top(); frontier.pop();
        long long cumulative_cost = -1 * curr.first;
        int far_edge = curr.second;
        if (far_edge == G) {
            break;
        }
        for (Trapezoid& neighbor : adj[far_edge]) {
            long long potential_cost = cumulative_cost + neighbor.cost();
            if (costs.find(neighbor.m_b2) == costs.end()) {
                costs[neighbor.m_b2] = potential_cost;
                frontier.push({-1 * (potential_cost), neighbor.m_b2});
            }
            else if (costs[neighbor.m_b2] > potential_cost) {
                costs[neighbor.m_b2] = potential_cost;
                frontier.push({-1 * (potential_cost), neighbor.m_b2});
            }
        }
    }
    cout << setfill(' ') << costs[G] / 100 << "." << setw(2) << setfill('0') << costs[G] % 100 << endl;
}

int main() {
    int N; cin >> N;
    while (N != 0) {
        Solve(N);
        cin >> N;
    }
    return 0;
}
