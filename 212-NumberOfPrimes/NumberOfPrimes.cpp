#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    bool sieve[N + 1];
    for (int n = 0; n <= N; n++) {
        sieve[n] = true;
    }
    sieve[0] = false;
    sieve[1] = false;
    for (int n = 2; n <= N; n++) {
        if (sieve[n]) {
            for (int multiple = 2; multiple * n <= N; multiple++) {
                sieve[multiple * n] = false;
            }
        }
    }
    int num_primes = 0;
    for (int n = 0; n <= N; n++) {
        num_primes += sieve[n];
    }
    cout << num_primes << endl;
    return 0;
}
