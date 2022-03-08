#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &array, int low, int high) {
    int pivot=array.at(high);
    int index=low-1;
    
    for(int i=low; i<=high; i++) {
        if(array.at(i) < pivot) {
            index++;
            swap(array.at(index),array.at(i));
        }
    }

    swap(array.at(index+1),array.at(high));
    return index+1;
}

void quickSort(vector<int> &array, int low, int high) {
    if(low < high) {
        int pi=partition(array,low,high);

        quickSort(array,low,pi-1);
        quickSort(array,pi+1,high);
    }
}