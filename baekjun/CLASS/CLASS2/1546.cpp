#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout.precision(12);
    cout << fixed;

    int n, max = 0;
    cin >> n;
    vector<double> arr(n);

    for (int i = 0; i < n; i++)
    {
        
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    double total = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] / max) * 100;
        total += arr[i];
    }

    double average = total / n;
    cout << average;

    return 0;
}