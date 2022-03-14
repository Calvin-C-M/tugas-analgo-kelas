#include "lib.cpp"

void insertionSort(vector<int> &array, int n) {
    for(int i=1; i<n; i++) {
        int key=array.at(i);
        int index=i-1;

        while(index >= 0 && array.at(index) > key) {
            array.at(index+1)=array.at(index);
            index--;
        }
        array.at(index+1)=key;
    }
}

int main() {
    vector<int> data={};

    long long jumlahData=0;

    cout << "Masukkan jumlah data: "; cin >> jumlahData;

    isiData(data,jumlahData);

    auto start=high_resolution_clock::now();

    insertionSort(data,data.size());
    
    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Menggunakan insertion sort" << endl
         << "Durasi fungsi: " << duration.count() << " microseconds" << endl;
}