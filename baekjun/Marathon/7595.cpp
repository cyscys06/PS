#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

void pyramid(int num);

int main()
{
    unsigned int n;
    vector<int> num;
    while(cin >> n)
    {
        num.push_back(n);
    }
    
    for (int i = 0; i < num.size(); i++)
    {
        pyramid(num[i]);
    } 

    return 0;
}

void pyramid(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }   
}