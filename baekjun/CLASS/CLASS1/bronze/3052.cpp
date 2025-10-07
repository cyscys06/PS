#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int a, count = 0, mod;
    bool flag = true;
    vector<int> A;

    while (cin >> a)
    {
        A.push_back(a);
    }

    vector<int> B;
    
    mod = A[0] % 42; // 초기값 설정 
    B.push_back(mod);
    count++;

    for (int i = 1; i < A.size(); i++) // A 벡터의 두번째 값부터 루프 시작
    {
        flag = true;
        mod = A[i] % 42; // 루프마다 나머지 갱신
        
        for (int j = 0; j < B.size(); j++) // 갱신한 나머지가 이전에 기록한 나머지와 다른지 비교하는 과정을 B 벡터의 원소의 개수만큼 반복
        {
            if (mod == B[j]) // 갱신한 나머지가 이전에 기록한 나머지와 같을때
            {
                flag = false;
                break; // 기록한 나머지중 하나라도 같으면 개수가 증가하지 않아야 하므로 break로 강제 다음 루프 넘어가기
            }   
        }
        
        if (flag == true) // 갱신한 나머지가 기록한 나머지와 다를때
        {
            count++;
            B.push_back(mod); // 갱신한 나머지를 B 벡터에 기록
        } 
    }

    cout << count;

    return 0;
}