#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int separateSum;
    int res = 0;
    for (int i = 1; i < n; i++)
    {   
        separateSum = 0; 
        int j = i;
        while (j > 0)
        {
            separateSum += j % 10;
            j /= 10; 
        }

        if (i + separateSum == n)
        {
            res = i;
            break;
        }
    }
    cout << res;
    return 0;
}

// 핵심: 입력받은 분해합이 나오는 원본 수를 모르지만 분해합보다 작은 어떤 자연수인것은 알고 있으므로, 
// 1부터 분해합보다 작은 수까지 반복하면서 i의 자릿수를 각각 구해서 더한값 + i가 분해합과 같으면 i가 원본 수임