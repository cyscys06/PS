#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::tuple;

int main()
{
    int a, b, c;
    vector<vector<int>> T;

    cin >> a >> b >> c;
    while (a != 0)
    {
        T.push_back({a, b, c});
        cin >> a >> b >> c;
    }

    for (int i = 0; i < T.size(); i++)
    {
        int rr4 = T[i][0] * T[i][0] * 4;
        int ww = T[i][1] * T[i][1];
        int ll = T[i][2] * T[i][2];

        if (rr4 >= ww + ll)
        {
            cout << "Pizza " << i + 1 << " fits on the table." << '\n';
        }
        else 
        {
            cout << "Pizza " << i + 1 << " does not fit on the table." << '\n';
        }
    }

    return 0;
}