#ifndef TERDAKWA_H_INCLUDED        //Di kerjakan oleh Agung Kaleb Sasau_103012500211
#define TERDAKWA_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

struct Terdakwa {
    string id_terdakwa;
    string nama;
    string alamat;
};

typedef Terdakwa infotypeTerdakwa;          // variabel alias untuk info
typedef struct elmTerdakwa *adrTerdakwa;    // variabel alias untuk pointer

// kerangka dari elemen list (SLL)
struct elmTerdakwa {
    infotypeTerdakwa info;
    adrTerdakwa next;
};

// kerangka dari list (SLL)
struct ListTerdakwa {
    adrTerdakwa first;
    adrTerdakwa last;
};

// pengecekan apakah list kosong
bool isEmptyTerdakwa(ListTerdakwa LT);
/* I.S. list LT terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void createListTerdakwa(ListTerdakwa &LT);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrTerdakwa alokasiTerdakwa(infotypeTerdakwa x);
/* I.S. info terdakwa x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL */

void dealokasiTerdakwa(adrTerdakwa &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen list
adrTerdakwa findTerdakwa(ListTerdakwa LT, string id_terdakwa);
/* I.S. list LT dan id_terdakwa terdefinisi
   F.S. mengembalikan alamat elemen terdakwa yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirstTerdakwa(ListTerdakwa &LT, adrTerdakwa P);
/* I.S. terdefinisi list LT yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfterTerdakwa(ListTerdakwa &LT, adrTerdakwa Prec, adrTerdakwa P);
/* I.S. terdefinisi list LT yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLastTerdakwa(ListTerdakwa &LT, adrTerdakwa P);
/* I.S. terdefinisi list LT yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirstTerdakwa(ListTerdakwa &LT, adrTerdakwa &P);
/* I.S. terdefinisi list LT yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari elemen pertama list yang akan dihapus */

void deleteLastTerdakwa(ListTerdakwa &LT, adrTerdakwa &P);
/* I.S. terdefinisi list LT yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari elemen terakhir list yang akan dihapus */

void deleteAfterTerdakwa(ListTerdakwa &LT, adrTerdakwa Prec, adrTerdakwa &P);
/* I.S. terdefinisi list LT yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. P adalah alamat dari elemen list setelah Prec yang akan dihapus */

// menampilkan isi list
void printInfoTerdakwa(ListTerdakwa LT);
/* I.S. terdefinisi list LT yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

// input data terdakwa dari user
infotypeTerdakwa inputDataTerdakwa();
/* I.S. ~
   F.S. meminta data terdakwa dari user */

#endif // TERDAKWA_H_INCLUDED
