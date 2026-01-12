#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isGroup = true;
        int vis[26] = {0, };
        for (int j = 0; j < arr[i].size(); j++) {
            int index = arr[i][j] - 'a';
            if (vis[index] == 0) { // 처음보는 알파벳이면 
                vis[index] = 1;
            } else if (vis[index] == 1) { // 이미 본 알파벳[']=\이면
                if (arr[i][j - 1] != arr[i][j]) { // 이전 알파벳과 다르면
                    isGroup = false;
                }
            }
        }

        if (isGroup) {
            count++;
        }
    }

    cout << count;

    return 0;
}