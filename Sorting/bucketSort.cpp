#include "../header.hpp"

void bucketSort(vector<float> &data) {
    vector<float> bucket[data.size()];

    for(int i=0; i<data.size(); i++) {
        int bi=data.size()*data.at(i);
        bucket[bi].push_back(data.at(i));
    }

    for(int i=0; i<data.size(); i++) 
        sort(bucket[i].begin(),bucket[i].end());
    
    int index=0;
    for(int i=0; i<data.size(); i++) 
        for(int j=0; j<bucket[i].size(); j++)
            data.at(index++)=bucket[i][j];
}