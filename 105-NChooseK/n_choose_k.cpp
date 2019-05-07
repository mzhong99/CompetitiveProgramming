#include <bits/stdc++.h>
using namespace std;

int K, M, N;
int num_used = 0;
string letters;
vector<char> result;
bool used[26];
void solve() {
    if (result.size() == K) {
        if (M == 0) {
            for (char c : result) {
                cout << c;
            }
            exit(0);
        }
        else {
            M--;
        }
    }
    else {
        for (int n = 0; n < N; n++) {
            if (used[n]) {
                continue;
            }
            else {
                used[n] = true;
                result.push_back(letters[n]);
                solve();
                result.pop_back();
                used[n] = false;
            }
        }
    }
}
int main() {
    cin >> letters >> K >> M;
    N = letters.length();
    sort(letters.begin(), letters.end());
    solve();
}
