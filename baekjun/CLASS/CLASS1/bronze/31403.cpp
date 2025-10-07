#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::string;
using std::stoi;

int main()
{
    string a, b;
    int c;
    cin >> a >> b >> c;
    
    int A = stoi(a);
    int B = stoi(b);
    
    cout << A + B - c << '\n';

    a += b;
    int D = stoi(a);

    cout << D - c;

    return 0;
}