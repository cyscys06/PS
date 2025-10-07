#include <bits/stdc++.h>
using namespace std;

string BW[8] = 
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string WB[8] = 
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int getChangeCount(vector<vector<char>> arr, int n, int m);

int main()
{
    int n, m, changeCount, min = INT_MAX;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            changeCount = getChangeCount(arr, i, j);     
            
            if (min > changeCount)
            {
                min = changeCount;
            }
        }
   
    }
    cout << min;
    return 0;
}

int getChangeCount(vector<vector<char>> arr, int n, int m)
{
    int BWcount = 0;
    int WBcount = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (arr[n + i][m + j] != WB[i][j])
            {
                WBcount++;
            }
            if (arr[n + i][m + j] != BW[i][j])
            {
                BWcount++;
            }
        }
    }

    return min(BWcount, WBcount);
}

// 핵심: 전체 판에서 8 * 8로 깎은 판을 원본 체스판과 비교할때, 왼쪽위가 W/B로 시작하는 체스판과 각각 비교해서 서로 다를때 각각 카운트를 증가시킴 
// 8 * 8로 깎은 판을 색칠한 방식(W시작, B시작)중 최솟값을 리턴
