#include <bits/stdc++.h>
using namespace std;

int N, K;
int maxWordLength = 0;

vector<string> board;
unordered_set<string> words;

string frontier;

void Build();
void Solve();
void BackTrack(int r, int c);

void Build() {
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        string line; cin >> line;
        board.push_back(line);
    }
    for (int k = 0; k < K; k++) {
        string line; cin >> line;
        words.insert(line);
        maxWordLength = max(maxWordLength, (int)line.length());
    }
}

void BackTrack(int r, int c) {
    if (r >= N || c >= N || frontier.length() > maxWordLength) {
        return;
    }
    frontier.push_back(board[r][c]);
    if (words.find(frontier) != words.end()) {
        words.erase(frontier);
    }
    BackTrack(r + 1, c);
    BackTrack(r, c + 1);
    frontier.pop_back();
}

void Solve() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            BackTrack(r, c);
            if (words.empty()) {
                cout << "yes" << endl;
                return;
            }
        }
    }
    cout << "no" << endl;
}

int main() {
    Build();
    Solve();
    return 0;
}
