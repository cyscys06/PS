#include <iostream>
using namespace std;
int main()
{
    // 첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b) % c << '\n';
    cout << ((a % c) + (b % c)) % c << '\n';
    cout << (a * b) % c << '\n';
    cout << ((a % c) * (b % c)) % c << '\n';
    return 0;
} 