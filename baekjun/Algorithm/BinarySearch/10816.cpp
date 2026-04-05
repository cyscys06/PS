#include <bits/stdc++.h>
using namespace std;

int lower_bound(const vector<int>& A, int target); // lower bound: 타겟 값 이상이 처음 나타나는 위치를 반환하는 함수
int upper_bound(const vector<int>& A, int target); // upper bound: 타겟 값보다 큰 값이 처음 나타나는 위치를 반환하는 함수

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
        int lb = lower_bound(A, B[i]); // lowerbound함수로 찾은 위치값
        int ub = upper_bound(A, B[i]); // upperbound함수로 찾은 위치값
        cout << ub - lb << " "; // ub - lb = 타겟 값이 적힌 숫자 카드의 개수
    } // 1 <= x < 5
    return 0;
}

int lower_bound(const vector<int>& A, int target) 
{
    int start = 0; // 시작 인덱스 값
    int end = A.size(); // 벡터 크기
    while (start < end) 
    {
        int mid = (start + end) / 2; // 중간값 저장
        if (A[mid] < target) // 중간값이 타겟보다 작으면,
            {
                start = mid + 1; // 탐색 범위를 중간값의 우측으로 변경(더 큰 쪽에 타겟 값이 있을 것)
            }
        else // 중간값이 타겟보다 크면,
            {
                end = mid; // 탐색 범위를 중간값의 좌측으로 변경(더 작은 쪽에 타겟 값이 있을 것)
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
