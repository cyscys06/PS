#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, answer = 0;
    cin >> N;
    vector<int> sequence(N); // 전체 수열 저장할 벡터
    vector<int> DP(N, 1); // 수열 속 숫자별로 가지는 최적인 최장 부분수열 길이를 저장할 별도의 벡터

    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence[j] < sequence[i])
            {
                DP[i] = max(DP[i], DP[j] + 1); // 지금 갖고있는 최장 부분수열 길이와 이전 숫자중 최장 부분수열 길이를 비교해 더 큰값으로 갱신
            }
        }
        answer = max(answer, DP[i]); // 실시간으로 정답 갱신
    }

    cout << answer;
    return 0;
}