#include <iostream>
using namespace std;

int main()
{
    int SIZE1, SIZE2; // SIZE1: 행 개수 SIZE2: 열 개수
    cin >> SIZE1 >> SIZE2;
    int first[SIZE1][SIZE2], second[SIZE1][SIZE2], total[SIZE1][SIZE2];
    
    for (int i = 0; i < SIZE1; i++) // 열
    {
        for (int j = 0; j < SIZE2; j++) // 행
        {
            cin >> first[i][j];
        }
    }

    for (int i = 0; i < SIZE1; i++) // 열
    {
        for (int j = 0; j < SIZE2; j++) // 행
        {
            cin >> second[i][j];
        }
    }

    for (int i = 0; i < SIZE1; i++) // 열
    {
        for (int j = 0; j < SIZE2; j++) // 행
        {
            total[i][j] = first[i][j] + second[i][j];
        }
    }

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            cout << total[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}