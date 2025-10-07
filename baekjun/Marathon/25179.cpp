#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;

    if ((n - 1) % (m + 1) != 0)
    {
        cout << "Can win";
    }
    else 
    {
        cout << "Can't win";
    }
    return 0;
}