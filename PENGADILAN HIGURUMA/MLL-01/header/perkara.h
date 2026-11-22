#ifndef PERKARA_H_INCLUDED        //Di kerjakan oleh Agung Kaleb Sasau_103012500211
#define PERKARA_H_INCLUDED

#include "terdakwa.h"
#include <string>
#include <iostream>

using namespace std;

struct Perkara {
    string nomor_perkara;
    string tanggal_sidang;
    string peran_hakim;
    string status_perkara;
    long long biaya_perkara;
};

typedef Perkara infotypePerkara;          // variabel alias untuk info
typedef struct elmPerkara *adrPerkara;    // variabel alias untuk pointer

// kerangka dari elemen relasi (DLL)
struct elmPerkara {
    infotypePerkara info;
    adrTerdakwa terdakwa; // Pointer menunjuk ke Child (Terdakwa)
    adrPerkara next;
    adrPerkara prev;      // Pointer mundur karena relasi menggunakan DLL
};

// kerangka dari list relasi (DLL)
struct ListPerkara {
    adrPerkara first;
    adrPerkara last;
};

// pengecekan apakah list relasi kosong
bool isEmptyPerkara(ListPerkara LP);
/* I.S. list LP terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list relasi kosong
void createListPerkara(ListPerkara &LP);
/* I.S. ~
   F.S. terbentuk list relasi kosong (first dan last NULL) */

// manajemen memori
adrPerkara alokasiPerkara(infotypePerkara x, adrTerdakwa T);
/* I.S. info perkara x dan alamat terdakwa T terdefinisi
   F.S. mengembalikan alamat elemen perkara berisi x yang menunjuk ke T
        dengan next dan prev NULL */

void dealokasiPerkara(adrPerkara &P);
/* I.S. pointer P terdefinisi
   F.S. memori elemen perkara P dikembalikan ke sistem;
        elemen terdakwa yang dirujuk tidak ikut dihapus */

// pencarian sebuah elemen relasi
adrPerkara findPerkara(ListPerkara LP, string nomor_perkara);
/* I.S. list LP dan nomor_perkara terdefinisi
   F.S. mengembalikan alamat elemen perkara yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen (DLL)
void insertFirstPerkara(ListPerkara &LP, adrPerkara P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen perkara P
   F.S. menempatkan elemen beralamat P pada awal list LP */

void insertAfterPerkara(ListPerkara &LP, adrPerkara Prec, adrPerkara P);
/* I.S. terdefinisi list LP yang mungkin kosong, elemen Prec, dan elemen P
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLastPerkara(ListPerkara &LP, adrPerkara P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen perkara P
   F.S. menempatkan elemen beralamat P pada akhir list LP */

// penghapusan sebuah elemen (DLL)
void deleteFirstPerkara(ListPerkara &LP, adrPerkara &P);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. P adalah alamat dari elemen pertama list yang dihapus dari LP */

void deleteLastPerkara(ListPerkara &LP, adrPerkara &P);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. P adalah alamat dari elemen terakhir list yang dihapus dari LP */

void deleteAfterPerkara(ListPerkara &LP, adrPerkara Prec, adrPerkara &P);
/* I.S. terdefinisi list LP yang mungkin kosong dan elemen Prec
   F.S. P adalah alamat dari elemen setelah Prec yang dihapus dari LP */

// menampilkan seluruh elemen relasi pada satu hakim
void printInfoPerkara(ListPerkara LP);
/* I.S. terdefinisi list LP yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info perkara beserta info terdakwanya */

// input data perkara dari user
infotypePerkara inputDataPerkara();
/* I.S. ~
   F.S. meminta data perkara dari user dan mengembalikannya sebagai infotypePerkara */

#endif // PERKARA_H_INCLUDED
