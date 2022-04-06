#include "../header.hpp"

bool linearSearch(vector<int> data, int target) {
    for(int d: data) {
        if(d == target) 
            return true;
    }
    return false;
}

/*
REFERENSI KOMPLEKSITAS :

https://iq.opengenus.org/time-complexity-of-linear-search/
https://www.geeksforgeeks.org/analysis-of-algorithms-set-2-asymptotic-analysis/

*/