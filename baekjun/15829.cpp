#include <iostream>
#include <vector>
using namespace std;
long long r = 1;
const int M = 1234567891;

int main()
{
    int L;
    long long total = 0;
    cin >> L;

    string l;
    cin >> l;

    for (int i = 0; i < L; i++)
    {
        int a = l[i] - 96;
        total += (a * r) % M;
        r = (r * 31) % M;
    }
    // r for문으로 증가시키면 안됨 -> 하나의 반복마다 갱신하는 식으로 증가
    long long res = total % M;

    cout << res;
    return 0;
}

// 자료형 long long으로 해도 못담아서 total에 더하거나 r 갱신할때마다 M으로 나눠줘야 함