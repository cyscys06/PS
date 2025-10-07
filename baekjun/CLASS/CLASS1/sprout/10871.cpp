#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> N(n);

    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
        if (N[i] < x)
        {
            cout << N[i] << " ";
        }
    }

    return 0;
}