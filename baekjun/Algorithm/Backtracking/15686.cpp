#include <bits/stdc++.h>
using namespace std;

int N, M, answer = 10000; // answer: 조합별 도시 최소 거리 중 최솟값(미리 매우 큰 수로 초기화해놓으면 나중에 비교할때 자동으로 최솟값이 할당됨)
int CD[14]; // 조합별 도시 최소 거리를 저장하는 배열 

vector<vector<int>> city(51, vector<int>(51)); // 도시 정보를 담을 벡터
vector<pair<int, int>> house; // 집 좌표를 저장하는 벡터
vector<pair<int, int>> chicken; // 치킨집 좌표를 저장하는 벡터
vector<bool> vis(14); // 방문표시용 벡터
vector<pair<int, int>> selected; // 치킨집 조합을 좌표로 담을 벡터

int GetCityDistance(vector<pair<int, int>> house, vector<pair<int, int>> selected); // 집 좌표 벡터, 치킨집 조합의 좌표 벡터를 인자로 받아 조합별 도시 치킨 거리를 반환하는 함수
void recursion(int index, int count);

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j]; // 도시의 정보를 벡터에 저장
            if (city[i][j] == 1) 
            {
                house.push_back({i, j}); // 1이라면 집 좌표 저장
            } // 원래 push_back() 에 하나의 인자만 넣을 수 있으나 인자 여러개를 중괄호로 묶어 하나의 인자로 전달 가능함
            else if (city[i][j] == 2)
            {
                chicken.push_back({i, j}); // 2라면 치킨집 좌표 저장
            }
        }
    }

    recursion(0, 0);
    cout << answer;
    return 0;
}

int GetCityDistance(vector<pair<int, int>> house, vector<pair<int, int>> selected) 
{
    int CityDistance = 0;
    for (int i = 0; i < house.size(); i++) // 모든 집에 대해 치킨 거리를 구해야 함
    {
        int minDist = 10000; // 치킨 거리(미리 매우 큰 수로 초기화)
        for (int j = 0; j < selected.size(); j++)
        {
            int dist = abs(house[i].first - selected[j].first) + abs(house[i].second - selected[j].second);
            minDist = min(minDist, dist);
        }
        CityDistance += minDist;
    }
    // for문 끝나면 하나의 조합의 도시 치킨 거리가 구해짐
    return CityDistance; // 그 거리를 반환
}

void recursion(int index, int count)
{
    if (count == M)
    {
        answer = min(answer, GetCityDistance(house, selected));
        return;
    }

    for (int i = index; i < chicken.size(); i++) // 방문하지 않은 치킨집을 만날 때까지 순회, 중복없는 조합
    {
        if (!vis[i]) // 방문하지 않은 치킨집을 만나면
        {
            vis[i] = true; // 치킨집을 방문표시
            selected.push_back(chicken[i]); // 치킨집의 좌표를 저장
            recursion(i + 1, count + 1); // 마지막 재귀에서(즉 count == M일때) 그 재귀에서 if문 실행 
            selected.pop_back(); // result에 저장해놓은 좌표 빼기
            vis[i] = false; // 방문표시 해제
        }
    }
}