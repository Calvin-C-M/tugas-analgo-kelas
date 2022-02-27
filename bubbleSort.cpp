#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

namespace bubbleSort {
    void ascending(vector<int> data) {
        for(int i=0; i<data.size()-1; i++) 
            for(int j=0; j<data.size()-i-1; j++) 
                if(data.at(j) > data.at(j+1)) 
                    swap(data.at(j), data.at(j+1));
    }

    void descending(vector<int> data) {
        for(int i=0; i<data.size()-1; i++) 
            for(int j=0; j<data.size()-i-1; j++) 
                if(data.at(j) < data.at(j+1)) 
                    swap(data.at(j), data.at(j+1));
    }
}

void inputData(vector<int> data, int amount) {
    for(int i=0; i<amount; i++) {
        int temp=0;
        cout << "Data ke-" << i << " : "; cin >> temp;
        data.push_back(temp);
    }
}

void printData(vector<int> data) {
    for(int d: data)
        cout << d << "  ";
    cout << endl;
}

int main() {

    vector<int> data={};

    cout << "Data sebelum sort = ";
    printData(data);

    auto start=high_resolution_clock::now();

    // Start Function

    bubbleSort::ascending(data);

    // End Function

    auto stop=high_resolution_clock::now();

    cout << "Data setelah sort = ";
    printData(data);

    auto duration=duration_cast<microseconds>(stop-start);

    cout << endl;
    cout << "Durasi Fungsi: " << duration.count() << " microseconds" << endl;

}