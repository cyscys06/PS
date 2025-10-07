#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int main()
{
    int a, b;
    vector<pair<int, int>> N;

    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
        {
            break;
        }
        N.push_back({a, b});
    }

    for (int i = 0; i < N.size(); i++)
    {
        cout << N[i].first + N[i].second << '\n';
    }

    return 0;
}