#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, answer = 0; // 물품 개수, 가방에 담을수있는 최대 무게, 물품의 무게, 물품의 가치, 정답
    cin >> N >> K;

    // 모든 인덱스는 1 기반 인덱스로 설정
    vector<pair<int, int>> item(N + 1); // 저장용 벡터
    vector<vector<int>> DP(N + 1, vector<int>(K + 1, 0)); // 기록용 벡터
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i].first >> item[i].second;
    }

    for (int i = 1; i <= N; i++) // 1번부터 N번까지의 물품
    {
        for (int j = 1; j <= K; j++) // 가방 무게의 경우의수 1부터 K까지에 대한 최적의 물품 가치
        {
            if (j >= item[i].first) // 무게가 j인 가방에 i번째 물품을 담을수 있으면
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - item[i].first] + item[i].second); // 왼쪽: 물건을 담지 않았을때의  오른쪽: 물건을 담는다(둘중 가치가 더 높은 선택을 함)
            }
            else // 물품 못담으면
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
        
    }
    
    answer = DP[N][K];
    cout << answer;
    return 0;
}