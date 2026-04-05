#include <bits/stdc++.h>
using namespace std;

unsigned int heap[200002]; // 최소 힙이므로 초기값을 매우 큰 값으로 설정
int heapsize = 0;

void insert(int x);
int remove();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 1; i <= 200001; i++) { // 배열 크기가 200002라면 존재하는 인덱스는 0~200001
        heap[i] = INT_MAX;
    }

    int n;
    unsigned int x;
    cin >> n;

    for (int i = 1; i <= n; i++) {
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

    for (int i = heapsize; i > 1; i = i / 2) {
        if (heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
        } else {
            break;
        }
    }
}

int remove() {
    int result;
    if (heapsize == 0) {
        return 0;
    }

    result = heap[1];
    heap[1] = heap[heapsize];
    heap[heapsize--] = INT_MAX;

    for (int i = 1; i <= heapsize;) {
        if (heap[i] < heap[i * 2] && heap[i] < heap[i * 2 + 1]) {
            break;
        }
        if (heap[i * 2] < heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i *= 2;
        } else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }
    
    return result;
}