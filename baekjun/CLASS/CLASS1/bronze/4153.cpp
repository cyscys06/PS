#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

bool isright(int a, int b, int c);

int main()
{
    int a, b, c;
    vector<vector<int>> A;
    
    while (cin >> a >> b >> c) 
    {
        if (a == 0) // 0 입력받으면 입력 종료
        {
            break;
        }

        A.push_back({a, b, c}); 
        
    }

    for (int i = 0; i < A.size(); i++)
    {
        sort(A[i].begin(), A[i].end()); // 검사 전 정렬

        if (isright(A[i][0], A[i][1], A[i][2]))
        {
            cout << "right";
        }
        else
        {
            cout << "wrong";
        }
        cout << '\n';
    }

    return 0;
}

bool isright(int a, int b, int c)
{
    if ((a * a) + (b * b) == (c * c))
    {
        return true;
    }
    else
    {
        return false;
    } 
}