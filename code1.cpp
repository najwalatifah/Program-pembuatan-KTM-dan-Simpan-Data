#include <iostream>
using namespace std;

struct Nilai {
    int Absen;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
    char NilaiHuruf;
};

struct Mahasiswa {
    string Nama;
    string NPM;
    string Angkatan;
    Nilai nilai;
    Mahasiswa* next; // Pointer ke node selanjutnya dalam linked list
};

Mahasiswa* head = NULL; // Pointer ke node pertama dalam linked list

// Fungsi untuk memeriksa apakah seorang mahasiswa sudah memiliki kartu mahasiswa
bool CekKartuMahasiswa(string NPM) {
    Mahasiswa* current = head;
    while (current != NULL) {
        if (current->NPM == NPM) {
            return true; // NPM sudah ada dalam linked list
        }
        current = current->next;
    }
    return false; // NPM belum ada dalam linked list
}

// Fungsi untuk membuat kartu tanda mahasiswa
void BuatKartuTandaMahasiswa() {
    string npm;
    char Tambahdata = 'y';
    while (Tambahdata == 'y' || Tambahdata == 'Y') { 
        Mahasiswa* baru = new Mahasiswa();
        cout << "Masukan Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, baru->Nama);
        inpt_npm:
        cout << "Masukan NPM Mahasiswa: ";
        cin >> npm;
        if(CekKartuMahasiswa(npm)){
            cout << "NPM sudah ada, masukan NPM Baru\n";
            goto inpt_npm;
        }
        baru->NPM = npm;
        cout << "Masukkan Angkatan Mahasiswa: ";
        cin >> baru->Angkatan;
        baru->next = head;
        head = baru;
        cout << "Data Mahasiswa Berhasil Ditambahkan" << endl;
        cout << "Tambahkan Data Mahasiswa lagi ? (Y/N) : ";
        cin >> Tambahdata;
    }
}

// Funsi untuk menampilkan Kartu tanda mahasiswa yang sudah dibuat
void TampilKartuTandaMahasiswa() {
    Mahasiswa* current = head;
    if (current == NULL) {
        cout << "Buat Kartu Tanda Mahasiswa" << endl;
        return;
    }
    cout << "============================================================" << endl;
    cout << "                   Kartu Tanda Mahasiswa" << endl;
    cout << "============================================================" << endl;
    while (current != NULL) {
        cout << "NPM Mahasiswa  : " << current->NPM << "\t\t" << endl;
        cout << "Nama Mahasiswa : " <<current->Nama << "\t\t" << endl;
        cout << "Angkatan       : " << current->Angkatan << endl << endl;
        current = current->next;
    }
    cout << "============================================================" << endl;
}

