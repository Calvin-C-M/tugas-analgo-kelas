#include "../header.hpp"

void insertionSort(vector<int> &data) {
    int key=0;

    for(int i=0; i<data.size(); i++) {
        key=data.at(i);
        int j=i-1;

        while(j >= 0 && data.at(j) > key) {
            data.at(j+1)=data.at(j);
            j--;
        }
        data.at(j+1)=key;
    }
}

/*
REFERENSI KOMPLEKSITAS: 

https://brilliant.org/wiki/insertion/#:~:text=When%20analyzing%20algorithms%2C%20the%20average,list%20is%20already%20mostly%20sorted.
https://iq.opengenus.org/insertion-sort-analysis/
*/