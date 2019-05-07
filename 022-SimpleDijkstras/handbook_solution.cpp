#include <bits/stdc++.h>
using std::vector;
using std::priority_queue;
using std::cin;
using std::cout;
using std::endl;
using std::set;

struct MyEntry {
    int index;
    long distance;
    MyEntry(long d, int i) {
        index = i;
        distance = d;
    }
    bool operator==(MyEntry &other) {
        return distance == other.distance && index == other.index;
    }
    bool operator>(MyEntry &other) {
        if (distance != other.distance) {
            return distance > other.distance;
        }
        return index > other.index;
    }
    bool operator<(MyEntry &other) {
        if (distance != other.distance) {
            return distance < other.distance;
        }
        return index < other.index;
    }
};

struct MyEdge {
    int index;
    long length;
    MyEdge(int i, long l) {
        index = i;
        length = l;
    }
};

int N, E, S, T;
const long INF = LONG_MAX;
vector<vector<MyEdge>> adj;

void dijkstra() {
    
    long* dist = new long[N];
    
    for (int n = 0; n < N; n++) {
        dist[n] = INF;
    }
    
    dist[S] = 0;
    
    int* prev = new int[N];

    set<MyEntry> frontier = set<MyEntry>();
    frontier.insert(MyEntry(0, S));

    while (!frontier.empty()) {

        MyEntry e = *frontier.begin();
        frontier.erase(e);

        int u = e.index;

        if (u == T) {
            break;
        }

        if (dist[u] < e.distance) {
            continue;
        }

        for (int e = 0; e < adj[u].size(); e++) {
            
            MyEdge edge = adj[u][e];
            
            int v = edge.index;
            long delta = edge.length;

            if (dist[u] + delta < dist[v]) {
                prev[v] = u;
                dist[v] = dist[u] + delta;
                frontier.insert(MyEntry(dist[v], v));
            }
        }
    }

    cout << dist[T] << endl;

    delete [] dist;
    delete [] prev;

}

int main() {
    
    cin >> N >> E >> S >> T;
    
    for (int n = 0; n < N; n++) {
        adj.push_back(vector<MyEdge>());
    }
    
    for (int e = 0; e < E; e++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(MyEdge(b, w));
        adj[b].push_back(MyEdge(a, w));
    }

    dijkstra();

}
