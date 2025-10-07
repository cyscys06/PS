#include <iostream>
using namespace std;
const int a = 45;

int main()
{
    int h, m;
    cin >> h >> m;

    if (m >= a)
    {
        cout << h << " " << m - a << "\n";
    }
    else if (!(h == 0) && m < a)
    {
        cout << h - 1 << " " << 60 - (a - m) << "\n";
    }
    else if (h == 0 && m < a)
    {
        cout << 23 << " " << 60 - (a - m) << "\n";
    }

    return 0;
}