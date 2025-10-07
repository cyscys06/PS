#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    int right = 1;
    int i = 1;
    while (1)
    {
        right += 6 * i;

        if (n <= right)
        {
            cout << i + 1;
            break;
        }
        i++;
    }
    return 0;
}

// 핵심: 1개의 육각형 방마다 방의 개수가 점점 6개씩 늘어남
// -> 현재 최대값 += 이전 최대값 * i번째로 설정하기
// 왼쪽, 오른쪽 값 만들어서 그 안에 있는 숫자가 몇번째 방인지 알아내도 상관없지만 최댓값만 비교해서 최댓값보다 작을때 몇번째 방인지 알아도 됨(최솟값 필요 X)
