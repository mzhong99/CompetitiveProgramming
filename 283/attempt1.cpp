#include <bits/stdc++.h>


using namespace std;

int W, H;
int start_r, start_c;
int end_r, end_c;

bool** seen;
char** board;
long** dist;

struct Entry {
    
    int row, col;
    long distance;
    
    Entry(long d, int r, int c) {
        row = r;
        col = c;
        distance = d;
    }

    int compare_to(const Entry& rhs) const {
        
        if (distance != rhs.distance) {
            return distance - rhs.distance;
        }
        
        int lhs_index = (row * W) + col;
        int rhs_index = (rhs.row * W) + rhs.col;
        
        return lhs_index - rhs_index;    
    }
};

bool operator<(const Entry& lhs, const Entry& rhs) {
    return lhs.compare_to(rhs) < 0;
}
bool operator==(const Entry& lhs, const Entry& rhs) {
    return lhs.compare_to(rhs) == 0;
}
bool operator>(const Entry& lhs, const Entry& rhs) {
    return lhs.compare_to(rhs) > 0;
}

vector<pair<int, int>>& neighborsOf(int r, int c) {
    vector<pair<int, int>> neigh;
    if (r - 1 >= 0) {
        if (board[r - 1][c] != '#') {
            neigh.push_back(make_pair(r - 1, c));
        }
    } 
    if (r + 1 < H) {
        if (board[r + 1][c] != '#') {
            neigh.push_back(make_pair(r + 1, c));
        }
    } 
    if (c - 1 >= 0) {
        if (board[r][c - 1] != '#') {
            neigh.push_back(make_pair(r, c - 1));
        }
    } 
    if (c + 1 > 0) {
        if (board[r][c + 1] != '#') {
            neigh.push_back(make_pair(r, c + 1));
        }
    }
    return neigh;
}

int main() {
    
    cin >> W >> H;
    
    dist = new long*[H];
    seen = new bool*[H];
    board = new char*[H];
    
    for (int h = 0; h < H; h++) {
        dist[h] = new long[W];
        seen[h] = new bool[W];
        board[h] = new char[W];
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            dist[r][c] = LONG_MAX;
            seen[r][c] = false;
            cin >> board[r][c];
            if (board[r][c] == 's') {
                start_r = r;
                start_c = c;
            }
            if (board[r][c] == 't') {
                end_r = r;
                end_c = c;
            }
        }
    }
    
    dist[start_r][start_c] = 0;
    
    priority_queue<Entry> pq;
    pq.push(Entry(0, start_r, start_c));

    while (!pq.empty()) {
        
        Entry e = pq.top(); pq.pop();

        int curr_row = e.row;
        int curr_col = e.col;

        if (curr_row == end_r and curr_col == end_c) break;
        if (dist[curr_row][curr_col] < e.distance) continue;
        
        vector<pair<int, int>> neighbors = neighborsOf(curr_row, curr_col);

        for (pair<int, int>& coord : neighbors) {
            long uv = 1;
            long heur = abs(curr_row - coord.first) + abs(curr_col - coord.second);
            if (dist[curr_row][curr_col] + uv < dist[coord.first][coord.second]) {
                dist[coord.first][coord.second] = dist[curr_row][curr_col] + uv;
                pq.push(Entry(heur + dist[coord.first][coord.second], coord.first, coord.second));
            }
        }
    }

    cout << dist[end_r][end_c] << endl;
}

    
