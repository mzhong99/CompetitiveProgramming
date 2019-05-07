#include <bits/stdc++.h>
using namespace std;

int N;

void solve(int n = N, char start = 'A', char helper = 'B', char goal = 'C') {
    if (n > 1) solve(n - 1, start, goal, helper);
    printf("%c -> %c\n", start, goal);
    if (n > 1) solve(n - 1, helper, start, goal);
}

int main() {
    cin >> N;
    solve();
}
    
