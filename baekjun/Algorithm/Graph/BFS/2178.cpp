#include <bits/stdc++.h>
using namespace std;

int N, M; // 세로, 가로

// 세로: y 가로: x 순서쌍 첫번째: y 두번째: x
int main()
{
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M));
    
    for (int y = 0; y < N; y++)
    {
        string s; 
        cin >> s;
        
        for (int x = 0; x < M; x++)
        {
            maze[y][x] = s[x] - '0';
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, 0)); // 이동거리 기록용 배열
    queue<pair<int, int>> q;

    if (maze[0][0] == 1) // 시작지점 포함
    {
        dist[0][0] = 1;
        q.push({0, 0});
    }

    // 현재좌표 기준 인접좌표에 접근하는 인덱스 집합들(시계방향으로 12시부터)
    int dx[4] = {0, 1, 0, -1};   
    int dy[4] = {-1, 0, 1, 0};
    // 위: -1, 0 오른: 0, 1 아래: 1, 0 왼0, -1 (인덱스 기준)

    while(!q.empty()) // 큐에 원소가 남지 않을때까지 반복(즉 방문가능한 모든 좌표에 방문할때까지 반복)
    {  
        auto[y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) // 현재좌표 기준 상하좌우 네방향에 인접한 모든 좌표를 방문하기 위한, 4번 순회하는 for문
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) 
            {
                continue;
            }

            if (maze[ny][nx] == 1 && dist[ny][nx] == 0) // 현재좌표에서 인접한 좌표에 방문하지 않은(즉 1인) 좌표가 있으면
            {
                q.push({ny, nx}); // 인접좌표의 좌표를 큐에 푸쉬(이 좌표는 후에 또다른 현재 좌표로 간주됨)
                dist[ny][nx] = dist[y][x] + 1; // 움직인 거리 기록
            }
        }
    }

    cout << dist[N-1][M-1] << '\n';
    return 0;
}