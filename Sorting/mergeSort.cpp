#include "../header.hpp"

void merge(vector<int> &data, int left, int mid, int right) {
    int subArrayLeft=mid-left+1;
    int subArrayRight=right-mid;

    vector<int> leftArray;
    vector<int> rightArray;

    for(int i=0; i<subArrayLeft; i++) 
        leftArray.push_back(data.at(left+i));

    for(int j=0; j<subArrayRight; j++) 
        rightArray.push_back(data.at(mid+1+j));

    int indexSubArrayLeft=0, indexSubArrayRight=0;
    int indexMergedArray=left;

    while(indexSubArrayLeft < subArrayLeft && indexSubArrayRight < subArrayRight) {
        if(leftArray.at(indexSubArrayLeft) <= rightArray.at(indexSubArrayRight)) {
            data.at(indexMergedArray)=leftArray.at(indexSubArrayLeft);
            indexSubArrayLeft++;
        } else {
            data.at(indexMergedArray)=rightArray.at(indexSubArrayRight);
            indexSubArrayRight++;
        }
        indexMergedArray++;
    }

    while(indexSubArrayLeft < subArrayLeft) {
        data.at(indexMergedArray)=leftArray.at(indexSubArrayLeft);
        indexSubArrayLeft++;
        indexMergedArray++;
    }

    while(indexSubArrayRight < subArrayRight) {
        data.at(indexMergedArray)=rightArray.at(indexSubArrayRight);
        indexSubArrayRight++;
        indexMergedArray++;
    }
}

void mergeSort(vector<int> &data, int begin, int end) {
    if(begin >= end) return;

    int mid=begin + ((end-begin)/2);
    mergeSort(data,begin,mid);
    mergeSort(data,mid+1,end);
    merge(data,begin,mid,end);
}