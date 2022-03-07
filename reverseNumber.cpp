#include <iostream>

using namespace std;

int reverse(int n) {
    if(n < 10) return n;
    else {
        cout << n % 10;
        reverse(n/10);
    }
}
