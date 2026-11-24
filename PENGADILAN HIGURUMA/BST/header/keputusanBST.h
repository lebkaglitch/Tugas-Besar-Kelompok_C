#ifndef PUTUSANBST_H_INCLUDED        //Di kerjakan oleh Muhammad Panji Adirangga_103012500229
#define PUTUSANBST_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

struct Putusan {
    string nomor_putusan;   // Key utama BST (Unik)
    string nomor_perkara;
    string id_hakim;
    string id_terdakwa;
    string tanggal_putusan;
    string hasil_keputusan;
    string jenis_hukuman;
    string status_banding;
};

typedef Putusan infotypePutusan;        // variabel alias untuk info
typedef struct nodePutusan *adrPutusan; // variabel alias untuk pointer

// tipe bentukan dari elemen node
struct nodePutusan {
    infotypePutusan info;
    adrPutusan left;
    adrPutusan right;
};

// tipe bentukan dari BST
struct BST {
    adrPutusan root;
};

// fungsi pembantu komparasi key BST
bool isLessPutusan(infotypePutusan left, infotypePutusan right);
/* I.S. record left dan right terdefinisi
   F.S. true jika nomor_putusan left berada sebelum right secara leksikografis/numerik */

// pengecekan apakah BST kosong
bool isEmptyBST(BST T);
/* I.S. BST T terdefinisi
   F.S. true jika BST kosong dan false jika tidak kosong */

// pembuatan BST kosong
void createBST(BST &T);
/* I.S. ~
   F.S. terbentuk BST kosong */

// manajemen memori
adrPutusan alokasiPutusan(infotypePutusan x);
/* I.S. info x terdefinisi
   F.S. mengembalikan alamat node berisi x dengan anak kiri dan kanan NULL */

void dealokasiPutusan(adrPutusan &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// pencarian sebuah elemen node
adrPutusan findPutusan(BST T, string nomor_putusan);
/* I.S. BST T dan nomor_putusan terdefinisi
   F.S. mengembalikan alamat node yang cocok atau NULL jika tidak ditemukan */

// penambahan elemen
void insertPutusan(BST &T, adrPutusan P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. menempatkan elemen beralamat P ke dalam BST berdasarkan nomor_putusan */

// penghapusan node yang sudah diketahui alamatnya
void deleteNodePutusan(BST &T, adrPutusan &P);
/* I.S. terdefinisi BST T yang mungkin kosong dan elemen node P
   F.S. node P dihapus dan digantikan sesuai aturan BST (successor/predecessor) */

void deletePutusanByNomor(BST &T, string nomor_putusan);
/* I.S. terdefinisi BST T dan nomor_putusan
   F.S. record yang cocok dihapus jika ditemukan */

// traversal BST
void printInOrder(adrPutusan root);
/* I.S. terdefinisi root BST T
   F.S. seluruh record ditampilkan dengan traversal in-order */

void printPreOrder(adrPutusan root);
/* I.S. terdefinisi root BST T
   F.S. seluruh record ditampilkan dengan traversal pre-order */

void printPostOrder(adrPutusan root);
/* I.S. terdefinisi root BST T
   F.S. seluruh record ditampilkan dengan traversal post-order */

// operasi analitik dasar BST
adrPutusan findMinPutusan(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan nomor_putusan terkecil atau NULL jika BST kosong */

adrPutusan findMaxPutusan(BST T);
/* I.S. terdefinisi BST T
   F.S. mengembalikan node dengan nomor_putusan terbesar atau NULL jika BST kosong */

int heightBST(adrPutusan root);
/* I.S. terdefinisi root BST T
   F.S. mengembalikan tinggi BST; tinggi pohon kosong adalah 0 */

int countNodesBST(adrPutusan root);
/* I.S. terdefinisi root BST T
   F.S. mengembalikan jumlah node dalam BST */

// input data putusan dari user
infotypePutusan inputDataPutusan();
/* I.S. ~
   F.S. meminta data putusan persidangan dari user */

#endif // PUTUSANBST_H_INCLUDED
