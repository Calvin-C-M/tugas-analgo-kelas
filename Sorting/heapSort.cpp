#include "../header.hpp"

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

/*
REFERENSI KOMPLEKSITAS: 

https://www.happycoders.eu/algorithms/heapsort/
https://iq.opengenus.org/time-complexity-of-heap-sort/
*/