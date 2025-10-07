#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int m, n; // 세로, 가로
    cin >> m >> n;

    vector<vector<bool>> S(m, vector<bool>(n, false));

    int i = 0, j = 0, count = 0; // 세로에 대한 이터레이터, 가로에 대한 이터레이터, 꺾은 횟수
    int visit = 0;
    int total = m * n; // 이동한 칸만큼 visit 1 증가, visit가 m * n(총 칸 수)와 같아지면 루프 종료

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dir = 0; // dx, dy의 0번째 인덱스(즉 오른쪽)부터 시작, 차례대로 오른쪽, 아래, 왼쪽, 위

    while (visit < total) // 방문안한 칸이 아직 남아있음
    {
        if (!S[i][j]) // 현재 칸 방문 표시 안했으면
        {
            S[i][j] = true; // 방문표시하고
            visit++;
        }

        int nj = j + dx[dir];
        int ni = i + dy[dir];

        if (ni < 0 || ni >= m || nj < 0 || nj >= n || S[ni][nj]) // 다음 이동할 좌표가 배열 범위를 벗어났거나 이미 방문한 좌표면 방향 전환
        {
            dir = (dir + 1) % 4; // dir에 1을 더하고 4로 나누면 0, 1, 2, 3이 계속 반복됨(dir이 3일때 다음 dir은 1더하고 4 나누면 다시 0 됨)
            count++; // 꺾은 횟수 1 증가
            
            ni = i + dy[dir];
            nj = j + dx[dir];
            // dir를 기반으로 다음 움직일 칸 지정
        }

        i = ni;
        j = nj;
    }

    cout << count - 1;

    return 0;
}