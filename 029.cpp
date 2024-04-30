#include <iostream>
#include <string>
using namespace std;

string cekKartu(long nomorKartu) {
    long kartuDiproses = nomorKartu;
    int jumlah = 0;
    int jumlahDigit = 0;
    long pembagi = 10;
    string hasil;

    while (kartuDiproses > 0) {
        int digitTerakhir = kartuDiproses % 10;
        jumlah = jumlah + digitTerakhir;
        kartuDiproses = kartuDiproses / 100;
    }

    kartuDiproses = nomorKartu / 10;
    while (kartuDiproses > 0) {
        int digitTerakhir = kartuDiproses % 10;
        int kaliDua = digitTerakhir * 2;
        jumlah = jumlah + (kaliDua % 10) + (kaliDua / 10);
        kartuDiproses = kartuDiproses / 100;
    }

    long temp = nomorKartu;
    while (temp != 0) {
        temp = temp / 10;
        jumlahDigit++;
    }

    for (int i = 0; i < jumlahDigit - 2; i++) {
        pembagi = pembagi * 10;
    }

    int digit1 = nomorKartu / pembagi;
    int digit2 = nomorKartu / (pembagi / 10);

    if (jumlah % 10 == 0) {
        if (digit1 == 4 && (jumlahDigit == 13 || jumlahDigit == 16)) {
            hasil = "VISA";
        } else if ((digit2 >= 51 && digit2 <= 55) && jumlahDigit == 16) {
            hasil = "MASTERCARD";
        } else {
            hasil = "INVALID";
        }
    } else {
        hasil = "INVALID";
    }

    return hasil;
}

int main() {
    long nomorKartu;
    cout << "Masukkan nomor kartu: ";
    cin >> nomorKartu;

    string hasil = cekKartu(nomorKartu);
    cout << "Hasil: " << hasil << endl;

    return 0;
}