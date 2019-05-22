#include <bits/stdc++.h>
using namespace std;

int main() {
    double N, L, R, M; cin >> N;
    L = 0; R = N;
    while (R - L > 1e-7) {
        M = L + (R - L) * 0.5;
        if (M * log2(M) < N) L = M + 1e-7;
        else                 R = M - 1e-7;
    }
    cout << M << endl;
    return 0;
}
