#include <iostream>
using namespace std;

int arr[100000];
int tmp[100000];

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= right)
        tmp[k++] = arr[j++];

    for (int t = left; t <= right; t++)
        arr[t] = tmp[t];
}

void mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}