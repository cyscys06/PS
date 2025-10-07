#include <bits/stdc++.h>
using namespace std;

int M, N, day = 0, unripe = 0;
queue<pair<int,int>> q;

int main() 
{
    cin >> M >> N;
    vector<vector<int>> tomato(N, vector<int>(M));

    for (int y = 0; y < N; y++) 
    {
        for (int x = 0; x < M; x++) 
        {
            cin >> tomato[y][x];
            if (tomato[y][x] == 1) 
            {
                q.push({x, y});
            }   
            else if (tomato[y][x] == 0)
            {
                unripe++;
            }
        }
    }

    if (unripe == 0) 
    { 
        cout << 0 << '\n'; return 0; 
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    while (!q.empty()) 
    {
        int cycle = (int)q.size();
        
        for (int i = 0; i < cycle; ++i) 
        {
            auto [x, y] = q.front(); 
            q.pop(); 
            for (int d = 0; d < 4; d++) 
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= M || ny < 0 || ny >= N) 
                {
                    continue;
                }
                
                if (tomato[ny][nx] == 0) 
                {
                    tomato[ny][nx] = 1;
                    q.push({nx, ny}); 
                    --unripe;
                }
            }
        }
        ++day;
    }

    cout << (unripe == 0 ? day - 1 : -1) << '\n';
    return 0;
}