// Fungsi untuk mencari data mahasiswa berdasarkan NPM
Mahasiswa* CariDataMahasiswa(string NPM) {
    Mahasiswa* current = head;
    while (current != NULL) {
        if (current->NPM == NPM) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Fungsi untuk menghitung nilai dan nilai huruf
void HitungNilai(Nilai& n) {
    n.NilaiAkhir = 0.1 * n.Absen + 0.2 * n.NilaiTugas + 0.3 * n.NilaiUTS + 0.4 * n.NilaiUAS;
    if (n.NilaiAkhir > 80)
        n.NilaiHuruf = 'A';
    else if (n.NilaiAkhir > 70)
        n.NilaiHuruf = 'B';
    else if (n.NilaiAkhir > 60)
        n.NilaiHuruf = 'C';
    else
        n.NilaiHuruf = 'D';
}

// Fungsi untuk menambah data mahasiswa ke linked list jika memiliki kartu mahasiswa
void TambahDataMahasiswa() {
    string NPM;
    char Tambahdata;
    cout << "Masukkan NPM Anda: ";
    cin >> NPM;
    if (CekKartuMahasiswa(NPM)) {
        Mahasiswa *baru = CariDataMahasiswa(NPM);
            cout << "Masukan Nilai Absen Mahasiswa: ";
            cin >> baru->nilai.Absen;
            cout << "Masukan Nilai Tugas Mahasiswa: ";
            cin >> baru->nilai.NilaiTugas;
            cout << "Masukan Nilai UTS Mahasiswa : ";
            cin >> baru->nilai.NilaiUTS;
            cout << "Masukan Nilai UAS Mahasiswa : ";
            cin >> baru->nilai.NilaiUAS;
            HitungNilai(baru->nilai);
            cout << "Data Mahasiswa Berhasil Ditambahkan" << endl;
            cout << "Tambahkan Data Mahasiswa lagi ? (Y/N) : ";
            cin >> Tambahdata;
            if(Tambahdata == 'y' || Tambahdata == 'Y'){
                TambahDataMahasiswa();
            }
    } else {
        cout << "Maaf, Anda belum memiliki kartu mahasiswa" << endl;
    }
}

// Fungsi untuk menampilkan data mahasiswa dari linked list
void TampilDataMahasiswa() {
    Mahasiswa* current = head;
    if (current == NULL) {
        cout << "Belum ada data mahasiswa" << endl;
        return;
    }

    cout << "Daftar Mahasiswa Universitas Singaperbangsa Karawang : " << endl;
    cout << "====================================================================================================================================" << endl;
    cout << "NPM                 \tNAMA            \tNILAI ABSEN \tNILAI TUGAS \tUTS   \tUAS   \tNILAI AKHIR \tNILAI HURUF" << endl;
    cout << "====================================================================================================================================" << endl;
    while (current != NULL) {
        cout << current->NPM << "\t\t"
            << current->Nama << "\t\t"
            << current->nilai.Absen << "\t\t"
            << current->nilai.NilaiTugas << "\t\t"
            << current->nilai.NilaiUTS << "\t"
            << current->nilai.NilaiUAS << "\t"
            << current->nilai.NilaiAkhir << "\t\t"
            << current->nilai.NilaiHuruf << endl;
        current = current->next;
    }
    cout << "====================================================================================================================================" << endl;
}

// Fungsi untuk mengubah data mahasiswa
void EditDataMahasiswa() {
    string NPM;
    cout << "Masukan NPM Mahasiswa Yang Ingin Diubah Datanya : ";
    cin >> NPM;

    Mahasiswa* mahasiswa = CariDataMahasiswa(NPM);
    if (mahasiswa != NULL) {
        cout << "Data Mahasiswa Ditemukan" << endl;
        cout << "Silahkan Masukan Data Baru : " << endl;
        cout << "Masukan Nama Mahasiswa: ";
        cin.ignore();
        getline(cin, mahasiswa->Nama);
        inpt_npm:
        cout << "Masukan NPM Mahasiswa : ";
        cin >> NPM;
        mahasiswa->NPM = NPM;
        cout << "Masukan Nilai Absen Mahasiswa : ";
        cin >> mahasiswa->nilai.Absen;
        cout << "Masukan Nilai Tugas Mahasiswa : ";
        cin >> mahasiswa->nilai.NilaiTugas;
        cout << "Masukan Nilai UTS Mahasiswa: ";
        cin >> mahasiswa->nilai.NilaiUTS;
        cout << "Masukan Nilai UAS Mahasiswa: ";
        cin >> mahasiswa->nilai.NilaiUAS;
        HitungNilai(mahasiswa->nilai);
        cout << "Data berhasil diubah" << endl;
    }
    else {
        cout << "Data mahasiswa tidak ditemukan" << endl;
    }
}

// Fungsi untuk menghapus data mahasiswa dari linked list
void HapusDataMahasiswa() {
    string NPM;
    cout << "Masukan NPM Mahasiswa Yang Ingin Dihapus : ";
    cin >> NPM;

    Mahasiswa* current = head;
    Mahasiswa* prev = NULL;
    while (current != NULL) {
        if (current->NPM == NPM) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "Data mahasiswa berhasil dihapus" << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Data mahasiswa dengan NPM tersebut tidak ditemukan" << endl;
}

int main() {
    char pilihan;
    do {
        cout << "\nMenu Program:\n";
        cout << "a. Buat Kartu Tanda Mahasiswa\n";
        cout << "b. Tampil Kartu Tanda Mahasiswa\n";
        cout << "c. Input Data Mahasiswa\n";
        cout << "d. Tampil Data Mahasiswa\n";
        cout << "e. Edit Data Mahasiswa\n";
        cout << "f. Hapus Data Mahasiswa\n";
        cout << "g. Keluar\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 'a':
            BuatKartuTandaMahasiswa();
            break;
        case 'b':
            TampilKartuTandaMahasiswa();
            break;
        case 'c':
            TambahDataMahasiswa();
            break;
        case 'd':
            TampilDataMahasiswa();
            break;
        case 'e':
            EditDataMahasiswa();
            break;
        case 'f':
            HapusDataMahasiswa();
            break;
        case 'g':
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Menu tidak valid"   << endl;
            cout << "Silakan coba lagi" << endl;
        }
    } while (pilihan != 'g');

    // Hapus semua node linked list sebelum keluar dari program
    Mahasiswa* current = head;
    Mahasiswa* next = NULL;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    head = NULL;

    return 0;
}