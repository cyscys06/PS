#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int n, t, p, countT = 0, countP1, countP2; //총 인원수, 티셔츠 한묶음의 개수, 펜 한묶음의 개수, 총 티셔츠 묶음 수, 총 펜 묶음 수, 펜 낱개 주문 수

    vector<int> T(6);
    cin >> n;
    
    for (int i = 0; i < T.size(); i++)
    {
        cin >> T[i];
    }
    
    cin >> t >> p;

    for (int i = 0; i < T.size(); i++)
    {
        if (T[i] % t == 0) // 사이즈별 티셔츠 t로 나눈 나머지가 0이면
        {
            countT += T[i] / t; // 나눈 몫이 곧 묶음수
        }
        else // 나머지 1 이상이면'
        {
            countT += T[i] / t + 1; // 나머지 메꿀 1 더해서 카운트에 더하기
        }
    }

    countP1 = n / p;
    countP2 = n % p;

    cout << countT << '\n' << countP1 << " " << countP2;

    return 0;
}