#include "../../header/terdakwa.h"

void deleteFirstTerdakwa(ListTerdakwa &LT, adrTerdakwa &P) {
    if (isEmptyTerdakwa(LT)) {
        P = nullptr;
        return;
    }
    P = LT.first;
    if (LT.first == LT.last) {
        LT.first = nullptr;
        LT.last = nullptr;
    } else {
        LT.first = LT.first->next;
        P->next = nullptr;
    }
}

void deleteAfterTerdakwa(ListTerdakwa &LT, adrTerdakwa Prec, adrTerdakwa &P) {
    if (isEmptyTerdakwa(LT) || Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P == LT.last) {
        LT.last = Prec;
    }
    P->next = nullptr;
}

void deleteLastTerdakwa(ListTerdakwa &LT, adrTerdakwa &P) {
    if (isEmptyTerdakwa(LT)) {
        P = nullptr;
        return;
    }
    if (LT.first == LT.last) {
        P = LT.first;
        LT.first = nullptr;
        LT.last = nullptr;
    } else {
        // Karena SLL (tanpa prev), telusuri hingga elemen tepat sebelum last
        adrTerdakwa prevLast = LT.first;
        while (prevLast->next != LT.last) {
            prevLast = prevLast->next;
        }
        P = LT.last;
        LT.last = prevLast;
        LT.last->next = nullptr;
    }
}

void printInfoTerdakwa(ListTerdakwa LT) {
    if (isEmptyTerdakwa(LT)) {
        cout << "Daftar Terdakwa kosong." << endl;
        return;
    }
    adrTerdakwa P = LT.first;
    int no = 1;
    while (P != nullptr) {
        cout << no++ << ". [" << P->info.id_terdakwa << "] " << P->info.nama
             << " | Alamat: " << P->info.alamat << endl;
        P = P->next;
    }
}