#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    int a, b;    
    bool flag = true;
    cin >> a;
        
    if (a == 1) // 첫입력 1이면
    {
        for (int i = 0; i < 7; i++)
        {
            b = a + 1;
            cin >> a;
            
            if (!(b - a == 0))
            {
                flag = false;
            }
        }

        if (flag == true)
        {
            cout << "ascending";
        }
        else
        {
            cout << "mixed";
        }
    }
    else if (a == 8) // 첫입력 8이면
    {
        for (int i = 0; i < 7; i++)
        {
            b = a - 1;
            cin >> a;
            
            if (!(b - a == 0))
            {
                flag = false;
            }
        }

        if (flag == true)
        {
            cout << "descending";
        }
        else
        {
            cout << "mixed";
        }
    }
    else // 첫입력 1, 8 아닌경우
    {
        cout << "mixed";
    }

    return 0;
}