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

int main() {

}