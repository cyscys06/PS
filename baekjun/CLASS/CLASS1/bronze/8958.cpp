#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::string;

int main()
{
    int score = 0, t;
    cin >> t;
    
    vector<string> T(t);
    vector<int> final_score(t, 0);

    for (int i = 0; i < t; i++)
    {
        cin >> T[i];
    }

    for (int i = 0; i < t; i++)
    {
        score = 0;
        
        for (int j = 0; j < T[i].size(); j++)
        {
            if (T[i][j] == 'X')
            {
                score = 0;
            }
            else if (T[i][j] == 'O')
            {
                score += 1;
                final_score[i] += score;
            }
        }

        cout << final_score[i] << '\n';
    }

    return 0;
}