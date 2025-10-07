#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int t, count;
    vector<int> T;

    while (true)
    {
        cin >> t;
        if (t == 0)
        {
            break;
        }

        T.push_back(t);
    }

    for (int i = 0; i < T.size(); i++)
    {
        count = 0;
        while(T[i] != 0)
        {
            count += T[i] * T[i];
            T[i]--;
        }

        cout << count << '\n';
    }
    
    return 0;
}