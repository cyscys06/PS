#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int a = 0; a < t; a++)
    {
        int s, n, total = 0;
        cin >> s >> n;
        vector<pair<int, int>> car(n);
        total += s;

        for (int i = 0; i < n; i++)
        {
            cin >> car[i].first >> car[i].second;
            total += car[i].first * car[i].second;
        }

        cout << total << '\n';
    }

    return 0;
}