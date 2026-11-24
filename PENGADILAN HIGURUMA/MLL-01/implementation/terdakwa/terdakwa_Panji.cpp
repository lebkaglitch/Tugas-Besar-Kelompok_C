#include "../../header/terdakwa.h"

bool isEmptyTerdakwa(ListTerdakwa LT) {
    return LT.first == nullptr;
}

void createListTerdakwa(ListTerdakwa &LT) {
    LT.first = nullptr;
    LT.last = nullptr;
}

adrTerdakwa alokasiTerdakwa(infotypeTerdakwa x) {
    adrTerdakwa P = new elmTerdakwa;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasiTerdakwa(adrTerdakwa &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

adrTerdakwa findTerdakwa(ListTerdakwa LT, string id_terdakwa) {
    adrTerdakwa P = LT.first;
    while (P != nullptr) {
        if (P->info.id_terdakwa == id_terdakwa) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertFirstTerdakwa(ListTerdakwa &LT, adrTerdakwa P) {
    if (P == nullptr) return;
    if (isEmptyTerdakwa(LT)) {
        LT.first = P;
        LT.last = P;
    } else {
        P->next = LT.first;
        LT.first = P;
    }
}

void insertAfterTerdakwa(ListTerdakwa &LT, adrTerdakwa Prec, adrTerdakwa P) {
    if (P == nullptr || Prec == nullptr) return;
    P->next = Prec->next;
    Prec->next = P;
    if (Prec == LT.last) {
        LT.last = P;
    }
}

void insertLastTerdakwa(ListTerdakwa &LT, adrTerdakwa P) {
    if (P == nullptr) return;
    if (isEmptyTerdakwa(LT)) {
        LT.first = P;
        LT.last = P;
    } else {
        LT.last->next = P;
        LT.last = P;
    }
}

infotypeTerdakwa inputDataTerdakwa() {
    infotypeTerdakwa x;
    cout << "ID Terdakwa   : ";
    cin >> x.id_terdakwa;
    cout << "Nama Terdakwa : ";
    getline(cin >> ws, x.nama);
    cout << "Alamat        : ";
    getline(cin >> ws, x.alamat);
    return x;
}