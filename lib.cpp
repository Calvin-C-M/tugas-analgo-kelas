#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void isiData(vector<int> &data, long long jumlah) {
    for(int i=1; i<=jumlah; i++) {
        int randomData=rand()%100+1;
        data.push_back(randomData);
    }
}

void printData(vector<int> data) {
    for(int d: data)
        cout << d << "  ";
}
