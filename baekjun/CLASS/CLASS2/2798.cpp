#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> N(n);
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }

    int max = 0;
    int total = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                total = N[i] + N[j] + N[k];
                if (total <= m && total > max)
                {
                    max = total;
                }
            }
        }
    }

    cout << max;
    return 0;
}

// 핵심: 3장의 카드를 각각 서로 다른 인덱스에서 더하는데, 
// 이때 for문을 하나만 써서 i-2, i-1, i 이렇게 더하면 값들이 선형으로 더해져서 모든 경우의수를 다 볼수 없음(예를들면 띄엄띄엄 더하는 경우)
// 따라서 서로 독립적으로 움직이는 for문을 뽑는 카드 장수만큼 만들어서, 독립적으로 움직이는 i, j, k를 기반으로 모든 경우의 수를 다 봐야 함(브루트포스)