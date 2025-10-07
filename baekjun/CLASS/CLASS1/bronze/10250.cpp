#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int main()
{
    int t, h, w, n, y, x; // 테스트케이스, 호텔의 층 수, 각 층의 방 수, N번째 손님, 호실 앞자리, 호실 뒷자리

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;

        y = n % h;
        x = n / h + 1;

        if (y == 0) // 꼭대기층인 경우
        {
            y = h;
            x -= 1;
        }

        if (x < 10)
        {
            cout << y << 0 << x;
        }
        else
        {
            cout << y << x;
        }

        cout << '\n';
    }

    return 0;
}