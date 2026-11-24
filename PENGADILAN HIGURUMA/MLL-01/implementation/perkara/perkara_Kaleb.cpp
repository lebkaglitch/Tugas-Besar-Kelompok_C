#include "../../header/perkara.h"

void deleteFirstPerkara(ListPerkara &LP, adrPerkara &P) {
    if (isEmptyPerkara(LP)) {
        P = nullptr;
        return;
    }
    P = LP.first;
    if (LP.first == LP.last) {
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        LP.first = LP.first->next;
        LP.first->prev = nullptr;
    }
    P->next = nullptr;
    P->prev = nullptr;
}

void deleteAfterPerkara(ListPerkara &LP, adrPerkara Prec, adrPerkara &P) {
    if (isEmptyPerkara(LP) || Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        LP.last = Prec;
    }
    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLastPerkara(ListPerkara &LP, adrPerkara &P) {
    if (isEmptyPerkara(LP)) {
        P = nullptr;
        return;
    }
    P = LP.last;
    if (LP.first == LP.last) {
        LP.first = nullptr;
        LP.last = nullptr;
    } else {
        LP.last = LP.last->prev;
        LP.last->next = nullptr;
    }
    P->next = nullptr;
    P->prev = nullptr;
}

void printInfoPerkara(ListPerkara LP) {
    if (isEmptyPerkara(LP)) {
        cout << "   (Belum ada perkara yang ditangani)" << endl;
        return;
    }
    adrPerkara P = LP.first;
    while (P != nullptr) {
        cout << "   - No. Perkara: " << P->info.nomor_perkara
             << " | Tgl Sidang: " << P->info.tanggal_sidang
             << " | Peran: " << P->info.peran_hakim
             << " | Status: " << P->info.status_perkara
             << " | Biaya: Rp" << P->info.biaya_perkara;
        if (P->terdakwa != nullptr) {
            cout << " | Terdakwa: " << P->terdakwa->info.nama
                 << " (" << P->terdakwa->info.id_terdakwa << ")";
        }
        cout << endl;
        P = P->next;
    }
}