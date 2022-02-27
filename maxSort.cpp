#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

namespace maxSort {
    void ascending(vector<int> data) {
        int U=data.size()-1;

        for(int i=0; i<U; i++) {
            int max=0;
            for(int j=1; j<=U; j++) {
                if(data.at(j) > data.at(max))
                    max=j;
            }
            swap(data.at(U), data.at(max));
            U--;
        }
    }

    void descending(vector<int> data) {
        int U=data.size()-1;

        for(int i=0; i<U; i++) {
            int max=0;
            for(int j=1; j<=U; j++) {
                if(data.at(j) < data.at(max))
                    max=j;
            }
            swap(data.at(U), data.at(max));
            U--;
        }

    }
}

void printData(vector<int> data) {
    for(int d: data) 
        cout << d << " ";
    cout << endl;
}

int main() {
    vector<int> data={};

    cout << "Data sebelum sort = ";
    printData(data);

    auto start=high_resolution_clock::now();

    maxSort::ascending(data);

    auto stop=high_resolution_clock::now();

    cout << "Data setelah sort = ";
    printData(data);

    auto duration=duration_cast<microseconds>(stop-start);

    cout << endl;
    cout << "Durasi Fungsi: " << duration.count() << " microseconds" << endl;

}