#include<iostream>
#define bias 10000000
using namespace std;

int arr[20000001] = {0};

int main() {

    int SIZE;
    int v;

    scanf("%d", &SIZE);
    for (int i=0; i<SIZE; i++) {

        scanf("%d", &v);
        arr[v+bias]++;
    }

    scanf("%d", &SIZE);

    for (int i=0; i<SIZE; i++) {
        scanf("%d", &v);
        cout << arr[v+bias] << " ";
    }

    return 0;
}
