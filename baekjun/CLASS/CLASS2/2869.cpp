#include <iostream>
using namespace std;

int main() {
    int a, b, v; // 낮에 올라가는 높이, 밤에 내려가는 높이, 총 올라가야 할 높이
    
    cin >> a >> b >> v;

    int count = (v - a) / (a - b);
    if ((v - a) % (a - b) == 0) { // 나머지 0인지 0 아닌지 검사
        count += 1; // 0이면 1만추가
    } else {
        count += 2; // 0 아니면 2 추가
    }

    cout << count;
    return 0;
}