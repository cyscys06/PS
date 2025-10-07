#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    vector<string> T;
    string a;

    bool flag;

    while (true)
    {
        cin >> a;
        if (a == "0")
        {
            break;
        }
        
        T.push_back(a);
    }

    for (int i = 0; i < T.size(); i++)
    {
        flag = true;

        int t = T[i].size();
        for (int j = 0; j < t / 2; j++)
        {
            if (!(T[i][j] == T[i][t - j - 1]))
            {
                flag = false;
            }
        }
        
        if (flag == true)
        {
            cout << "yes" << '\n';
        }
        else 
        {
            cout << "no" << '\n';
        }
    }

    return 0;
}

