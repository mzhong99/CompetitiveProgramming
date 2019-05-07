#include <bits/stdc++.h>
using namespace std;

int main() {
    double N; cin >> N;
    double L, R, M;
    L = 0; R = N;
    while (R - L > 1e-9) {
        M = L + (R - L) * 0.5;
        if   (M * M < N) L = M + 1e-9;
        else             R = M - 1e-9;
    }
    cout << L << endl;
    return 0;
}
