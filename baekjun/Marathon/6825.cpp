#include <bits/stdc++.h>
using std::cout;
using std::cin;

int main()
{
    double w, h; // 몸무게, 키
    cin >> w >> h;

    double BMI = w / (h * h);

    if (BMI > 25)
    {
        cout << "Overweight" << '\n';
    }
    else if (BMI <= 25 && BMI >= 18.5)
    {
        cout << "Normal weight" << '\n';
    }
    else if (BMI < 18.5)
    {
        cout << "Underweight" << '\n';
    }

    return 0;
}