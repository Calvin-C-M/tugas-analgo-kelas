#include "../header.hpp"

int partition(vector<int> &data, int low, int high) {
    int pivot=data.at(high);
    int i=low-1;

    for(int j=low; j<=high; j++) {
        if(data.at(j) < pivot) {
            i++;
            swap(data.at(i),data.at(j));
        }
    }
    swap(data.at(i+1),data.at(high));
    return i+1;
}

void quickSort(vector<int> &data, int low, int high) {
    if(low < high) {
        int pi=partition(data,low,high);

        quickSort(data,low,pi-1);
        quickSort(data,pi+1,high);
    }
}

/*
REFERENSI KOMPLEKSITAS: 

https://www.javatpoint.com/quick-sort
https://iq.opengenus.org/time-and-space-complexity-of-quick-sort/
*/