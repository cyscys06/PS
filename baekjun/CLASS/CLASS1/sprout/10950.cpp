#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::pair;

int main()
{
    int a;
    cin >> a;

    vector<pair<int, int>> A(a);

    for (int i = 0; i < a; i++)
    {
        cin >> A[i].first >> A[i].second;
    }

    for (int i = 0; i < a; i++)
    {
        cout << A[i].first + A[i].second << '\n';
    }

    return 0;
}