#include "../../header/hakim.h"

void deleteFirstHakim(ListHakim &LH, adrHakim &P) {
    if (isEmptyHakim(LH)) {
        P = nullptr;
        return;
    }
    P = LH.first;
    if (LH.first == LH.last) {
        LH.first = nullptr;
        LH.last = nullptr;
    } else {
        LH.first = LH.first->next;
        P->next = nullptr;
    }
}

void deleteAfterHakim(ListHakim &LH, adrHakim Prec, adrHakim &P) {
    if (isEmptyHakim(LH) || Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P == LH.last) {
        LH.last = Prec;
    }
    P->next = nullptr;
}

void deleteLastHakim(ListHakim &LH, adrHakim &P) {
    if (isEmptyHakim(LH)) {
        P = nullptr;
        return;
    }
    if (LH.first == LH.last) {
        P = LH.first;
        LH.first = nullptr;
        LH.last = nullptr;
    } else {
        // Karena SLL (tanpa prev), cari elemen tepat sebelum last
        adrHakim prevLast = LH.first;
        while (prevLast->next != LH.last) {
            prevLast = prevLast->next;
        }
        P = LH.last;
        LH.last = prevLast;
        LH.last->next = nullptr;
    }
}

void printInfoHakim(ListHakim LH) {
    if (isEmptyHakim(LH)) {
        cout << "Daftar Hakim kosong." << endl;
        return;
    }
    adrHakim P = LH.first;
    int no = 1;
    while (P != nullptr) {
        cout << no++ << ". [" << P->info.id_hakim << "] " << P->info.nama
             << " | Jabatan: " << P->info.jabatan
             << " | Pengadilan: " << P->info.pengadilan << endl;
        P = P->next;
    }
}

bool isTerdakwaReferenced(ListHakim LH, adrTerdakwa T) {
    if (T == nullptr) return false;
    adrHakim H = LH.first;
    while (H != nullptr) {
        adrPerkara R = H->listPerkara.first;
        while (R != nullptr) {
            if (R->terdakwa == T) {
                return true;
            }
            R = R->next;
        }
        H = H->next;
    }
    return false;
}