#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, l, result = 0;
    cin >> a;

    for (int i = 31; i >= 0; i--)
    {
        if (a & (1 << i))
        {
            l = i;
            break;
        }
    }

    for (int i = l; i >= 0; i--)
    {
        if (a & (1 << i))
        {
            result += (1 << (l - i));
        }
        
    }

    cout << result;

    return 0;
}