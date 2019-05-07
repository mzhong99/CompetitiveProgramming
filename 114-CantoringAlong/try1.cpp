#include <bits/stdc++.h>
using namespace std;

char* working;
long start = 0;
long finish;

void solve(long s = start, long f = finish) {
    if (f - s == 3) {
        return;
    }
    long div = (f - s) / 3;
    for (long i = start + div; i < finish; i += div) {
        working[i] = ' ';
    }
    solve(s, div);
    solve(s + (2 * div), f);
}
int main() {
    long L;
    while(cin >> L) {
        working = new char[(long)pow(3, L)];
        cout << finish << endl;
        finish = pow(3, L);
        for (long l = 0; l < finish; l++) {
            working[l] = '-';
        }
        cout << working << endl;
        delete [] working;
    }
}
