#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> result; 

void recursion(int count) 
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

    for (int i = 1; i <= N; i++) // 수열의 수들이 오름차순으로 정렬돼야 하는게 아니므로 인덱스를 그냥 1부터 시작해도 됨
    {
        result.push_back(i); 
        recursion(count + 1); 
        result.pop_back();
    }
    // 하나의 수열 안에서 중복인 숫자가 생기는걸 방지하기 위해 vis 벡터가 존재했는데 이 문제에서는 하나의 수열 안에서 숫자의 중복이 허용되므로 vis가 존재할 필요가 없음
    // 원래는 vis[i] = true를 통해 이미 지나온 길(이미 나온 경우의 수)는 따로 구별해서 같은 길을 다시 방문하지 않도록(즉 하나의 수열 안에서 중복 숫자가 발생하지 않도록) 했었음
}

int main()
{
    cin >> N >> M; 
    recursion(0); // 인덱스는 1부터 시작하는걸로 설정 
    return 0;
}