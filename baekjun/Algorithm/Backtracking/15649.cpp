#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> result; // 정답 값을 저장할 벡터 미리 생성
vector<bool> vis(9, false);

void recursion(int count) // M개의 숫자를 골라 출력하는 것이므로 깊이(몇개의 숫자를 고르는지) = 목표 = M이 됨
// count는 트리 형태에서 다음 숫자를 찾아 밑으로 내려갈때마다 1씩 증가
{
    
    if (count == M) // M개만큼의 숫자를 모두 찾았으면
    {
        for (int i = 0; i < M; i++)
        {
            cout << result[i] << " "; // 정답 벡터 안에 있는 원소들(수열의 경우의 수)
        }
        cout << "\n";
        return; // return 함으로써 이 재귀함수 종료함
    }
    
    

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i]) // vis의 i번째 인덱스가 false라면
        {
            vis[i] = true; // 그 인덱스를 true표시함(즉 이 인덱스를 기준삼아 재귀함수를 계속 돌리겠다는 뜻)
            // 첫번째 루프에서 vis[1] = true로 설정됨. 그다음 밑의 재귀함수에서도 i는 똑같이 1부터 시작하지만 이미 vis는 true가 되었으므로 재귀함수에서는 다음 루프인 i = 2에서 vis[2]를 true로 설정하고 2를 1 다음에 올 슷자로 수열에 넣음
            result.push_back(i); // 재귀함수를 돌리면서 차례대로 숫자를 정답 벡터에 넣음
            recursion(count + 1); // 다음 재귀함수는 2번째 자리에 올 숫자를 찾는 재귀함수. count = 0, 1, 2, 3까지는 1, 2, 3, 4번째 숫자를 찾고 count = 4일때 그 모든 숫자들을 출력
            result.pop_back(); // 한가지 경우의수(숫자 집합)을 출력한 뒤에는 정답 벡터에서 하위 원소부터 하나씩 빼고 그 자리에 다른 경우의 수인 숫자를 넣음 -> 이거 반복
            vis[i] = false;
        } // pop_back(): 인자는 들어가지 않아도 되며, 자동으로 가장 최근에 들어온 원소를 빼줌.  
    }
}

int main()
{
    cin >> N >> M; 
    recursion(0); // N, M은 전역변수이므로 함수에 인자로 넣지 않아도 됨
    return 0;
}