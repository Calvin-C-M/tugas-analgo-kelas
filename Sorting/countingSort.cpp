#include "../header.hpp"

int maxElement(vector<int> data) {
    int value=0;
    for(int d: data) {
        if(value < d) 
            value=d;
    }
    return value;
}

int minElement(vector<int> data) {
    int value=maxElement(data);
    for(int d: data) {
        if(value > d) 
            value=d;
    }
    return value;
}

void countSort(vector<int> &data) {
    int max=maxElement(data);
    int min=minElement(data);
    int range=max-min+1;

    vector<int> count(range), output(data.size());
    for(int d: data) 
        count[d-min]++;

    for(int i=1; i<count.size(); i++) 
        count[i]+=count[i-1];
    
    for(int i=data.size()-1; i>=0; i--) {
        output[count[data[i]-min]-1]=data[i];
        count[data[i]-min]--;
    }

    for(int i=0; i<data.size(); i++) 
        data[i]=output[i];
}

/*
REFERENSI KOMPLEKSITAS: 

https://iq.opengenus.org/time-and-space-complexity-of-counting-sort/#:~:text=The%20time%20complexity%20of%20counting%20sort%20algorithm%20is%20O(n,of%20values%20to%20be%20sorted.
*/