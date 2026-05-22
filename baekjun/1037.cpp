#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num, min = INT_MAX, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }
    cout << min * max;

    return 0;
}