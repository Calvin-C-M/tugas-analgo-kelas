/*

JUDUL PROGRAM   : Tower Of Hanoi
NAMA            : Calvin Calfi Montolalu
NPM             : 140810200053
TANGGAL BUAT    : 26/02/2022
DESKRIPSI       : Menyelesaikan masalah tower of hanoi

*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void towerOfHanoi(int disks, char beginRod, char midRod, char finalRod) {
    if(disks == 0) return;

    towerOfHanoi(disks-1, beginRod, midRod, finalRod);

    cout << "Pindah piring " << disks << " dari tiang " << beginRod << " ke tiang " << finalRod << endl;

    towerOfHanoi(disks-1, midRod, beginRod, finalRod);
}

int main() {
    // Declare Variable

    int n=0;

    cout << "Jumlah Piring: "; cin >> n;

    auto start=high_resolution_clock::now();
    
    // Start function

    towerOfHanoi(n, 'A', 'B', 'C');

    // End function

    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);

    cout << endl;
    cout << "Durasi Fungsi: " << duration.count() << " microseconds" << endl;
}