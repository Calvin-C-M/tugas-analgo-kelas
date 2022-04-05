#include "../header.hpp"

void bubbleSort(vector<int> &data) {
    for(int i=0; i<data.size()-1; i++) 
        for(int j=0; j<data.size()-i-1; j++) 
            if(data.at(j) > data.at(j+1)) 
                swap(data.at(j),data.at(j+1));
}

int main() {

}