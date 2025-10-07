#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, b; // 노드 개수, 앞, 뒷값
    cin >> N;

    vector<vector<int>> graph(N); // 인접 리스트

    for (int i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        a--; b--; // 실제값에서 1빼서 0기반 인덱스로 만들기
        // 트리는 무방향 그래프이므로 양쪽 방향 다 넣기
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> ans(N); // 부모 노드 기록용 벡터
    vector<bool> vis(N, false); // 방문용 벡터(노드의 개수와 같음)
    queue<int> q; // 

    // 부모 노드 찾기 코드
    
    q.push(0); // 루트 노드부터 시작
    vis[0] = true; // 1번 노드는 방문 표시

    while(!(q.empty())) // 큐에 아무것도 남지 않을 때까지 반복
    {
        int parent = q.front(); // 큐의 맨 앞에 있는 값을 부모 노드로 지정(1은 부모 노드)
        q.pop(); // 큐의 맨 앞에 있는 원소를 제거

        for (int i = 0; i < graph[parent].size(); i++) // 연결 정보를 저장한 벡터의 부모 노드와 연결된 자식 노드를 모두 순회(부모 노드와 대응하는 인덱스에 푸쉬백된 모든 인덱스를 순회)
        {
            int child = graph[parent][i]; // 자식 노드를 지정
            if (!(vis[child])) // 방문하지 않은 노드인 경우
            {
                ans[child] = parent; // 자식 노드의 부모 노드를 정답 벡터에 저장
                vis[child] = true; // 방문 표시
                q.push(child); // 자식 노드를 큐에 푸쉬(현재 자식 노드를 다음 부모 노드로 간주)
            }
        } 
    }

    for (int i = 1; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << '\n';
    }

    return 0;
}


// BFS 원리
// 1. 큐 초기화: 시작 노드를 큐에 넣고 방문 표시를 합니다.
// 2. 큐에서 노드 추출: 큐에서 노드를 하나 꺼내어 현재 노드로 설정합니다.
// 3. 인접 노드 확인: 현재 노드와 인접한 모든 노드들을 확인합니다.
// 4. 방문하지 않은 노드 큐에 추가: 인접한 노드 중 방문하지 않은 노드를 모두 큐에 추가하고 방문 표시를 합니다.
// 5. 큐가 빌 때까지 반복: 큐가 빌 때까지 2번부터 4번까지의 과정을 반복합니다.