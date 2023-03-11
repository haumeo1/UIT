#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int currSize = 1; currSize < n; currSize *= 2) {
        for (int leftStart = 0; leftStart < n-1; leftStart += 2*currSize) {
            int mid = min(leftStart + currSize - 1, n-1);
            int rightEnd = min(leftStart + 2*currSize - 1, n-1);
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    iterativeMergeSort(arr);
    for (auto x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
