#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Parametric_Search(vector<int> &A, int n);

int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> A(k);
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
    }

    cout << Parametric_Search(A, n);

    return 0;
}

int Parametric_Search(vector<int> &A, int n)
{
    int max = *max_element(A.begin(), A.end());
    int count, result;
    ll s = 1, e = max;
    while (s <= e)
    {
        ll m = (s + e) / 2;
        count = 0;

        for (int i = 0; i < A.size(); i++)
        {
            count += A[i] / m;
        }

        if (count >= n) // 조건 만족
        {
            result = m;
            s = m + 1;
        }
        else if (count < n) // 조건 불만족
        {
            e = m - 1;
        }
    }
    return result;
}