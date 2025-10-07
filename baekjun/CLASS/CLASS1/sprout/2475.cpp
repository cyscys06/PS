#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int a, num = 0;

    while (cin >> a)
    {
        num += (a * a);
    }

    num %= 10;
    cout << num;

    return 0;
}