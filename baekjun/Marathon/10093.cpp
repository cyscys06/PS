#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a, b, c;
    cin >> a >> b;

    if (b >= a)
    {
        if (b == a)
        {
            cout << 0;
            return 0;
        }
        
        c = b - a - 1;
        cout << c << '\n';
        for (unsigned long long i = a + 1; i < b; i++)
        {
            cout << i << " ";
        }
    }
    else if (b < a)
    {
        c = a - b - 1;
        cout << c << '\n';
        for (unsigned long long i = b + 1; i < a; i++)
        {
            cout << i << " ";
        }
    }

    return 0;
}