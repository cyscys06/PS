#include <bits/stdc++.h>
using namespace std;

int N, result = 0;
bool vis1[15], vis2[30], vis3[30]; // 각각 열, 왼쪽아래 대각선, 오른쪽아래 대각선

void recursion(int row) // 현재 행 몇번째인지를 최대 행 개수 N과 비교하면서 재귀함수 호출(1차원 배열 row를 인자로 받음)
{
    if (row == N) // 마지막 행까지 가면
    {
        result++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (vis1[i] || vis2[row + i] || vis3[row - i + N]) // 이전 행에 놓은 퀸의 위치와 같은 열에 있거나 양방향 대각선 거리에 있는 퀸이라면
        {
            continue; // 다음 루프로 강제로 넘어가기
        }
        vis1[i] = vis2[row + i] = vis3[row - i + N] = true; // 이미 놓은 퀸 자리를 기준으로 세로, 양 대각선 좌표들은 true로 놓기(true면 못놓는 자리임, false면 놓을수 있음)
        recursion(row + 1); // 재귀함수 실행
        vis1[i] = vis2[row + i] = vis3[row - i + N] = false; // 모든 재귀함수 다 호출 끝나면(즉 퀸끼리 공격 불가한 자리에 모두 놓은게 끝나면) false로 true였던 좌표들 해제해주기
    }
}

int main()
{
    cin >> N;
    recursion(0);
    cout << result;
    return 0;
}