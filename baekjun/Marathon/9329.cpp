#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int T;
    cin >> T;
    bool flag;
    int index;
    int n, m, k, s, totalmoney;

    for (int w = 0; w < T; w++)
    {
        cin >> n >> m;
        vector<int> nums(m);
        vector<vector<int>> sticker(n);
        vector<int> money(n);
        totalmoney = 0;
        for (int a = 0; a < n; a++)
        {
            cin >> k;
            
            for (int b = 0; b < k; b++)
            {
                cin >> s;
                sticker[a].push_back(s);
            }

            cin >> money[a];
        }
        for (int c = 0; c < m; c++)
        {
            cin >> nums[c];
        }
        
        for (int i = 0; i < n; i++)
        {
            flag = true;
            while (flag)
            {
                for (int j = 0; j < sticker[i].size(); j++)
                {
                    index = sticker[i][j];
                    if (nums[index - 1] == 0)
                    {
                        flag = false;
                        break;
                    }
                    if (flag)
                    {
                        nums[index - 1]--;
                    }
                }
                if (flag)
                {
                    totalmoney += money[i];
                }
            }
        }

        cout << totalmoney << '\n';
    }

    return 0;
}