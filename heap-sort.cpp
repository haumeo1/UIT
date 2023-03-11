#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr, int N, int i)
{

    
    int largest = i;

    
    int l = 2 * i + 1;

    
    int r = 2 * i + 2;

    
    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    
    if (largest != i) {
        swap(arr[i], arr[largest]);

        
        heapify(arr, N, largest);
    }
}
void heapSort(vector<int>& arr, int N)
{
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        int largest = 0;
        int l, r;
        while (true) {
            l = 2 * largest + 1;
            r = 2 * largest + 2;
            if (l < i && arr[l] > arr[largest])
                largest = l;
            if (r < i && arr[r] > arr[largest])
                largest = r;
            if (largest == i)
                break;
            swap(arr[i], arr[largest]);
        }
    }
}
