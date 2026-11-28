#ifndef DUMMY_H_INCLUDED
#define DUMMY_H_INCLUDED

#include "MLL-01/header/hakim.h"
#include "MLL-01/header/perkara.h"
#include "MLL-01/header/terdakwa.h"
#include "BST/header/keputusanBST.h"

void dummyHakim(ListHakim &LH);
/* I.S. LH terdefinisi dan kosong
   F.S. LH berisi minimal 5 data hakim */

void dummyTerdakwa(ListTerdakwa &LT);
/* I.S. LT terdefinisi dan kosong
   F.S. LT berisi minimal 5 data terdakwa */

void dummyPerkara(ListHakim &LH, ListTerdakwa &LT);
/* I.S. LH berisi data hakim dan LT berisi data terdakwa
   F.S. daftar perkara pada elemen hakim berisi minimal 10 relasi ke terdakwa */

void dummyPutusan(BST &T);
/* I.S. T terdefinisi dan kosong
   F.S. T berisi minimal 10 node putusan persidangan dengan nomor_putusan unik dan acak */

#endif // DUMMY_H_INCLUDED
