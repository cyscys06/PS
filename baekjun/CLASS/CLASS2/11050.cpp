#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // 처음은 0으로 초기화

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (i == j || j == 0) {
                dp[i][j] = 1;
            }
            if (i > 0 && j > 0) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    cout << dp[n][r];
    return 0;
}