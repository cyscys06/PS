#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    int t;
    cin >> t;
    
    vector<int> R(t);
    vector<string> S(t);

    for (int i = 0; i < t; i++)
    {
        cin >> R[i] >> S[i];
    }

    for (int i = 0; i < t; i++) // 테스트케이스 루프
    {
        for (int j = 0; j < S[i].size(); j++) // 한 테케당 하나의 문자열 루프
        {
            for (int k = 0; k < R[i]; k++) // 한 문자열당 하나의 문자 루프
            {
                cout << S[i][j];
            }
        }
        
        cout << '\n';
    }

    return 0;
}