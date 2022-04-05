#include "../header.hpp"

bool linearSearch(vector<int> data, int target) {
    // bool found=false;
    for(int d: data) {
        if(d == target) 
            return true;
    }
    return false;
}

int main() {

}