#include "../../header/perkara.h"

bool isEmptyPerkara(ListPerkara LP) {
    return LP.first == nullptr;
}

void createListPerkara(ListPerkara &LP) {
    LP.first = nullptr;
    LP.last = nullptr;
}

adrPerkara alokasiPerkara(infotypePerkara x, adrTerdakwa T) {
    adrPerkara P = new elmPerkara;
    P->info = x;
    P->terdakwa = T;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasiPerkara(adrPerkara &P) {
    if (P != nullptr) {
        P->terdakwa = nullptr; // Putus referensi ke Child tanpa menghapus Child
        delete P;
        P = nullptr;
    }
}

adrPerkara findPerkara(ListPerkara LP, string nomor_perkara) {
    adrPerkara P = LP.first;
    while (P != nullptr) {
        if (P->info.nomor_perkara == nomor_perkara) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertFirstPerkara(ListPerkara &LP, adrPerkara P) {
    if (P == nullptr) return;
    P->prev = nullptr;
    if (isEmptyPerkara(LP)) {
        P->next = nullptr;
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertAfterPerkara(ListPerkara &LP, adrPerkara Prec, adrPerkara P) {
    if (isEmptyPerkara(LP) || Prec == nullptr || P == nullptr) return;
    P->next = Prec->next;
    P->prev = Prec;
    if (Prec->next != nullptr) {
        Prec->next->prev = P;
    } else {
        LP.last = P;
    }
    Prec->next = P;
}

void insertLastPerkara(ListPerkara &LP, adrPerkara P) {
    if (P == nullptr) return;
    P->next = nullptr;
    if (isEmptyPerkara(LP)) {
        P->prev = nullptr;
        LP.first = P;
        LP.last = P;
    } else {
        P->prev = LP.last;
        LP.last->next = P;
        LP.last = P;
    }
}

infotypePerkara inputDataPerkara() {
    infotypePerkara x;
    cout << "Nomor Perkara  : ";
    cin >> x.nomor_perkara;
    cout << "Tanggal Sidang : ";
    getline(cin >> ws, x.tanggal_sidang);
    cout << "Peran Hakim    : ";
    getline(cin >> ws, x.peran_hakim);
    cout << "Status Perkara : ";
    getline(cin >> ws, x.status_perkara);
    cout << "Biaya Perkara  : ";
    cin >> x.biaya_perkara;
    return x;
}