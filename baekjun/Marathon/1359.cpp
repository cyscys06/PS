#include <bits/stdc++.h>
using namespace std;

int factorial(int n);
int getCombination(int n, int r);

int main()
{
    cout.precision(12); // 출력 소수점 조절
    cout << fixed;

    int n, m, k, total = 0; // 전체 수, n개에서 뽑을 m개, 정답 일치하는 k개
    cin >> n >> m >> k;
        
    int totalCombination = getCombination(n, m); // n개에서 m개 뽑은 조합
    double result;
     
    for (int i = k; i <= m; i++)
    {
        int yesCombination = getCombination(m, i); // 당첨인 숫자 뽑는 조합(내가뽑은 m개에서 당첨숫자 k개 나오는 조합)
    
        int noCombination = getCombination(n - m, m - i); // 내가 안뽑은 숫자에서 당첨 아닌 숫자 나오는 조합(내가안뽑은 n - m개에서 당첨아닌숫자 m - k개 나오는 조합) 
        
        total += yesCombination * noCombination;
    }

    result = (double)total / (double)totalCombination;

    cout << result;

    return 0; 
}

int factorial(int n)
{
    if (n <= 1) // n이 음수인 경우까지 포함
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int getCombination(int n, int r)
{
    return factorial(n) / (factorial(n - r) * factorial(r));
}

// 조합 공식: n! / (n - r)! * r! 

// 핵심: 내가 m개 뽑은 수들은 복권에서 무조건 당첨될 숫자들의 모임으로 봐야함(실제론 아니지만 이렇게 생각하는게 이해하기 쉬움)
// 그중 2개의 당첨 숫자가 어떤 조합으로 당첨되는지가 조합으로 존재하므로 3개에서 2개 구하는 조합개수 구하기
// 나머지 당첨이 아닌 숫자(3 - 2 = 1)는 내가 안뽑은 숫자(즉, 당첨이 아닌 숫자)에서 1개를 구하는것
// 만약 내가뽑은 3개에서 당첨숫자 2개를 구하고 거기서 당첨아닌숫자 1개를 더구하면, 그건 곧 내가뽑은 3개에서 당첨숫자 3개를 고르는의미가 돼서 규칙 위반임