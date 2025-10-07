#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

const int SIZE = 7;
int grams[] = {100, 50, 20, 10, 5, 2, 1}; 


int main()
{
    int N, left = 0, right = 0;

    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (left <= right)
        {
            left += A[i];
            continue;
        }
        else if (left > right)
        {
            right += A[i];
            continue;
        }
    }

    int gram = abs(left - right), count = 0; // 남은무게, 무게추 개수
    
    for (int i = 0; i < SIZE; i++)
    {
        if (gram >= grams[i])
        {
            count += gram / grams[i];
            gram %= grams[i];
        }

        if (gram == 0)
        {
            break;
        }
    }

    cout << count;
    
    return 0;
}