#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 속도 빨라짐
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X;
    cin >> X;

    int dp[X + 1] = {0, };

    for (int i = 2; i <= X; i++) // 정수 0, 1은 최소연산횟수 0이므로 루프에서 제외
    {
        dp[i] = dp[i - 1] + 1; // -1 연산(기본)
        if (i % 2 == 0) // 나누기 2 연산
        {
            dp[i] = min(dp[i], dp[i / 2] + 1); // 둘중 작은걸 값으로 가짐
        }
        
        if (i % 3 == 0) // 나누기 3 연산
        {
            dp[i] = min(dp[i], dp[i / 3] + 1); // 둘중 작은걸 값으로 가짐
        }
    }
    
    cout << dp[X];
    return 0;
}