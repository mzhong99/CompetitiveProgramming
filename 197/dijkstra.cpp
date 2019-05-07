#include <bits/stdc++.h>
#define pdi pair<double, int>

using namespace std;

// one-based indexing

int V, E;
const double INF = 1e9;

vector<pair<int, double>>* adj;

int main() {
    
    cin >> V >> E;
    adj = new vector<pair<int, double>>[V + 1];    
    
    for (int e = 0; e < E; e++) {
        
        int a, b;
        double w;
        
        cin >> a >> b >> w;
        
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    
    }

    // used to traverse the graph
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

    // first is distance, second is parent
    pdi* dists = new pdi[V + 1];
    bool* seen = new bool[V + 1];
    
    for (int v = 0; v <= V; v++) {
        
        seen[v] = false;
        dists[v] = make_pair(INF, -1);
        
    }

    // start is at node 1
    // destination is at node V
    int start = 1;
    int destination = V;

    dists[start] = make_pair(0, -1);

    // pair with first = dist (for the priority queue)
    //           second = node label
    pair<double, int> dijkstra_start = make_pair(0, start);
    pq.push(dijkstra_start);

    while (!pq.empty()) {
        
        pair<double, int> current = pq.top();
        pq.pop();

        int current_label = current.second;
        double dist_to_current = current.first;

        if (seen[current_label]) {
            continue;
        }

        for (pair<double, int> neighbor : adj[current_label]) {
            
            int neighbor_label = neighbor.second;
            double neighbor_current_best = dists[neighbor_label].first;
            double delta = neighbor.first;

            if (!seen[neighbor_label]) {
                
                if (dist_to_current + delta < neighbor_current_best) {
                    
                    double neighbor_new_best = dist_to_current + delta;
                    dists[neighbor_label] = make_pair(neighbor_new_best, current_label);
                    pq.push(make_pair(neighbor_new_best, neighbor_label));

                }
                
            }
        
        }

        seen[current_label] = true;

    }

    delete [] adj;
    
    int curr_best_path = dists[destination].second;
    vector<int> path = vector<int>();

    while (curr_best_path != -1) {
        path.push_back(curr_best_path);
        curr_best_path = dists[curr_best_path].second;
    }
    
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        cout << *it << " ";
    }
    
    cout << endl;

}
