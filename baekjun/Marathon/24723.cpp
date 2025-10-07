#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    int a, b = 1;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        b *= 2;
    }
    cout << b;

    return 0;
}