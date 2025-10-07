#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    int num;

    cin >> num;

    cout << "int a;" << '\n';
    cout << "int *ptr = &a;" << '\n';
    
    for (int i = 2; i <= num; i++)
    {
        if (i == 2)
        {
            cout << "int **ptr2 = &ptr;" << '\n';
            continue;
        }
        else
        {
            cout << "int ";
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }

            cout << "ptr" << i << " = &ptr" << i - 1 << ";" <<'\n';
        }
    }

    return 0;
}