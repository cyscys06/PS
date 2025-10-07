#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int main()
{
    int W, H, X, Y, p, count = 0; // 가로, 세로, (x, y), 선수 수, 경기장 안에 있는 선수 수
    cin >> W >> H >> X >> Y >> p;

    vector<pair<int, int>> P(p);

    for (int i = 0; i < p; i++)
    {
        cin >> P[i].first;
        cin >> P[i].second;
    }

    int R = H / 2; // H 짝수이므로 반지름 무조건 정수
    

    vector<pair<int, int>> O(2);
    O[0].first = X;
    O[1].first = X + W;
    O[0].second = O[1].second = Y + R;
    
    for (int i = 0; i < p; i++)
    {
        if ((P[i].first >= X && P[i].first <= X + W) && (P[i].second >= Y && P[i].second <= Y + H)) // 직사각형
        {
            count++;
            continue;
        }

        if (P[i].first < X) // 왼쪽 반원
        {
            double x = O[0].first - P[i].first;
            double y = O[0].second - P[i].second;
            double distance = sqrt(x * x + y * y); // 왼쪽 반원 중심과 선수 좌표 사이 거리
            
            if (distance <= R) // 반지름보다 작거나 같을때만
            {
                count++;
                continue;
            }
        }
        else if (P[i].first > X + W) // 오른쪽 반원
        {
            double x = O[1].first - P[i].first;
            double y = O[1].second - P[i].second;
            double distance = sqrt(x * x + y * y); // 오른쪽 반원 중심과 선수 좌표 사이 거리
            
            if (distance <= R) // 반지름보다 작거나 같을때만
            {
                count++;
                continue;
            }
        }
    }

    cout << count;

    return 0;
}