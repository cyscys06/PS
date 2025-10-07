#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle);

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> triangle(N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int num;
            cin >> num;
            triangle[i - 1].push_back(num);
        }
    }

    cout << solution(triangle);
    return 0;
}

int solution(vector<vector<int>> triangle)
{
    int answer = 0; // 숫자 총합
    for (int i = 1; i < triangle.size(); i++) // 2층부터 시작, 마지막 층까지 반복
    {
        for (int j = 0; j < triangle[i].size(); j++) // 각각의 층의 원소개수만큼
        {
            if (j == 0) // 처음이면
            {
                triangle[i][j] += triangle[i - 1][0];
            }
            else if (j == triangle[i].size() - 1) // 마지막이면
            {
                triangle[i][j] += triangle[i - 1].back();
            }
            else // 중간이면
            {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }
    int last = triangle.size() - 1;

    for (int i = 0; i <= last; i++)
    {
        answer = max(answer, triangle[last][i]);
    }

    return answer;
    // *max_element() 함수 사용하기
}