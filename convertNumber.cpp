/*

JUDUL PROGRAM   : Convert Number
NAMA            : Calvin Calfi Montolalu
NPM             : 140810200053
TANGGAL BUAT    : 28/02/2022
DESKRIPSI       : Mengonversikan angka menjadi tulisan

*/

#include <iostream>

using namespace std;

bool inRange(int number, int min, int max) {
    return number >= min && number <= max;
}

string satuan(int n) {
    switch(n) {
        case 1: return "Satu";
        case 2: return "Dua";
        case 3: return "Tiga";
        case 4: return "Empat";
        case 5: return "Lima";
        case 6: return "Enam";
        case 7: return "Tujuh";
        case 8: return "Delapan";
        case 9: return "Sembilan";
    }
    return "Error";
}

void tulisan(int angka) {
    if(angka <= 11) cout << satuan(angka) << " ";
    else if(angka > 11 && angka <= 19) {
        tulisan(angka%10);
        cout << "Belas ";
    } else if(inRange(angka, 20, 99)) {
        tulisan(angka/10);
        cout << "Puluh ";
        tulisan(angka%10);
    } else if(inRange(angka, 100, 199)) {
        cout << "Seratus ";
        tulisan(angka%100);
    } else if(inRange(angka, 200, 999)) {
        tulisan(angka/100);
        cout << "Ratus ";
        tulisan(angka%100);
    } else if(inRange(angka, 1000, 1999)) {
        cout << "Seribu ";
        tulisan(angka%1000);
    } else if(inRange(angka, 2000, 999999)) {
        tulisan(angka/1000);
        cout << "Ribu ";
        tulisan(angka%1000);
    } else if(inRange(angka, 1000000, 999999999)) {
        tulisan(angka/1000000);
        cout << "Juta ";
        tulisan(angka%1000000);
    } else if(inRange(angka, 1000000000, 999999999999)) {
        tulisan(angka/1000000000);
        cout << "Milyar ";
        tulisan(angka%1000000000);
    } else cout << "Ukuran angka anda melebihi kapasitas";
}

int main() {
    int number;

    cout << "Masukkan angka: "; cin >> number;

    cout << "Hasil = "; tulisan(number);
}