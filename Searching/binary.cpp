#include "../header.hpp"

using namespace std;

bool binarySearch(vector<int> data, int target, int left, int right) {
    if(right >= 1) {
        int mid=left + (right-left)/2;

        if(data.at(mid) == target) 
            return true;
        
        if(data.at(mid) > target)
            return binarySearch(data,target,left,mid-1);

        if(data.at(mid) < target) 
            return binarySearch(data,target,mid+1,right);
    }
    return false;
}

/*
REFERENSI KOMPLEKSITAS :

https://iq.opengenus.org/time-complexity-of-binary-search/
https://www.geeksforgeeks.org/complexity-analysis-of-binary-search/
*/