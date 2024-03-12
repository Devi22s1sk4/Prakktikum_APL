#include <iostream>
#include <string>

using namespace std;

struct Hadiah {
    string nama;
    int jumlah;
};

void tampilkanData(Hadiah hadiah[], int jumlahHadiah) {
    cout << "Data Hadiah Natal:\n";
    for (int i = 0; i < jumlahHadiah; i++) {
        cout << i + 1 << ". " << hadiah[i].nama << " - " << hadiah[i].jumlah << " buah\n";
    }
}

int main() {
    string namaUser;
    int nimUser;
    int attempt = 0;
    bool loggedIn = false;

    while (attempt < 3 && !loggedIn) {
        cout << "Masukkan Nama: ";
        cin >> namaUser;
        cout << "Masukkan NIM: ";
        cin >> nimUser;

        if (namaUser == "Devi" && nimUser == 122) {
            cout << "Login berhasil!\n";
            loggedIn = true;
        }
        else {
            cout << "Login gagal. Silakan coba lagi.\n";
            attempt++;
        }
    }

    if (!loggedIn) {
        cout << "Gagal login sebanyak 3 kali. Program berhenti." << endl;
        return 0;
    }

    Hadiah daftarHadiah[] = {
        {"Buku", 5},
        {"Boneka", 10},
        {"Gaun Pesta", 3},
        {"Lego", 7},
        {"Sepatu heels", 4},
        {"Perhiasan", 6},
        {"Tas", 8},
        {"Gitar", 2}
    };
    int jumlahHadiah = 8;

    int pilihan;
    do {
        cout << "\nSILAHKAN PILIH MENU\n";
        cout << "1. Tampilkan Hadiah Natal\n";
        cout << "2. Tambahkan Hadiah Natal\n";
        cout << "3. Ubah Hadiah Natal\n";
        cout << "4. Hapus Hadiah Natal\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarHadiah, jumlahHadiah);
                break;
            case 2:
                if (jumlahHadiah < 100) {
                    cout << "Masukkan Nama Hadiah: ";
                    cin >> daftarHadiah[jumlahHadiah].nama;
                    cout << "Masukkan Jumlah Hadiah: ";
                    cin >> daftarHadiah[jumlahHadiah].jumlah;
                    jumlahHadiah++;
                    cout << "Data berhasil ditambahkan.\n";
                } else {
                    cout << "Maaf, jumlah hadiah sudah mencapai batas maksimum.\n";
                }
                break;
            case 3:
                int indeksEdit;
                tampilkanData(daftarHadiah, jumlahHadiah);
                cout << "Masukkan nomor hadiah yang ingin diubah: ";
                cin >> indeksEdit;
                if (indeksEdit >= 1 && indeksEdit <= jumlahHadiah) {
                    cout << "Masukkan Nama Hadiah baru: ";
                    cin >> daftarHadiah[indeksEdit - 1].nama;
                    cout << "Masukkan Jumlah Hadiah baru: ";
                    cin >> daftarHadiah[indeksEdit - 1].jumlah;
                    cout << "Data berhasil diubah.\n";
                } else {
                    cout << "Nomor hadiah tidak valid.\n";
                }
                break;
            case 4:
                int indeksHapus;
                tampilkanData(daftarHadiah, jumlahHadiah);
                cout << "Masukkan nomor hadiah yang ingin dihapus: ";
                cin >> indeksHapus;
                if (indeksHapus >= 1 && indeksHapus <= jumlahHadiah) {
                    for (int i = indeksHapus - 1; i < jumlahHadiah - 1; i++) {
                        daftarHadiah[i] = daftarHadiah[i + 1];
                    }
                    jumlahHadiah--;
                    cout << "Data berhasil dihapus.\n";
                } else {
                    cout << "Nomor hadiah tidak valid.\n";
                }
                break;
            case 5:
                cout << "Program berhenti, Terima kasih telah menggunakan program Hadiah Natal!";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}

