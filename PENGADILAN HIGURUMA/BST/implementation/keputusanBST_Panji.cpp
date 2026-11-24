#include "../header/keputusanBST.h"

bool isLessPutusan(infotypePutusan left, infotypePutusan right) {
    return left.nomor_putusan < right.nomor_putusan;
}

bool isEmptyBST(BST T) {
    return T.root == nullptr;
}

void createBST(BST &T) {
    T.root = nullptr;
}

adrPutusan alokasiPutusan(infotypePutusan x) {
    adrPutusan P = new nodePutusan;
    P->info = x;
    P->left = nullptr;
    P->right = nullptr;
    return P;
}

void dealokasiPutusan(adrPutusan &P) {
    delete P;
    P = nullptr;
}

adrPutusan findPutusan(BST T, string nomor_putusan) {
    adrPutusan curr = T.root;
    while (curr != nullptr) {
        if (nomor_putusan == curr->info.nomor_putusan) {
            return curr;
        } else if (nomor_putusan < curr->info.nomor_putusan) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return nullptr;
}

void insertPutusan(BST &T, adrPutusan P) {
    if (P == nullptr) return;

    if (isEmptyBST(T)) {
        T.root = P;
        return;
    }

    adrPutusan curr = T.root;
    adrPutusan parent = nullptr;

    while (curr != nullptr) {
        parent = curr;
        if (P->info.nomor_putusan == curr->info.nomor_putusan) {
            // Nomor putusan unik; tidak memasukkan duplikat
            return;
        } else if (isLessPutusan(P->info, curr->info)) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (isLessPutusan(P->info, parent->info)) {
        parent->left = P;
    } else {
        parent->right = P;
    }
}

infotypePutusan inputDataPutusan() {
    infotypePutusan x;
    cout << "Nomor Putusan (Unik) : ";
    cin >> x.nomor_putusan;
    cout << "Nomor Perkara        : ";
    cin >> x.nomor_perkara;
    cout << "ID Hakim             : ";
    cin >> x.id_hakim;
    cout << "ID Terdakwa          : ";
    cin >> x.id_terdakwa;
    cout << "Tanggal Putusan      : ";
    getline(cin >> ws, x.tanggal_putusan);
    cout << "Hasil Keputusan      : ";
    getline(cin >> ws, x.hasil_keputusan);
    cout << "Jenis Hukuman        : ";
    getline(cin >> ws, x.jenis_hukuman);
    cout << "Status Banding       : ";
    getline(cin >> ws, x.status_banding);
    return x;
}