#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
   
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    } 
    vector<pair<int,int>> ops; // 뒤집은 구간 기록

    for (int i = 0; i < n; i++) 
    {
        if (a[i] == i + 1) 
        {
            continue;
        } // 이미 제자리면 패스
        
        // 올바른 숫자(i+1)가 있는 위치 찾기
        int j = i;
        while (a[j] != i + 1) 
        {
            j++;
        }
        // [i, j] 구간 뒤집기
        reverse(a.begin() + i, a.begin() + j + 1);
        ops.push_back({i + 1, j + 1}); // 1-based 인덱스 저장
    }

    cout << ops.size() << "\n";
    for (auto &p : ops) 
    {
        cout << p.first << " " << p.second << "\n";
    }
}
