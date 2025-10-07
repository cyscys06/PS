#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, waiting = 0, answer = 0;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        waiting += A[i];
        answer += waiting;
    }

    cout << answer;
    return 0;
}