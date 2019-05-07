#include <bits/stdc++.h>
using namespace std;

int main() {
    double B, D, sl, sr, sm, V, d, t, s;
    cin >> B >> D;
    sl = 0; sr = 1e9;
    t = sqrt(2 * B / 9.81);
    while (sr - sl > 1e-10) {
        sm = sl + (0.5 * (sr - sl));
        V = (2 * pow(sm, 5)) + (3 * pow(sm, 4)) + sm;
        d = V * t;
        if (d < D) sl = sm + 1e-9;
        else       sr = sm - 1e-9;
    }
    cout << sm << endl;
}
