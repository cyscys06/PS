#include <bits/stdc++.h>
using std::cout;
using std::cin;

void Snail31(int a);
void Snail13(int a);
void Snail111(int a);

int main()
{
    int a;
    cin >> a;

    Snail31(a);
    for (int i = 0; i < 3; i++)
    {
        Snail111(a);
    }
    Snail13(a);

    return 0;
}

void Snail31(int a) // @@@ @
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a * 3; j++)
        {
            cout << "@";
        }
        for (int j = 0; j < a; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < a; j++)
        {
            cout << "@";
        }
        cout << '\n';
    }
}

void Snail13(int a)
{   
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cout << "@";
        }
        for (int j = 0; j < a; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < a * 3; j++)
        {
            cout << "@";
        }
        cout << '\n';
    }
}

void Snail111(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < a; j++)
            {
                cout << "@";
            }
            for (int j = 0; j < a; j++)
            {
                cout << " ";
            }
        }
        
        for (int j = 0; j < a; j++)
        {
            cout << "@";
        }
        cout << '\n';
    }
}

