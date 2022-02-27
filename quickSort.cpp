#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

namespace quickSort {
    int partition(vector<int> data, int low, int high) {
        int pivot=data.at(high);
        int i=low-1;

        for(int j=low; j<=high-1; j++) {
            if(data.at(j) < pivot) {
                i++;
                swap(data.at(i), data.at(j));
            }
        }
        swap(data.at(i+1), data.at(high));
        return i+1;
    }

    void ascending(vector<int> data, int low, int high) {
        if(low < high) {
            int pi=partition(data,low,high);
            ascending(data,low,pi-1);
            ascending(data,pi+1,high);
        }
    }

    void descending(vector<int> data, int low, int high) {
        // Belum kelar
        if(low < high) {
            int pi=partition(data,low,high);
            ascending(data,low,pi-1);
            ascending(data,pi+1,high);
        }
    }
}

void printData(vector<int> data) {
    for(int d: data) 
        cout << d << " ";
    cout << endl;
}

int main() {
    // Deklarasi variabel
    vector<int> data={};

    cout << "Data sebelum sort = "; 
    printData(data);

    auto start=high_resolution_clock::now();

    // Start Function

    quickSort::ascending(data,0,data.size()-1);

    // End Function

    auto stop=high_resolution_clock::now();

    cout << "Data setelah sort = "; 
    printData(data);

    auto duration=duration_cast<microseconds>(stop-start);

    cout << endl;
    cout << "Durasi Fungsi: " << duration.count() << " microseconds" << endl;

}