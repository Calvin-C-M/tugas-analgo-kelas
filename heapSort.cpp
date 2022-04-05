#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(vector<int> &data, int n, int i) {
    int max=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left < n && data.at(left) > data.at(max)) 
        max=left;

    if(right < n && data.at(right) > data.at(max)) 
        max=right;

    if(max != i) {
        swap(data.at(i),data.at(max));
        heapify(data,n,max);
    }
}

void heapSort(vector<int> &data, int n) {
    for(int i=n/2-1; i >= 0; i--)   
        heapify(data,n,i);
    for(int i=n-1; i > 0; i--) {
        swap(data.at(0),data.at(i));
        heapify(data,i,0);
    }
}

void printData(vector<int> data) {
    for(int d: data) 
        cout << d << "  ";
    cout << endl;
}

int main() {
    vector<int> jumlahData={50,100,500,1000,5000};

    for(int jumlah: jumlahData) {
        vector<int> data={};

        for(int i=0; i<jumlah; i++) {
            int temp=rand()%100;
            data.push_back(temp);
        }

        auto start=high_resolution_clock::now();

        heapSort(data,data.size());

        auto stop=high_resolution_clock::now();

        auto duration=duration_cast<microseconds>(stop-start);

        cout << "Jumlah data = " << jumlah << endl
            << "Waktu run time = " << duration.count() << " microseconds" << endl;
    }
}