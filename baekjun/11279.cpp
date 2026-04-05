#include <bits/stdc++.h>
using namespace std;

int heap[200001] = {0, };
// 문제점: heap 배열 크기가 100001이었을때, remove 함수에서 i = 50001 이상인 경우 지정되지 않은 배열 범위에 접근하게 되므로 오류가 발생함
// 해결(AI 도움 받음): 배열 크기를 (heap에 최대로 저장 가능한 원소 개수) * + 1 = 200001로 지정함
int heapsize = 0;

void insert(int x);
int remove();

int main() {
    // 수정: 시간초과 방지를 위해 코드 추가
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        
        if (x > 0) {
            insert(x);
        } else if (x == 0) {
            cout << remove() << '\n';
        }
    }

    return 0;
}

void insert(int x) {
    heap[++heapsize] = x;

    for (int i = heapsize; i > 1; i /= 2) { // 수정: i/2 -> i /= 2
        if (heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
        } else {
            break;
        }
    }
}

int remove() {
    if (heapsize == 0) {
        return 0;
    }

    int result = heap[1]; 
    heap[1] = heap[heapsize]; 
    heap[heapsize--] = 0; 

    for (int i = 1; i <= heapsize;) {
        if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) {
            break;
        } 
        if (heap[i * 2] > heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i *= 2;
        } else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }

    return result;
}