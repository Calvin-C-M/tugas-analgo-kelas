#include "../header.hpp"

namespace SelectionSort {
    void min(vector<int> &data) {
        int minIndex=0;

        for(int i=0; i<data.size()-1; i++) {
            minIndex=i;
            for(int j=i+1; j<data.size(); j++) 
                if(data.at(j) < data.at(minIndex))
                    minIndex=j;
            
            swap(data.at(minIndex),data.at(i));
        }
    }

    void max(vector<int> &data) {
        int maxIndex=0;
        for(int i=0; i<data.size()-1; i++) {
            maxIndex=i;
            for(int j=i+1; j<data.size(); j++) 
                if(data.at(j) > data.at(maxIndex))
                    maxIndex=j;
            
            swap(data.at(maxIndex),data.at(i));
        }
    }
}

/*
REFERENSI KOMPLEKSITAS: 

https://iq.opengenus.org/time-complexity-of-selection-sort/
https://www.gatevidyalay.com/selection-sort-selection-sort-algorithm/
*/