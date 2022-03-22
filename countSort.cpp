#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void countSort(vector<int> &data) {
    int max=*max_element(data.begin(),data.end());
    int min=*min_element(data.begin(),data.end());
    int range=max-min+1;

    vector<int> count(range), output(data.size());
    for(int d: data) 
        count[d-min]++;

    for(int i=0; i<count.size(); i++) 
        count[i]+=count[i-1];
    
    for(int i=data.size()-1; i>=0; i--) {
        output[count[data[i]-min-1]]=data[i];
        count[data[i]-min]--;
    }

    for(int i=0; i<data.size(); i++) 
        data[i]=output[i];
}

void printData(vector<int> data) {
    for(int d: data) 
        cout << d << "  ";
    cout << endl;
}

int main() {
    vector<int> array={3,6,4,1,3,5,3};
    countSort(array);
    printData(array);
}