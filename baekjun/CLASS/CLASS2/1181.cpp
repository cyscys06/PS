#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, max = 0;
    cin >> n;

    vector<string> arr(n);
    
    // 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 중복제거
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    n = arr.size();
    // 정렬
    for (int i = 0; i < n - 1; i++) {
        int temp = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[temp].length() > arr[j].length()) {
                temp = j;
            } else if (arr[temp].length() == arr[j].length()) { // 두 문자열 길이 같을때
                // strcmp 사용 안하고, str끼리 바로 비교연산자 사용 가능
                // 작은쪽이 사전순으로 앞에 있으므로, 작은 문자열을 앞에 놓기
                if (arr[temp] > arr[j]) {
                    temp = j;
                }
            }
        }
        swap(arr[i], arr[temp]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}