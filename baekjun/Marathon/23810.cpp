#include <iostream>
using std::cout;
using std::cin;

int main()
{
    int num;
    cin >> num;

    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < num; b++)
        {
            for (int c = 0; c < num * 5; c++)
            {
                cout << "@";
            }

            cout << '\n';
        }

        for (int d = 0; d < num; d++)
        {
            for (int e = 0; e < num; e++)
            {
                cout << "@";
            }

            cout << '\n';
        }
    }

    for (int f = 0; f < num; f++)
        {
            for (int g = 0; g < num; g++)
            {
                cout << "@";
            }

            cout << '\n';
        }

    
    return 0;
}