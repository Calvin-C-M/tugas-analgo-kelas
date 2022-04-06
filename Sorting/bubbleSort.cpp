#include "../header.hpp"

void bubbleSort(vector<int> &data) {
    for(int i=0; i<data.size()-1; i++) 
        for(int j=0; j<data.size()-i-1; j++) 
            if(data.at(j) > data.at(j+1)) 
                swap(data.at(j),data.at(j+1));
}

/*
REFERENSI KOMPLEKSITAS: 

https://www.happycoders.eu/algorithms/bubble-sort/#Bubble_Sort_Time_Complexity
https://www.simplilearn.com/tutorials/data-structure-tutorial/bubble-sort-algorithm
*/