#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::sqrt;

int main()
{
    int a;
    cin >> a;

    vector<int> T(a);

    for (int i = 0; i < a; i++)
    {
        cin >> T[i];
        int root = sqrt(T[i]); // 숫자의 제곱근을 정수형 변수에 저장 -> 제곱근이 정수면 제곱근 통째로 변수에 저장, 제곱근 무한소수면 소수부분 짤림
        
        if (root * root == T[i])
        {
            cout << 1 << '\n';
        }
        else 
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}