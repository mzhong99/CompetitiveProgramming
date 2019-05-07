#include <bits/stdc++.h>
using namespace std;

int R, C;
int** board;

void Build() {
    cin >> R >> C;
    board = new int*[R];
    for (int r = 0; r < R; r++) {
        board[r] = new int[C];
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
        }
    }
}

void FloodFill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) {
        return;
    }
    if (board[r][c] == 0) {
        return;
    }
    board[r][c] = 0;
    FloodFill(r - 1, c);
    FloodFill(r + 1, c);
    FloodFill(r, c - 1);
    FloodFill(r, c + 1);
}

void Solve() {
    int total = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == 1) {
                total++;
                FloodFill(r, c);
            }
        }
    }
    cout << total << endl;
}

int main() {
    Build();
    Solve();
    return 0;
}
