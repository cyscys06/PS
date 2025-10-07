#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int MIN = INT_MAX, MAX = INT_MIN;
    cin >> n;

    vector<int> N(n);

    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
        MIN = min(MIN, N[i]);
        MAX = max(MAX, N[i]);
    }

    cout << MIN << " " << MAX;

    return 0;
}