#include <bits/stdc++.h>
using namespace std;

double B, D;

double VelocityFunction(double takeoffDistance) {
    return (2 * pow(takeoffDistance, 5)) + (3 * pow(takeoffDistance, 4)) + takeoffDistance;
}

double DistanceCovered(double takeoffVelocity) {
    double T = sqrt(2.0 * B / 9.81);
    double distance = takeoffVelocity * T;
    return distance;
}

int main() {
    cin >> B >> D;
    double low = 0;
    double high = D;
    double mid = low + (high - low) * 0.5;
    for (int i = 0; i < 50000; i++) {
        mid = low + (high - low) * 0.5;
        double distance = DistanceCovered(VelocityFunction(mid));
        if (distance > D) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    cout.precision(11);
    cout << mid << endl;
    return 0;
}
