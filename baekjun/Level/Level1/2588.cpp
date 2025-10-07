#include <iostream>
using namespace std;
const int SIZE = 3;
int main()
{
    int a, b;
    cin >> a >> b;
    
    int b1 = (b / 100);
    int b2 = (b / 10) % 10;
    int b3 = (b % 10);
    
    cout << a * b3 << '\n';
    cout << a * b2 << '\n';
    cout << a * b1 << '\n';
    cout << a * b;
    return 0;
}