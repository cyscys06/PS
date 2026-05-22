#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    double lo = -999.0, hi = 999.0;

    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2.0;
        if (a * mid + b > 0)
            hi = mid;
        else
            lo = mid;
    }

    cout << fixed << setprecision(4) << (lo + hi) / 2.0 << endl;
    return 0;
}