#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num = 665, count = 0;
    cin >> n;

    while (true)
    {
        num += 1;
        string snum = to_string(num);
        if (snum.find("666") != string::npos) 
        {
            count++;
            if (count == n)
            {
                cout << num;
                return 0;
            }
        }
        // 문자열에서 특정 값 찾는 find
        // 못찾으면 npos라는 쓰레기값 반환하는데, 
        // npos가 아닌경우 666이 문자열 안에 들어있는 것이므로 count 증가
    }
    return 0;
}

// 핵심: 숫자를 1 증가시킨 동시에, 숫자를 문자열로 변환해서 그 문자열 안에 666(종말수 최소조건)이 있는지를 비교(find)
// 666이 있다면 그 666이 존재하는 문자열은 영화 시리즈 중 하나가 될 수 있으므로 카운트를 1 증가(영화 하나 나온걸로 간주)
// 카운트가 n이 되는 순간은 n번째 영화를 의미하므로, 그때의 숫자가 n번째 영화가 될 것


// 어떤 숫자에 특정 숫자가 연속적으로 들어있는지를 확인하려면, 숫자를 문자열로 바꾸고 find함수를 사용하면 좋음