#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Parametric_Search(vector<int> &A, int m);

int main()
{
    int n, m; // 강의 수, 블루레이 수
    cin >> n >> m;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << Parametric_Search(A, m);

    return 0;
}

int Parametric_Search(vector<int> &A, int m)
{
    ll start = *max_element(A.begin(), A.end()); // 최소: 적어도 입력받은 값들 중 가장 큰 값까지는 담을 수 있어야 함
    ll end = 0; // 최대: 모든 값들의 합을 충분히 담을수 있는 공간
    for (int i = 0; i < A.size(); i++)
    {
        end += A[i];
    }
    int result = end;

    while (start <= end)
    {
        ll mid = (start + end) / 2;
        int count = 1, sum = 0;
        
        for (int i = 0; i < A.size(); i++)
        {
            if (sum + A[i] > mid)
            {
                count++;
                sum = 0;
            }
            sum += A[i];
        }
    
        if (count <= m) 
        {
            result = mid;
            end = mid - 1;
        }
        else if (count > m) 
        {
            start = mid + 1;
        }
    }
    return result;
}