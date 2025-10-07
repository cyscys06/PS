#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    if (b < 0)
    {
        return 0;
    }
    cout << fixed << setprecision(9) << a / b;
    return 0;
}