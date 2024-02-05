#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <istream>
#include <string>

using namespace std;

struct datapasien {
    string  nama, penyakit;
    int umur;

    datapasien* next;
};

datapasien* head, * tail, * cur, * newNode, * before, * indeks, * del;

bool found{ true };
int Antrian1 = 0, antrianRiwayat = 0;

int queueKosong() {
    if (head == NULL) {
        return(true);
    }
    else
        return(false);
}

int countSingleLinkedList() {
    cur = head;
    int jumlah = 0;
    while (cur != NULL) {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void createlinkedlist(string nama, string penyakit, int umur) {
    if (umur > 60) {
        //tambah diawal
        if (queueKosong()) {
            head = new datapasien();
            head->nama = nama;
            head->penyakit = penyakit;
            head->next = NULL;
            tail = head;
        }
        else {
            newNode = new datapasien();
            newNode->nama = nama;
            newNode->penyakit = penyakit;
            newNode->umur = umur;
            newNode->next = head;
            head = newNode;
        }
    }
    else {
        //tambah diakhir
        if (queueKosong()) {
            head = new datapasien();
            head->nama = nama;
            head->penyakit = penyakit;
            head->umur = umur;
            head->next = NULL;
            tail = head;
        }
        else {
            newNode = new datapasien();
            newNode->nama = nama;
            newNode->penyakit = penyakit;
            newNode->umur = umur;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void deletelinkedlist() {
    if (queueKosong()) {
        cout << " Queue masih kosong !!";
    }
    else {
        del = head;
        head = del->next;
        {
            newNode = new datapasien();
            newNode->nama = del->nama;
            newNode->penyakit = del->penyakit;
            newNode->umur = del->umur;
            if (head == NULL)
                head = newNode;
            else
                tail->next = newNode;

            tail = newNode;
            tail->next = NULL;
            antrianRiwayat++;
        }
        free(del);
        Antrian1--;
        cout << "== Pelayanan " << tail->nama << " Selesai" << endl;
    }
}

void search() {
    string cari;
    cur = head;
    cout << "Masukkan nama yang dicari : "; cin.ignore(); getline(cin, cari);
    while (cur != tail)
    {
        if (cur->nama == cari) {
            found = true;
            cout << "Nama     : " << cur->nama << endl;
            cout << "Penyakit : " << cur->penyakit << endl;
            cout << "Umur     : " << cur->umur << endl;
        }
        cur = cur->next;
        before = cur;
    }
    if (found == false) {
        cout << "Nama Tidak Ada Dalam Data!" << endl;
    }
    found = false;
}
void BubbledSort_Descending()
{
    int swapp = 0;

    do {
        cur = head, indeks = NULL;
        while (cur != NULL) {
            indeks = cur->next;
            while (indeks != NULL) {
                if (cur->umur < indeks->umur) {
                    swap(cur->nama, indeks->nama);
                    swap(cur->penyakit, indeks->penyakit);
                    swap(cur->umur, indeks->umur);
                }
                indeks = indeks->next;
            }
            cur = cur->next;
        }
        swapp = 1;
    } while (swapp != 1);
    cout << "Data Berhasil Diurutkan";
}

void BubbledSort_Ascending() {
    int swapp = 0;

    do {
        cur = head, indeks = NULL;
        while (cur != NULL) {
            indeks = cur->next;
            while (indeks != NULL) {
                if (cur->umur > indeks->umur) {
                    swap(cur->nama, indeks->nama);
                    swap(cur->penyakit, indeks->penyakit);
                    swap(cur->umur, indeks->umur);
                }
                indeks = indeks->next;
            }
            cur = cur->next;
        }
        swapp = 1;
    } while (swapp != 1);
    cout << "Data Berhasil Diurutkan";
}

void print() {
    int i = 0;
    cur = head;
    cout << endl << "===============================================" << endl;
    cout << "|=============== DAFTAR PASIEN ================|";
    cout << endl << "===============================================" << endl;
    cout << setw(3) << "|No" << setw(10) << "|   Nama   |" << setw(15) << "    Penyakit   " << setw(17) << "|     Umur     |" << endl;
    do {
        i++;
        cout << setw(3) << i << setw(10) << cur->nama << setw(15) << cur->penyakit << setw(17) << cur->umur << endl;
        cur = cur->next;
        cout << "===============================================" << endl;
    } while (cur != NULL && i != Antrian1);
    cout << endl << "Jumlah Antrian : " << Antrian1;
    cout << endl << endl;
}

int main() {

    system("color 0a");
    cout << "\n\t Sedang Memuat\n";
    char a = 177, b = 219;
    cout << "\t";
    for (int i = 0; i <= 15; i++)
        cout << a;
    cout << "\r";
    cout << "\t";
    for (int i = 0; i <= 15; i++)
    {
        cout << b;
        for (int j = 0; j <= 1e8; j++);
    }

    int pilih;
    int antrian, umur2;
    string kembali, nama2, penyakit2;

    do {
        antrian = 1;
        system("cls");
        if (!queueKosong()) {
            print();
        }

        system("color A");

        cout << "===============================================" << endl;
        cout << "======== PROGRAM RUMAH SAKIT WIROSABAN ========" << endl;
        cout << "===============================================" << endl;
        cout << " MENU : " << endl;
        cout << " 1. Tambah Pasien" << endl;
        cout << " 2. Lihat Daftar Antrian Pasien" << endl;
        cout << " 3. Layani Pasien" << endl;
        cout << " 4. Cari Data Pasien" << endl;
        cout << " 5. Urutkan Data Menurun" << endl;
        cout << " 6. Urutkan Data Menaik" << endl;
        cout << " 7. Exit" << endl;
        cout << " Pilih menu : "; cin >> pilih;
        switch (pilih) {
        case 1:
        {
            cout << endl << "=== Menu Input Pasien ===";
            while (antrian == 1) {
                if (!queueKosong()) {
                    print();
                }
                Antrian1++;
                cout << endl << "==> Input Pasien" << endl;
                cout << " Masukkan Nama : "; cin.ignore(); getline(cin, nama2);
                cout << " Masukkan Penyakit : "; getline(cin, penyakit2);
                cout << " Masukkan Umur Pasien : "; cin >> umur2;
                createlinkedlist(nama2, penyakit2, umur2);
                cout << endl << " Tekan 1 Untuk Menambah Pasien || Tekan 0 untuk Kembali ke Menu ";
                cin >> antrian;
                system("cls");
            }
        }
        break;
        case 2:
        {
            cout << endl << "== Menu Daftar Pasien ==" << endl;
            if (!queueKosong()) {
                print();
            }
            else
                cout << "== Tidak Ada Pasien !! ==" << endl;
            cout << endl << "Tekan 0 untuk Kembali ke Menu ";
            cin >> antrian;
            system("cls");
        }
        break;
        case 3:
        {
            cout << endl << "== Menu Layani Pasien";
            if (!queueKosong()) {
                deletelinkedlist();
            }
            else
                cout << "== Tidak Ada Pasien !!" << endl;
            cout << endl << " Tekan 1 Untuk Menambah Pasien || Tekan 0 untuk Kembali ke Menu ";
            cin >> antrian;
            system("cls");
        }
        break;
        case 4:
            search();
            break;
        case 5:
            BubbledSort_Descending();
            break;
        case 6:
            BubbledSort_Ascending();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << endl << "Input Yang Anda Masukkan SALAH ! " << endl;
            break;
        }
        cout << "Kembali ke menu ?[ y/n ] : "; cin >> kembali;
    } while (kembali == "y" || kembali == "Y");
    system("pause");
}
