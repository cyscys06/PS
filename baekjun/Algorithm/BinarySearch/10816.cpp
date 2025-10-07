#include <bits/stdc++.h>
using namespace std;

int lower_bound(const vector<int>& A, int target);
int upper_bound(const vector<int>& A, int target);

int main() 
{
    
    int N, M;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) 
    {
        cin >> B[i];
    }
    
    for (int i = 0; i < M; i++) 
    {
        int lb = lower_bound(A, B[i]);
        int ub = upper_bound(A, B[i]);
        cout << ub - lb << " ";
    }
    return 0;
}

int lower_bound(const vector<int>& A, int target) 
{
    int start = 0;
    int end = A.size();
    while (start < end) 
    {
        int mid = (start + end) / 2;
        if (A[mid] < target)
            {
                start = mid + 1;
            }
        else
            {
                end = mid;
            }
    }
    return start;
}

int upper_bound(const vector<int>& A, int target) 
{
    int start = 0;
    int end = A.size();
    while (start < end) 
    {
        int mid = (start + end) / 2;
        if (A[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }   
    }
    return start;
}
