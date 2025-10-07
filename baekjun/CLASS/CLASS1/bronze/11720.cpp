#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    int a, count = 0;
    string b;
    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        count += b[i] - '0';
    }

    cout << count;

    return 0;
}