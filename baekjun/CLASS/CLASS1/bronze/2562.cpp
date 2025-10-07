#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::max;

int main()
{
    int a, MAX = INT_MIN, b;
    vector<int> A;

    while (cin >> a)
    {
        A.push_back(a);
    }

    for (int i = 0; i < A.size(); i++)
    {
        if (MAX < A[i])
        {
            MAX = A[i];
            b = i;
        }
    }

    cout << MAX << '\n';
    cout << b + 1 << '\n';

    return 0;
}