#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main()
{
    string a;
    bool flag = true;
    cin >> a;

    if (a.length() == 1 || a.length() == 2) // 수열 길이 1이나 2면 반드시 등차수열
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
        return 0;
    }

    vector<int> S(a.length());

    for (int i = 0; i < a.length(); i++)
    {
        S[i] = a[i] - '0'; // 원본 숫자 S 벡터에 저장
    }

    for (int i = 0; i < S.size() - 2; i++)
    {
        if (!(S[i + 1] - S[i] == S[i + 2] - S[i + 1])) // 한번이라도 다르면
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    }
    else
    {
        cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
    }

    return 0;
}
