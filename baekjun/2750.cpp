#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j]) 
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            // 현재 인덱스의 값보다 더 작은 값이 있으면 둘이 서로 교체
        }
        cout << arr[i] << '\n';
    }   

    return 0;
}

// 선택 정렬 핵심: 큰 for문은 전체 배열을 순회하는 반복문이고,
// 안에 있는 for문은 i번째 인덱스에서 시작해서 그 다음 인덱스들 중 최솟값을 찾아서 그걸 i번째 인덱스에 넣는 반복문
// j = i + 1; j < n; j++ 라 하면 i의 다음 인덱스부터 시작해서 모든 인덱스를 순회하므로 결국 최솟값이 나올수밖에 없음
// 

// https://hsp1116.tistory.com/33