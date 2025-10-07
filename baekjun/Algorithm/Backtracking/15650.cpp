#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> result; 
vector<bool> vis(8, false);

void recursion(int index, int count) // 수열을 오름차순으로 만들기위해 인덱스 값을 추가로 인자로 받도록 함 
// 재귀함수를 호출할때마다 인덱스 값을 다음 재귀함수에 건네주면 다음 재귀함수에서는 항상 이전 함수보다 큰 인덱스로만 함수를 시작하게 됨
{
    
    if (count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
        return; 
    }

    for (int i = index; i <= N; i++)
    {
        if (!vis[i])
        {
            vis[i] = true; 
            result.push_back(i); 
            recursion(i + 1, count + 1); // 다음 재귀함수에서는 현재 인덱스인 i보다 1 큰 값을 인자로 보냄 -> 항상 i보다 큰 값이 다음 재귀함수에서 사용됨
            result.pop_back();
            vis[i] = false;
        }   
    }
}

int main()
{
    cin >> N >> M; 
    recursion(1, 0); // 인덱스는 1부터 시작하는걸로 설정 
    return 0;
}