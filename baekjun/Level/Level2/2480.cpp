#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    if (d1 == d2 && d2 == d3)
    {
        cout << 10000 + (d1) * 1000 << '\n';
        return 0;
    }
    
    if (d1 == d2)
    {
        cout << 1000 + (d1) * 100 << '\n';
        return 0;
    } 
    else if (d2 == d3) 
    {
        cout << 1000 + (d2) * 100 << '\n';
        return 0;
    }
    else if (d3 == d1)
    {
        cout << 1000 + (d3) * 100 << '\n';
        return 0;
    }

    if (!(d1 == d2 && d2 == d3))
    {
        cout << max({d1, d2, d3}) * 100 << '\n';
        return 0;
    }
}