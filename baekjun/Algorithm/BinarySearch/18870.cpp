#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> O(N); // 원본 벡터
    vector<int> C(N); // 정렬/압축 벡터
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        O[i] = temp;
        C[i] = temp;
    } // 입력값 전부 입력

    sort(C.begin(), C.end()); // 정렬
    C.erase(unique(C.begin(), C.end()), C.end()); // 중복 제거

    for (int i = 0; i < N; i++)
    {
        int com = lower_bound(C.begin(), C.end(), O[i]) - C.begin(); // 목표값 미만 값들 만큼의 개수
        cout << com << " ";
    }

    return 0;
}