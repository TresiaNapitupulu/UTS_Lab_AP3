#include <iostream>                                         // header file & library untuk i/0
using namespace std;                                        // biar ga perlu nulis ::std

  string jenis_kartu (string nomor_kartu) {                 //untuk menentukan jenis kartu berdasarkan no.kartunya
    string tipe_kartu = "tidak tahu ";                   
    int digit1 = nomor_kartu[0] - '0';                     // mengambil digit1 dari kartu & diubah ke integer

    // kondisi untuk menentukan jenis kartu berdasarkan digit1 dan panjang no. kartu
    if ((digit1 == 5) && (nomor_kartu.length() == 16) && (nomor_kartu[1] >= '1' && nomor_kartu[1] <= '5')) {
        return "mastercard"; }
    else if (digit1 == 4 && (nomor_kartu.length() == 13 || nomor_kartu.length() == 16)) {
        return "visa"; }
    return tipe_kartu;                                      
  }

  int hitung_checksum(string nomor_kartu) {                 // mengambil no.kartu lalu dihitung jumlah checksumnya menggunakkan algoritma luhn
    int jumlah = 0;                                         // menyimpan total jumlah digit
    bool ubah_angka = false;                                // untuk menentukan digitnya harus diubah/tidak

    for (int i = nomor_kartu.length() - 1; i >= 0; i--){    // loop checksum, dimulai dari paling kanan no kartu
        int digit = nomor_kartu[i] - '0';
        if(ubah_angka) digit *= 2;                          // digit dikali 2
        jumlah += digit / 10 + digit % 10;                  // total digit ditambahkan ke jumlah
        ubah_angka = !ubah_angka; }                         //ubah jadi nilai kebalikan untuk mengubah nilai berikutnya

    return jumlah;
  }
  //mengambil no kartu sebagai masukkan jika "true" maka no kartu memenuhi algoritma luhn, jika "false" maka tidak
  bool algoritmaluhn(string nomor_kartu) {                           
    int checksum = hitung_checksum(nomor_kartu);
    return (checksum % 10 == 0); }
  
  int main() {                                              //eksekusi program dimulai
    string nomor_kartu;                                     // mendeklarasikan tipe data, 'nomor_kartu' sebagai string
    char pilih;                                             //mendeklarasikan tipe data, 'pilih' sebagai char
  do {
    system("cls");                                          // untuk membersihkan layar
        cout << "masukkan no.Kartu : ";                     
        cin >> nomor_kartu;                                 

  string tipe_kartu = jenis_kartu (nomor_kartu);            // memanggil fungsi 'jenis_kartu' lalu disimpan ke 'tipe_kart' 
    if (tipe_kartu != "tidak tahu ") {                     // jika jenis kartu ditemukan, kode akan dieksekusi
        int checksum = hitung_checksum(nomor_kartu);        // jika berhasil ditemukan program akan menghitung checksum no kartu dengan fungsi 'hitung_checksum'
        cout << "tipe kartu : " << tipe_kartu << endl;      // mencetak jenis kartu
        cout << "no.Checksum : " << checksum << endl; }     // mencetak checksumnya
    else {
        cout << "no.Kartu invalid (coba lagi)" << endl; }   //jikalau jenis kartu tidak diketahui program akan mencetakk pesan ini
    cout << "ingin memasukkan no.Kartu lagi? (y/n) ";       //pertanyaan untuk user, ketik (y/n)
    cin >> pilih;
    } while (pilih == 'y' || pilih == 'Y');                 //jika user mengetik 'y' || 'Y' program akan kembali ke baris pertama loop

  return 0;                                                 //eksekusi program telah selesai dan keluar dari fungsi utama
  }