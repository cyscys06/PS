#include <bits/stdc++.h>
using namespace std;

int arr[20000002];
const int COR = 10000001;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, num;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num + COR]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << arr[num + COR] << " ";
    }

    return 0;
}