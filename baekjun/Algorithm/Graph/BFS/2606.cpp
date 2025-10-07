#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M, u, v; // 정점개수, 간선개수, 시작점, 끝점
    cin >> N >> M;

    vector<vector<int>> G(N); // 무방향/희소 그래프이므로, N * N인 2차원 벡터 만들기(노드를 기준으로 탐색)
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        u--; // 노드 6개면 인덱스는 0~5이므로 실제입력값에서 1씩 빼주기
        v--;
        G[u].push_back(v);
        G[v].push_back(u); // 무방향이므로 반대 경우도 넣어주기(대칭)
    }

    int count = 0; // 연결된 정점의 개수(즉 연결된 컴퓨터 개수)
    vector<bool> vis(N, false); // 방문여부 검사용 벡터
    
    queue<int> q;
    q.push(0); // 큐에 노드 번호 푸쉬
    vis[0] = true; // 방문 노드는 1로 표시

    // 전체탐색 아니므로 for문 순회 필요 X        
    while(!q.empty()) // q 안에 뭐가 있을때(즉 하나의 컴포넌트 안의 모든 연결된 노드들을 탐색)
    {
        int cur = q.front(); // 큐의 맨앞 값(특정 노드 번호)
        q.pop(); // cur에 저장했으니 큐에서 빼기


        for (auto next : G[cur]) // cur: 간선의 시작정점 또는 연결된 정점 -> next는 true거나 false
        {
            if (vis[next] == false) // 연결된 다음 노드에 대해:
            {
                q.push(next);
                vis[next] = true; 
                count++;
            }
        }
    }
    cout << count << '\n';  
    return 0;
}