#include <iostream>
#include <vector>

using namespace std;

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