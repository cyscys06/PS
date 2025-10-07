#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::pair;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<bool> flag(26, true);

int main()
{
    string a;
    cin >> a;

    for (int i = 0; i < alphabet.size(); i++)
    {
        for (int j = 0; j < a.length(); j++)
        {
            if (alphabet[i] == a[j] && flag[i] == true) // 문자 서로 같고 알파벳 벡터에 대응되는 플래그가 디폴트(true)일때
            {
                cout << j << " ";
                flag[i] = false;
                break;
            }
        }

        if (flag[i] == true)
        {
            cout << -1 << " ";
        }
    }

    return 0;
}