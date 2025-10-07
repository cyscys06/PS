#include <bits/stdc++.h>
using namespace std;

int binarysearch(int i, const vector<int> &A, const vector<int> &B);

int main()
{
    int N, num1, M, num2;
    cin >> N;

    vector<int> A(N); 
    for (int i = 0; i < N; i++)
    {
        cin >> num1;
        A[i] = num1;
    }
    sort(A.begin(), A.end());

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> num2;
        B[i] = num2; 
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (binarysearch(i, A, B) == 1)
        {
            cout << "1\n";
        }
        else if (binarysearch(i, A, B) == 0)
        {
            cout << "0\n";
        }
    }
    

    return 0;
}

int binarysearch(int i, const vector<int> &A, const vector<int> &B)
{
    int start = 0;
    int end = A.size() - 1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (A[middle] == B[i])
        {
            return 1;
        }
        else if (A[middle] < B[i])
        {
            start = middle + 1;
        }
        else if (A[middle] > B[i])
        {
            end = middle - 1;
        }
    }
    return 0;
}
