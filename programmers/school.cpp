#include <string>
#include <vector>

using namespace std;
const int M = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) // puddles 에는 물웅덩이 좌표만 담겨있음 -> 좌표 저장하는 2차원 벡터 별도로 만들기
{
    int answer = 0;
    vector<vector<int>> coordinate(n, vector<int>(m, 0)); // 격자 좌표 벡터
    vector<vector<bool>> isPuddle(n, vector<bool>(m, false)); // 물웅덩이 좌표 기록용 플래그 생성
    
    // puddles 실제좌표값에서 1씩 빼주기(격자용 좌표와 비교하기 위해)
    for (int i = 0; i < puddles.size(); i++)
    {
        puddles[i][0] -= 1;
        puddles[i][1] -= 1;
        isPuddle[puddles[i][1]][puddles[i][0]] = true; // 물웅덩이가 있는 좌표는 true로 기록
    }

    // 현재 좌표 인덱스 = 이전 좌표들(현재좌표 기준 위쪽과 왼쪽에 있는 좌표들)의 인덱스 값들을 더한 것
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isPuddle[i][j]) // 현재 좌표가 물웅덩이면
            {
                continue; // 강제로 다음 루프로 넘어가기
            } 
            // 물웅덩이인지를 먼저 체크해주기
            
            if (i == 0 && j == 0) // 시작지점
            {
                coordinate[i][j] = 1;
            }
            else if (i > 0 && j == 0) // 현재좌표 기준 위쪽좌표만 존재
            {
                coordinate[i][j] += coordinate[i - 1][j];
            }
            else if (i == 0 && j > 0) // 현재좌표 기준 왼쪽좌표만 존재
            {
                coordinate[i][j] += coordinate[i][j - 1];
            }
            else // 현재좌표 기준 위쪽, 왼쪽좌표 둘다 존재
            {
                coordinate[i][j] += (coordinate[i - 1][j] + coordinate[i][j - 1]);
            }

            coordinate[i][j] %= M; // 루프마다 M으로 나눠서 경로 개수가 오버플로우되는 현상 방지
        }
    }

    answer = coordinate[n - 1][m - 1];

    return answer;
}