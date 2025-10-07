#include <bits/stdc++.h>
using namespace std;

// n(Sk)^c = 집합 Sk의 여집합 중 판정된 숫자의 개수. 즉 판정받은 숫자는 서열을 새로받은 것을 의미
// (판정: 여집합의 원소들 중 Sk집합의 특정 원소를 기준으로 그 원소보다 작은 숫자들)
// n(RSk) = k번 그룹의 판정된 숫자의 개수들
// WS = 모든 n(RSk)의 합(즉 모든 그룹의 판정된 숫자의 개수들의 총합)

int main()
{
    int N, K, x; // 총 숫자 개수, 집합 개수, 숫자 
    int t = 0, rk = 0; // 입력을 구분하기 위한 변수 t
    int a;

    cin >> N >> K;

    int p[K]; // 집합별 숫자 개수
    vector<pair<int, int>> S(N); // Ck(새로 받은 서열), Sk(그룹 구분용). 1차원 벡터이므로 모든 숫자를 저장해야 함

    for (int i = 0; i < K; i++)
    {
        cin >> p[i];

        for (int j = 0; j < p; j++)
        {
            cin >> x;
            S[t] = {x, i}; // 입력받은 새로받은 서열과 그때의 숫자가 속한 그룹을 pair형으로 1차원 벡터에 저장
            t++;
        }
    } 
    // 여기까지가 정렬 전(1번 그림)

    sort(S.begin(), S.end()); // 정렬 후(2번 그림)

    int WS = 0; 
    int NRS[K] = {0, }; // 그룹 개수만큼 NRS의 크기를 설정
    vector<int> res(N);

    for (int i = 0; i < N; i++) // 모든 숫자를 방문해야 하므로 총 숫자 개수만큼 도는 for문 만들기
    {
        a = 0;
        
        if (WS - NRS[i] == S[i].second) // WS - n(RSk) = 0이면(정방향 출력)
        {
            for (int j = 0; j < p[a]; j++)
            {
                rk += 1;
                a++;
                res[i] = 
            }
            
        }
        else // WS - n(RSk) /= 0이면(역방향 출력)
        {

        }
        cout << '\n';
    }



}