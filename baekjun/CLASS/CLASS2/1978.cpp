#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    bool flag;
    vector<int> N(n);

    for (int i = 0; i < n; i++)
    {
        flag = true;
        cin >> N[i];
        
        if (N[i] == 1)
        {
            flag = false;
        }
        for (int j = 2; j * j <= N[i]; j++)
        {
            if (N[i] % j == 0) // 소수면 나머지 0 안나오고 합성수면 최소한번 0 나오므로
            {
                flag = false;
            }
        }

        if (flag)
        {
            count++;
        }
    }

    cout << count;
    return 0;
}

// 핵심1: 모든 약수 중 가장 작은 수와 가장 큰 수는 각각 2와 어떤 수의 제곱근인 것
// 핵심2: 소수를 어떤 수로 나누면 나머지가 0이 아닌 것
// for문을 선언해서 j를 2부터 시작하게 하고(1은 약수 아님), j의 범위를 입력받은 수의 제곱근까지로 설정 -> 입력받은 수를 모든 j로 나눔
// 만약 입력받은 수를 j로 나눴을때 나머지가 0이면 입력받은 수는 합성수이므로 카운트 증가 안하고, 나머지 0 아니면 소수이므로 카운트 증가