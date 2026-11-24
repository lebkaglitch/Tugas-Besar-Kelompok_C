#ifndef HAKIM_H_INCLUDED        //Di kerjakan oleh Muhammad Panji Adirangga_103012500229
#define HAKIM_H_INCLUDED

#include "perkara.h"
#include <string>
#include <iostream>

using namespace std;

struct Hakim {
    string id_hakim;
    string nama;
    string jabatan;
    string pengadilan;
};

typedef Hakim infotypeHakim;            // variabel alias untuk info
typedef struct elmHakim *adrHakim;      // variabel alias untuk pointer

// kerangka dari elemen list (SLL)
struct elmHakim {
    infotypeHakim info;
    adrHakim next;           // Hanya next (SLL)
    ListPerkara listPerkara; // Sub-list relasi perkara (DLL: memiliki first & last)
};

// kerangka dari list (SLL)
struct ListHakim {
    adrHakim first;
    adrHakim last;
};

// pengecekan apakah list kosong
bool isEmptyHakim(ListHakim LH);
/* I.S. list LH terdefinisi
   F.S. true jika list kosong dan false jika tidak kosong */

// pembuatan list kosong
void createListHakim(ListHakim &LH);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrHakim alokasiHakim(infotypeHakim x);
/* I.S. info hakim x terdefinisi
   F.S. mengembalikan alamat elemen berisi x dengan next NULL
        dan listPerkara kosong (first dan last NULL) */

void dealokasiHakim(adrHakim &P);
/* I.S. pointer P terdefinisi
   F.S. elemen hakim dan seluruh elemen perkara relasinya di-dealokasi;
        elemen terdakwa yang dirujuk tidak ikut dihapus */

// pencarian sebuah elemen list
adrHakim findHakim(ListHakim LH, string id_hakim);
/* I.S. list LH dan id_hakim terdefinisi
   F.S. mengembalikan alamat elemen hakim yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertFirstHakim(ListHakim &LH, adrHakim P);
/* I.S. terdefinisi list LH yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada awal list */

void insertAfterHakim(ListHakim &LH, adrHakim Prec, adrHakim P);
/* I.S. terdefinisi list LH yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */

void insertLastHakim(ListHakim &LH, adrHakim P);
/* I.S. terdefinisi list LH yang mungkin kosong dan elemen list P
   F.S. menempatkan elemen beralamat P pada akhir list */

// penghapusan sebuah elemen
void deleteFirstHakim(ListHakim &LH, adrHakim &P);
/* I.S. terdefinisi list LH yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari elemen pertama list yang akan dihapus */

void deleteLastHakim(ListHakim &LH, adrHakim &P);
/* I.S. terdefinisi list LH yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari elemen terakhir list yang akan dihapus */

void deleteAfterHakim(ListHakim &LH, adrHakim Prec, adrHakim &P);
/* I.S. terdefinisi list LH yang mungkin kosong, elemen list P dan elemen list Prec
   F.S. P adalah alamat dari elemen list setelah Prec yang akan dihapus */

// menampilkan isi list
void printInfoHakim(ListHakim LH);
/* I.S. terdefinisi list LH yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list */

// pengecekan referensi terdakwa di seluruh perkara hakim
bool isTerdakwaReferenced(ListHakim LH, adrTerdakwa T);
/* I.S. terdefinisi list hakim dan alamat terdakwa
   F.S. true jika terdakwa masih direferensikan oleh perkara hakim */

// input data hakim dari user
infotypeHakim inputDataHakim();
/* I.S. ~
   F.S. meminta data hakim dari user */

#endif // HAKIM_H_INCLUDED
