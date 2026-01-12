#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> arr(3);
    int th;
    int realnum;
    bool flag;
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i];

        flag = true;
        for (int j = 0; j < arr[i].size(); j++) {
            int num = arr[i][j] - '0';
            if (num > 9 || num < 0) {
                flag = false;
            }
        }

        if (flag) {
            th = i;
            realnum = stoi(arr[i]);
            break;
        }
    }

    int v = 3 - th;
    realnum += v;
    if (realnum % 3 == 0 && realnum % 5 == 0) {
        cout << "FizzBuzz";
    } else if (realnum % 3 != 0 && realnum % 5 == 0) {
        cout << "Buzz";
    } else if (realnum % 3 == 0 && realnum % 5 != 0) {
        cout << "Fizz";
    } else {
        cout << realnum;
    }

    return 0;
}