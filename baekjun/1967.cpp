#include <bits/stdc++.h>
using namespace std;

bool visited[10001] = {false, }; // 방문표시용 배열
int Max = 0, total = 0; // Max: 트리 지름, total: 각 리프 노드별 경로값의 최댓값
vector<vector<pair<int, int>>> Graph(10001); 
// Graph[i]: i번 노드(출발노드)로부터 이동할 수 있는 다른 노드들(도착 노드)과 그 노드들로 이동하는 데 드는 가중치를 pair로 저장하는 vector가 저장돼있음
void dfs(int current_node, int weight);

int main() {
    int n, count;
    cin >> n;

    for (int i = 1; i < n; i++) { // n - 1번 입력받음(루트 노드가 자식노드인 경우는 없으므로, 루트노드가 자식노드로 존재하는 간선과 그 가중치에 대한 입력은 존재하지 않음)
        int parent, child, weight;
        cin >> parent >> child >> weight;
        Graph[parent].push_back({child, weight});
        Graph[child].push_back({parent, weight});
    }
    // 양방향 그래프 형태이므로, 부모 -> 자식/자식 -> 부모로 이동할 수 있도록 부모/자식 노드에 대한 출발노드/도착노드 정보 전부 저장하기
    
    vector<int> leaf;
    for (int i = 1; i <= n; i++) { // 모든 노드에 대해 반복
        if (Graph[i].size() == 1) { // i번째 노드에 저장된 vector의 size가 1이라는것은, i번째 노드와 연결된 노드가 1개 뿐이라는 뜻이므로, 해당 노드는 리프 노드가 됨
            leaf.push_back(i); // 자식노드 번호를 리프 노트 벡터에 저장
        }
    }
      
    for (int i = 0; i < leaf.size(); i++) {
        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
        dfs(leaf[i], 0);
    }

    cout << Max;

    return 0;
}

void dfs(int current_node, int weight) {
    visited[current_node] = true; // 현재 이동한 노드는 방문표시

    for (int i = 0; i < Graph[current_node].size(); i++) {
        int next_node = Graph[current_node][i].first;
        
        if (!visited[next_node]) {
            dfs(next_node, weight + Graph[current_node][i].second);
        }
    }
    
    // 여기까지 오면 더이상 이동할 다른 노드가 없다는 뜻
    // -> 지금까지 이동한 경로값을 Max와 비교
    if (Max < weight) {
        Max = weight;
    }
}