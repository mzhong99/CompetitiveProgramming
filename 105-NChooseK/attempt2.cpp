#include <bits/stdc++.h>
using namespace std;

void solve(int idx);

string s;
int N, M, K;
int m = 1;
vector<char> stk;
int main() {
    cin >> s >> K >> M;
    N = s.length();
    sort(s.begin(), s.end());
    solve(0);
}
void solve(int idx) {
    if (stk.size() == K) {
        if (++m > M) {
            for (char c : stk) {
                cout << c;
            }
            cout << endl;
            exit(0);
        }
    }
    else {
        for (int i = idx; i < s.length(); i++) {
            stk.push_back(s[i]);
            solve(i + 1);
            stk.pop_back();
        }
    }
}
