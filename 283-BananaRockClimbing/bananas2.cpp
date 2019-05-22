#include <bits/stdc++.h>
using namespace std;

struct Point {
    int r, c, w;
    Point(int _r = 0, int _c = 0, int _w = 0) {
        r = _r;
        c = _c;
        w = _w;
    }
    Point up() {
        return Point(r - 1, c, w + 1);
    }
    Point down() {
        return Point(r + 1, c, w + 1);
    }
    Point left() {
        return Point(r, c - 1, w + 1);
    }
    Point right() {
        return Point(r, c + 1, w + 1);
    }
    bool operator==(const Point& rhs) {
        return r == rhs.r and c == rhs.c;
    }
    bool operator<(const Point& rhs) {
        return w > rhs.w;
    }
}

vector<vector<int >> dist;
vector<vector<char>> board;
int R, C;
Point S, T;

bool is_ready(Point p) {
    return p.r >= 0 and p.r < R and
           p.c >= 0 and p.c < C and
           (board[p.r][p.c] == 't' or board[p.r][p.c] == '.');
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        board.push_back(vector<char>(C));
        dist.push_back(vector<int>(C));
        for (int c = 0; c < C; c++) {
            dist[r][c] = INT_MAX;
            char ch; cin >> ch;
            board[r][c] = ch;
            if (ch == 's') {
                S = Point(r, c, 0);
                seen[r][c] = true;
                dist[r][c] = 0;
            }
            if (ch == 't') {
                T = Point(r, c, 0);
            }
        }
    }
    priority_queue<Point> pq; 
    pq.push(S);
    while (!pq.empty()) {
        Point cursor = pq.top(); pq.pop();
        if (cursor == T) break;
        vector<Point> neighbors = {
            cursor.up(), 
            cursor.down(), 
            cursor.left(), 
            cursor.right()
        };
        for (Point n : neighbors) {
            if (is_ready(n)) {
                if (dist[n.r][n.c] > n.w) {
                    dist[n.r][n.c] = n.w;
                    pq.push(n);
                }
            }
        }
    }
    cout << dist[T.r][T.c] << endl;
}
