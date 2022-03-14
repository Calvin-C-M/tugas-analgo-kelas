#include "lib.cpp"

void merge(vector<int> &array, int left, int mid, int right) {
    int subArrayLeft=mid-left+1;
    int subArrayRight=right-mid;

    vector<int> leftArray;
    vector<int> rightArray;

    for(int i=0; i<subArrayLeft; i++) 
        leftArray.push_back(array.at(left+i));

    for(int j=0; j<subArrayRight; j++) 
        rightArray.push_back(array.at(mid+1+j));

    int indexSubArrayLeft=0, indexSubArrayRight=0;
    int indexMergedArray=left;

    while(indexSubArrayLeft < subArrayLeft && indexSubArrayRight < subArrayRight) {
        if(leftArray.at(indexSubArrayLeft) <= rightArray.at(indexSubArrayRight)) {
            array.at(indexMergedArray)=leftArray.at(indexSubArrayLeft);
            indexSubArrayLeft++;
        } else {
            array.at(indexMergedArray)=rightArray.at(indexSubArrayRight);
            indexSubArrayRight++;
        }
        indexMergedArray++;
    }

    while(indexSubArrayLeft < subArrayLeft) {
        array.at(indexMergedArray)=leftArray.at(indexSubArrayLeft);
        indexSubArrayLeft++;
        indexMergedArray++;
    }

    while(indexSubArrayRight < subArrayRight) {
        array.at(indexMergedArray)=rightArray.at(indexSubArrayRight);
        indexSubArrayRight++;
        indexMergedArray++;
    }
}

void mergeSort(vector<int> &array, int begin, int end) {
    if(begin >= end) return;
    int mid=begin+((end-begin)/2);

    mergeSort(array,begin,mid);
    mergeSort(array,mid+1,end);
    merge(array,begin,mid,end);
}

int main() {
    vector<int> data={};
    long long jumlahData=0;

    cout << "Masukkan jumlah data: "; cin >> jumlahData;

    isiData(data,jumlahData);

    auto start=high_resolution_clock::now();

    mergeSort(data,0,data.size()-1);

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << "Menggunakan merge sort" << endl
         << "Durasi fungsi: " << duration.count() << " microseconds" << endl;
}