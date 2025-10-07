#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    double k, d1, d2, d3;
    cin >> k >> d1 >> d2;

    if (d1 == d2) 
    {
        cout << k * k;
        return 0;
    }
    else
    {
        if (d1 == 3 * d2)
        {
            cout << k * k - d2 * d2;
            return 0;
        }

        d3 = (d1 - d2) / 2;
        cout << k * k - d3 * d3;
    }

    return 0;
}