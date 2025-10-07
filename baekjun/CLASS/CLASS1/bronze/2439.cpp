#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    int a;
    cin >> a;

    for (int i = a; i > 0; i--)
    {
        for (int j = 1; j <= a; j++)
        {
            if (i - j > 0)
            {
                cout << " ";
                continue;
            }
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}