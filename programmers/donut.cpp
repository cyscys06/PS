#include <bits/stdc++.h>
using namespace std;

int u, v; // 시작, 종료
int max_node = 0; // 노드의 최댓값, 즉 노드의 개수
vector<int> solution(vector<vector<int>> edges) 
{
    vector<int> answer;
    while (cin >> u >> v)
    {
        u--;
        v--;
        edges[u].push_back(v);
        max_node = max({max_node, u, v}); // 시작/종료 노드중 큰값을 max_node에 저장
    }
    int N = max_node; // 간선 개수

    vector<int> indegree(N, 0);
    vector<int> outdegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        int u = edges[i][0]; // 시작노드
        int v = edges[i][1]; // 종료노드

        outdegree[u]++; // 정점기준 outdegree는 시작노드임
        indegree[v]++; // 정점기준 indegree는 종료노드임
    }

    vector<int> new_indegree(N, 0);
    vector<int> in_outdegree(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (outdegree[i] >= 2 && indegree[i] == 0) // 새로 생성된 정점 찾기
        {
            answer.push_back(i);
            answer.push_back(outdegree[i]); // answer[1]에 그래프 총 개수가 저장
        }

        if (outdegree[i] == 0 && indegree[i] >= 1)
        {
            answer[2]++;
        }

        if (outdegree[i] == 2 && indegree[i] == 2)
        {
            answer[3]++;
        }
    }
    answer[1] = answer[1] - answer[2] - answer[3];

    return answer;
}

int main()
{
    vector<vector<int>> edges = {};
    vector<int> result = solution(edges);

    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i] << ' ';
    }
}