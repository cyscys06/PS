#include <bits/stdc++.h>
using namespace std;

int getA(int a, int b);
int getB(int a, int b);

int main()
{
    int a, b;
    cin >> a >> b;

    cout << getA(a, b) << '\n' << getB(a, b);
    return 0;
}

int getA(int a, int b)
{
    int r = a % b;
    while (r != 0)
    {   
        a = b;
        b = r;
        r = a % b;
    } 
    return b;
}
int getB(int a, int b)
{
    return (a * b) / getA(a, b);
}

// 유클리드 호제법: 두 양의 정수 a, b에 대해 a를 b로 나눈 나머지를 r이라 하면(단 0 <= r < b) a, b의 최대공약수는 b, r의 최대공약수와 같다
// 나머지가 0이 될 때까지 반복
// ex) 24, 18의 최대공약수 구하기
// 24 = 18 * 1 + 6, r = 6
// 18 = 6 * 3 + 0, r = 0
// 따라서 24와 18의 최대공약수는 6
