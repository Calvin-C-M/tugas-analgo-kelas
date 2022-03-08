#include <iostream>
#include <vector>
#include <chrono>

#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "insertionSort.cpp"

using namespace std;
using namespace std::chrono;

void isiData(vector<int> &data, long long jumlah) {
    for(int i=1; i<=jumlah; i++) {
        int randomData=rand()%100+1;
        data.push_back(randomData);
    }
}

void printData(vector<int> data) {
    for(int d: data)
        cout << d << "  ";
}

void menu(vector<int> data) {
    int pil=0;

    printf("Sorting dengan menggunakan metode\n");
    printf("1. Merge Sort       3. Quick Sort\n");
    printf("2. Insertion Sort\n");
    cout << "Pilihan: "; cin >> pil;

    switch(pil) {
        
    }
}

void printInsertionSortTime(vector<int> data) {
    auto start=high_resolution_clock::now();

    insertionSort(data,data.size());
    
    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Menggunakan insertion sort" << endl
         << "Durasi fungsi: " << duration.count() << " microseconds" << endl;
}

void printMergeSortTime(vector<int> data) {
    auto start=high_resolution_clock::now();

    mergeSort(data,0,data.size()-1);

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Menggunakan merge sort" << endl
         << "Durasi fungsi: " << duration.count() << " microseconds" << endl;
}

void printQuickSortTime(vector<int> data) {
    auto start=high_resolution_clock::now();

    quickSort(data,0,data.size()-1);

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Menggunakan quick sort" << endl
         << "Durasi fungsi: " << duration.count() << " microseconds" << endl;
}

int main() {
    long long jumlahData=0;
    vector<int> data;

    cout << "Masukkan jumlah data: "; cin >> jumlahData;

    isiData(data, jumlahData);

    menu(data);
}