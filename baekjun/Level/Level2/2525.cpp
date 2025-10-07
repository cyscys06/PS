#include <iostream>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C;

    D = B + C;
    
    while (D >= 60)
    {
        if (D >= 60)
        {
            D -= 60;
            A += 1;
        }
        
        if (A == 24)
        {
            A = 0;
        }
    }
    cout << A << " " << D << '\n';
    

    return 0;
}