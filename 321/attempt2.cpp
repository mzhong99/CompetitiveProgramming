#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, a, b; cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> a; b = a < 0 ? -1 * a : a;
        cout << a << " is " << (b % 2 ? "odd" : "even") << endl;
    }
}
