#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int k, n;
        cin >> k >> n;
        int apart[k + 1][n + 1];
        for (int i = 1; i < n + 1; i++) {
            apart[0][i] = i;
        }
        for (int i = 0; i < k + 1; i++) {
            apart[i][0] = 0;
        }
        
        for (int i = 1; i < k + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
            }
        }

        cout << apart[k][n] <<'\n';
    }
    return 0;
}