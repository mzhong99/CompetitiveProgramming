#include <bits/stdc++.h>
using namespace std;

int V, E;
struct edge {
    int end1, end2, length;
    edge(int e1, int e2, int l) {
        end1 = e1;
        end2 = e2;
        length = l;
    }
    bool operator==(edge& other) {
        return other.length == length;
    }
    bool operator>(edge& other) {
        return length > other.length;
    }
    bool operator<(edge& other) {
        return length < other.length;
    }
};
int main() {
    cin >> V >> E;
    vector<edge> edges = vector<edge>();
    for (int e = 0; e < E; e++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(edge(a, b, w));
    }
    sort(edges.begin(), edges.end());
    int* groups = new int[V];
    for (int v = 0; v < V; v++) {
        groups[v] = v;
    }
    int mst = 0;
    for (edge& ed : edges) {
        // for (int v = 0; v < V; v++) {
        //     cout << groups[v] << " ";
        // }
        // cout << mst << endl;
        // edge ed = edges[e];
        if (groups[ed.end1] == groups[ed.end2]) {
            continue;
        }
        else {
            int old_group = groups[ed.end2];
            int new_group = groups[ed.end1];
            groups[ed.end2] = groups[ed.end1];
            for (int v = 0; v < V; v++) {
                if (groups[v] == old_group) {
                    groups[v] = new_group;
                }
            }
            mst += ed.length;
        }
    }
    cout << mst << endl;
    delete [] groups;
}
