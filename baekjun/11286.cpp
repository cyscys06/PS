#include <bits/stdc++.h>
using namespace std;

int heap[200002];
int heapsize = 0;

void insert(int x);
int remove();

int main() {
    int n, x;

    for (int i = 1; i <= 200001; i++) {
        heap[i] = INT_MAX;
    }
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x != 0) {
            insert(x);
        } else {
            cout << remove() << '\n';
        }
    } 

    return 0;
}

void insert(int x) {
    heap[++heapsize] = x;

    for (int i = heapsize; i > 1; i /= 2) { // i = 1인 경우 이미 루트 노드이므로 더이상 부모 노드가 존재하지 않음
        if (abs(heap[i]) < abs(heap[i / 2])) { // 절댓값 같아도 그냥 넘어감
            swap(heap[i], heap[i / 2]);
        } else if (abs(heap[i]) == abs(heap[i / 2])) {
            if (heap[i] < heap[i / 2]) {
                swap(heap[i], heap[i / 2]);
            } else {
                break;
            }
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
    heap[heapsize--] = INT_MAX;

    for (int i = 1; i <= heapsize;) {
        if (abs(heap[i]) < abs(heap[i * 2]) && abs(heap[i]) < abs(heap[i * 2 + 1])) {
            break;
        }
        if (abs(heap[i * 2]) < abs(heap[i * 2 + 1])) {
            swap(heap[i], heap[i * 2]);
            i *= 2;
        } else if (abs(heap[i * 2]) == abs(heap[i * 2 + 1])) {
            if (heap[i * 2] < heap[i * 2 + 1]) {
                swap(heap[i], heap[i * 2]);
                i *= 2;
            } else {
                swap(heap[i], heap[i * 2 + 1]);
                i = i * 2 + 1;
            }
        } else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }

    return result;
}
