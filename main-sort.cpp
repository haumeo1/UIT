#include <bits/stdc++.h>
#include "heap-sort.cpp"
#include "quick-sort.cpp"
#include "merge-sort.cpp"
using namespace std;
using namespace std::chrono;

// Tạo một dãy số thực ngẫu nhiên
vector<int> createRandomSequence(int length) {
    vector<int> sequence(length);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,1000000);
    for (int i = 0; i < length; i++) {
        sequence[i] = dis(gen);
    }
    return sequence;
    
}

int main() {
    auto start=high_resolution_clock::now();
    // Tạo dãy thứ nhất với thứ tự tăng dần
    vector<int> sequence1 = createRandomSequence(1000000);
    sort(sequence1.begin(), sequence1.end());

    // Tạo dãy thứ hai với thứ tự giảm dần
    vector<int> sequence2 = createRandomSequence(1000000);
    sort(sequence2.begin(), sequence2.end(), greater<double>());

    // Tạo 8 dãy còn lại với trật tự ngẫu nhiên
    vector<vector<int> > sequences(8);
    for (int i = 0; i < 8; i++) {
        sequences[i] = createRandomSequence(1000000);
        random_shuffle(sequences[i].begin(), sequences[i].end());
    }
    heapSort(sequence1,0);// hàm sắp xếp tăng dần
    heapSort(sequence2,0);//hàm sắp xêp giảm dần
    heapSort(sequences[3],0);//hàm ngẫu nhiên
    quickSort(sequence1,0,sequence1.size()-1);// hàm sắp xếp tăng dần
    quickSort(sequence2,0,sequence2.size()-1);//hàm sắp xêp giảm dần
    quickSort(sequences[3],0,sequenceso[3].size()-1);//hàm ngẫu nhiên
    iterativeMergeSort(sequence1);// hàm sắp xếp tăng dần
    iterativeMergeSort(sequence2);//hàm sắp xêp giảm dần
    iterativeMergeSort(sequences[3]);//hàm ngẫu nhiên


    
    
    

    
    auto stop= high_resolution_clock::now();
    auto time_count = duration_cast<microseconds>(stop - start);

    return 0;
}
