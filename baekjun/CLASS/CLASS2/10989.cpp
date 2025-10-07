#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> count(10001, 0);

    for (int i = 0; i < n; i++) 
    {
        int x;
        cin >> x;
        count[x]++;
    }

    // 출력 (중복 개수만큼)
    for (int i = 1; i <= 10000; i++) 
    {
        while (count[i]--) {
            cout << i << '\n';
        }
    }

    return 0;
}
