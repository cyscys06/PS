#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;
using std::fixed;

int main()
{  
    cout.precision(16);
    cout << fixed;
    int N, L, H;
    double T = 0, F; 
    // 평가하는사람 수, 최저점수 개수, 최대점수 개수, 모든 평가점수 합, 최종점수

    cin >> N >> L >> H;
    vector<double> moviereview(N);

    for (int i = 0; i < N; i++)
    {
        cin >> moviereview[i];
        T += moviereview[i];
    }
    sort(moviereview.begin(), moviereview.end()); 
    // 배열의 이름은 배열의 첫번째 원소의 주소

    for (int i = 0; i < L; i++)
    {
        T -= moviereview[i];
    }

    for (int i = 0; i < H; i++)
    {
        T -= moviereview[moviereview.size() - 1 - i];
    }

    F = T / (N - L - H);

    cout << (double)F;
    return 0;
}

// https://passwords.google.com/