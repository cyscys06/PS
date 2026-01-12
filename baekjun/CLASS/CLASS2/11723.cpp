#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> S(21, 0);

    int n, x;
    string str;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;

        if (str == "add") {
            cin >> x;
            if (S[x] == 0) {
                S[x] = 1;
            }
        } else if (str == "remove") {
            cin >> x;
            if (S[x] == 1) {
                S[x] = 0;
            }
        } else if (str == "check") {
            cin >> x;
            cout << S[x] << "\n";
        } else if (str == "toggle") {
            cin >> x;
            if (S[x] == 1) {
                S[x] = 0;
            } else {
                S[x] = 1;
            }
        } else if (str == "all") {
            for (int j = 1; j < S.size(); j++) {
                S[j] = 1;
            }
        } else if (str == "empty") {
            for (int j = 1; j < S.size(); j++) {
                S[j] = 0;
            }
        }
        
    }
}
// 범위기반 for문
        // ex) for (int j : S) {
        //        j = 1;
        //     }
        // for문 축소되는 장점 있지만, 자료구조의 인덱스에 대한 정보 알수없고, 자료구조 요소 값을 변경 못하는 단점 있음