#include <iostream>
#include <cstdlib> // Untuk menggunakan fungsi system("CLS") pada Windows
#include <conio.h>
#include <string>

using namespace std;

struct Student
{
    int id;
    char nama[50];
    float agama, pkn, b_indo, b_ing, mtk, ipa, ips;
    char grade;
};

class Admin
{
private:
    Student student[100];
    int count;

public:
    Admin()
    {
        count = 0;
    }

    void addDataStudent()
    {
        cout << "--> Menambah Data Student" << endl;
        cout << "Masukkan ID Student: ";
        cin >> student[count].id;
        cout << "Masukkan Nama Student: ";
        cin.ignore();
        cin.getline(student[count].nama, 50);
        cout << "Masukkan Nilai Agama: ";
        cin >> student[count].agama;
        cout << "Masukkan Nilai PKN: ";
        cin >> student[count].pkn;
        cout << "Masukkan Nilai Bahasa Indonesia: ";
        cin >> student[count].b_indo;
        cout << "Masukkan Nilai Bahasa Inggris: ";
        cin >> student[count].b_ing;
        cout << "Masukkan Nilai Matematika: ";
        cin >> student[count].mtk;
        cout << "Masukkan Nilai IPA: ";
        cin >> student[count].ipa;
        cout << "Masukkan Nilai IPS: ";
        cin >> student[count].ips;

        float total = student[count].agama + student[count].pkn + student[count].b_indo + student[count].b_ing + student[count].mtk + student[count].ipa + student[count].ips;
        float average = total / 7;

        if (average >= 90)
            student[count].grade = 'A';
        else if (average >= 80 && average < 90)
            student[count].grade = 'B';
        else if (average >= 70 && average < 80)
            student[count].grade = 'C';
        else if (average >= 60 && average < 70)
            student[count].grade = 'D';
        else
            student[count].grade = 'E';

        count++;

        cout << "Data Student berhasil ditambahkan." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    void displayDataStudent()
    {
        if (count == 0)
        {
            cout << "Belum ada data Student." << endl;
            return;
        }

        cout << "--> Menampilkan Data Student" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "ID Student: " << student[i].id << endl;
            cout << "Nama Student: " << student[i].nama << endl;
            cout << "Nilai Agama: " << student[i].agama << endl;
            cout << "Nilai PKN: " << student[i].pkn << endl;
            cout << "Nilai Bahasa Indonesia: " << student[i].b_indo << endl;
            cout << "Nilai Bahasa Inggris: " << student[i].b_ing << endl;
            cout << "Nilai Matematika: " << student[i].mtk << endl;
            cout << "Nilai IPA: " << student[i].ipa << endl;
            cout << "Nilai IPS: " << student[i].ips << endl;
            cout << "Grade: " << student[i].grade << endl;
            cout << "-----------------------" << endl;
        }

        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    void updateDataStudent()
    {
        if (count == 0)
        {
            cout << "Belum ada data Student." << endl;
            return;
        }

        cout << "--> Mengubah Data Student" << endl;
        int id;
        cout << "Masukkan ID Student yang ingin diubah: ";
        cin >> id;

        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (student[i].id == id)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "ID Student tidak ditemukan." << endl;
            return;
        }

        cout << "Masukkan Nama Student: ";
        cin.ignore();
        cin.getline(student[index].nama, 50);
        cout << "Masukkan Nilai Agama: ";
        cin >> student[index].agama;
        cout << "Masukkan Nilai PKN: ";
        cin >> student[index].pkn;
        cout << "Masukkan Nilai Bahasa Indonesia: ";
        cin >> student[index].b_indo;
        cout << "Masukkan Nilai Bahasa Inggris: ";
        cin >> student[index].b_ing;
        cout << "Masukkan Nilai Matematika: ";
        cin >> student[index].mtk;
        cout << "Masukkan Nilai IPA: ";
        cin >> student[index].ipa;
        cout << "Masukkan Nilai IPS: ";
        cin >> student[index].ips;

        float total = student[index].agama + student[index].pkn + student[index].b_indo + student[index].b_ing + student[index].mtk + student[index].ipa + student[index].ips;
        float average = total / 7;

        if (average >= 90)
            student[index].grade = 'A';
        else if (average >= 80 && average < 90)
            student[index].grade = 'B';
        else if (average >= 70 && average < 80)
            student[index].grade = 'C';
        else if (average >= 60 && average < 70)
            student[index].grade = 'D';
        else
            student[index].grade = 'E';

        cout << "Data Student berhasil diubah." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    void deleteDataStudent()
    {
        if (count == 0)
        {
            cout << "Belum ada data Student." << endl;
            return;
        }

        cout << "--> Menghapus Data Student" << endl;
        int id;
        cout << "Masukkan ID Student yang ingin dihapus: ";
        cin >> id;

        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (student[i].id == id)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "ID Student tidak ditemukan." << endl;
            return;
        }

        for (int i = index; i < count - 1; i++)
        {
            student[i] = student[i + 1];
        }

        count--;

        cout << "Data Student berhasil dihapus." << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    void runAdminMenu()
    {
        int choice;
        while (true)
        {
            cout << "                                          .....::::::.....                                           " << endl;
            cout << "                                   ..:^^~~~~~~!!!!!!!!~~~~~~^^:..                                    " << endl;
            cout << "                               .:^~~~!!!!~~~~~~~~~~~~~~~~~~!!!!~~~^:.                               " << endl;
            cout << "                            .^~~!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!~~^.                            " << endl;
            cout << "                         .^~~!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!~~^.                         " << endl;
            cout << "                       :^~!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!~^:                       " << endl;
            cout << "                     :~!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!!~:                     " << endl;
            cout << "                   .^!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!^.                   " << endl;
            cout << "                  ^~!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!~^                  " << endl;
            cout << "                .^!~~~~~~~~~~~~~~~~~~~~~~~~~!!!~~~~~~!!!~~~~~~~~~~~~~~~~~~~~~~~~~!^.                " << endl;
            cout << "               .~!~~~~~~~~~~~~~~~~~~~~~~~!~~^^::::::::^^~~!~~~~~~~~~~~~~~~~~~~~~~~!~.               " << endl;
            cout << "              .~!~~~~~~~~~~~~~~~~~~~~~~!~^:..............:^~!~~~~~~~~~~~~~~~~~~~~~~!~.              " << endl;
            cout << "              ~!~~~~~~~~~~~~~~~~~~~~~!~:....................:~!~~~~~~~~~~~~~~~~~~~~~!~              " << endl;
            cout << "             ^!~~~~~~~~~~~~~~~~~~~~~!^........................^!~~~~~~~~~~~~~~~~~~~~~!^             " << endl;
            cout << "            .~~~~~~~~~~~~~~~~~~~~~~~^..........................^~~~~~~~~~~~~~~~~~~~~~~~.            " << endl;
            cout << "            :!~~~~~~~~~~~~~~~~~~~~~~............................~~~~~~~~~~~~~~~~~~~~~~!:            " << endl;
            cout << "            ~!~~~~~~~~~~~~~~~~~~~~~~............................~~~~~~~~~~~~~~~~~~~~~~!~            " << endl;
            cout << "            ~~~~~~~~~~~~~~~~~~~~~~~~............................~~~~~~~~~~~~~~~~~~~~~~~~            " << endl;
            cout << "           .~~~~~~~~~~~~~~~~~~~~~~~~:..........................:~~~~~~~~~~~~~~~~~~~~~~~~.           " << endl;
            cout << "            ~~~~~~~~~~~~~~~~~~~~~~~~~..........................~~~~~~~~~~~~~~~~~~~~~~~~~            " << endl;
            cout << "            ~!~~~~~~~~~~~~~~~~~~~~~~!~:......................:~!~~~~~~~~~~~~~~~~~~~~~~!~            " << endl;
            cout << "            :!~~~~~~~~~~~~~~~~~~~~~~~~~^:..................:^~~~~~~~~~~~~~~~~~~~~~~~~~!:            " << endl;
            cout << "            .~~~~~~~~~~~~~~~~~~~~~~~~~~!~~^:............:^~~!~~~~~~~~~~~~~~~~~~~~~~~~~~.            " << endl;
            cout << "             ^!~~~~~~~~~~~~~~~~~~~~~~~!!!~!!~~^^^^^^^^~~!!!!!!~~~~~~~~~~~~~~~~~~~~~~~!^             " << endl;
            cout << "              ~!~~~~~~~~~~~~~~~~~~~!~~^^:.:^^~~~~~~~~~~^^:.:^^~~!~~~~~~~~~~~~~~~~~~~!~              " << endl;
            cout << "              .~!~~~~~~~~~~~~~~~!~~^:..........................:^~~!~~~~~~~~~~~~~~~!~.              " << endl;
            cout << "               .~!~~~~~~~~~~~~!~^..................................^~!~~~~~~~~~~~~!~.               " << endl;
            cout << "                .^!~~~~~~~~~!~:......................................:~!~~~~~~~~~!^.                " << endl;
            cout << "                  ^~!~~~~~!~^..........................................^~!~~~~~!~^                  " << endl;
            cout << "                   .^!~~~!~..............................................~!~~~!^.                   " << endl;
            cout << "                     :~!!^................................................^!!~:                     " << endl;
            cout << "                       :^..................................................^:                       " << endl;
            cout << "                           ..............................................                           " << endl;
            cout << "                              ........................................                              " << endl;
            cout << "                                  ................................                                  " << endl;
            cout << "                                        ....................                                        " << endl;

            system("CLS");
            cout << "Menu Utama" << endl;
            cout << "=======================================" << endl;
            cout << "1. Menambah Data Student" << endl;
            cout << "2. Menampilkan Data Student" << endl;
            cout << "3. Mengubah Data Student" << endl;
            cout << "4. Menghapus Data Student" << endl;
            cout << "5. Kembali ke Menu Awal" << endl;
            cout << "--> Pilih menu (1-5): ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addDataStudent();
                break;
            case 2:
                displayDataStudent();
                break;
            case 3:
                updateDataStudent();
                break;
            case 4:
                deleteDataStudent();
                break;
            case 5:
                resetDataStudent();
                cout << "Kembali ke Menu Awal..." << endl;
                cout << "Tekan enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                continue;

            default:
                cout << "Pilihan tidak valid. Silakan pilih menu (1-5)." << endl;
                cout << "Tekan enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
                break;
            }
            cout << "Tekan Tombol apapun untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        }
    }

    void resetDataStudent()
    {
        count = 0;
    }
};

int main()
{
    int choice;
    Admin admin;

    system("CLS");
    cout << "Selamat Datang di Aplikasi Rapot Online" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Login sebagai : " << endl;
    cout << "1. Admin" << endl;
    cout << "2. Teacher" << endl;
    cout << "3. Student" << endl;
    cout << endl;
    cout << "--> Pilih menu (1-3): ";
    cin >> choice;

    if (choice == 1)
    {
        string username;
        string password;

        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        if (username == "admin" && password == "admin123")
        {
            admin.runAdminMenu();
        }
        else
        {
            cout << "Username atau password yang Anda masukkan salah." << endl;
            cout << "Tekan enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
            system("CLS");
            main();
        }
    }
    else if (choice == 2)
    {
        // Logika untuk login sebagai Teacher
        cout << "Anda login sebagai Teacher." << endl;
        // ...
    }
    else if (choice == 3)
    {
        // Logika untuk login sebagai Student
        cout << "Anda login sebagai Student." << endl;
        // ...
    }
    else
    {
        cout << "Pilihan tidak valid. Silakan pilih menu (1-3)." << endl;
    }

    return 0;
}
