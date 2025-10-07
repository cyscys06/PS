#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int d = a * b * c;
    vector<int> res(10, 0);

    while (d > 0)
    {
        int t = d % 10;
        res[t]++;
        d /= 10;
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }

    return 0;
}