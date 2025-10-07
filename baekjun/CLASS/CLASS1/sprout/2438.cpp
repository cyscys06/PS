#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    int a;
    cin >> a;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << '\n';
    }

    return 0;
}