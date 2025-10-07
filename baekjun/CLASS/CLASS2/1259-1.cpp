#include <iostream>
using namespace std;

int main()
{
    int num;
    int c[5];
    bool flag = true;

    cin >> num;

    int i = 0;
    while (num > 0)
    {      
        c[i] = num % 10;
        num /= 10;
        i++;
    }

    for (int j = 0; j < i / 2; j++)
    {
        if (c[j] != c[i - j - 1])
        {
            flag = false;
        }
    }

    if (flag == true)
    {
        cout << "yes";
    }
    else 
    {
        cout << "no";
    }
}