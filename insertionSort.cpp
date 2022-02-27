#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

namespace insertionSort {
    void ascending(vector<int> data) {
        int key, j;

        for(int i=0; i<data.size(); i++) {
            key=data.at(i);
            j=i-1;

            while(j >= 0 && data.at(j) > key) {
                data.at(j+1)=data.at(j);
                j--;
            }
            data.at(j+1)=key;
        }
    }

    void descending(vector<int> data) {
        int key, j;

        for(int i=0; i<data.size(); i++) {
            key=data.at(i);
            j=i-1;

            while(j >= 0 && data.at(j) < key) {
                data.at(j+1)=data.at(j);
                j--;
            }
            data.at(j+1)=key;
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

    insertionSort::ascending(data);

    // End Function

    auto stop=high_resolution_clock::now();

    cout << "Data setelah sort = ";
    printData(data);

    auto duration=duration_cast<microseconds>(stop-start);

    cout << endl;
    cout << "Durasi Fungsi: " << duration.count() << " microseconds" << endl;
}