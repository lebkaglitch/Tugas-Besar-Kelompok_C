#include "../../header/hakim.h"

bool isEmptyHakim(ListHakim LH) {
    return LH.first == nullptr;
}

void createListHakim(ListHakim &LH) {
    LH.first = nullptr;
    LH.last = nullptr;
}

adrHakim alokasiHakim(infotypeHakim x) {
    adrHakim P = new elmHakim;
    P->info = x;
    P->next = nullptr;
    createListPerkara(P->listPerkara);
    return P;
}

void dealokasiHakim(adrHakim &P) {
    if (P != nullptr) {
        // Dealokasi seluruh elemen relasi perkara milik hakim ini terlebih dahulu
        adrPerkara curr = P->listPerkara.first;
        while (curr != nullptr) {
            adrPerkara temp = curr;
            curr = curr->next;
            dealokasiPerkara(temp);
        }
        P->listPerkara.first = nullptr;
        P->listPerkara.last = nullptr;

        // Dealokasi elemen hakim (terdakwa tidak ikut dihapus)
        delete P;
        P = nullptr;
    }
}

adrHakim findHakim(ListHakim LH, string id_hakim) {
    adrHakim P = LH.first;
    while (P != nullptr) {
        if (P->info.id_hakim == id_hakim) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertFirstHakim(ListHakim &LH, adrHakim P) {
    if (P == nullptr) return;
    if (isEmptyHakim(LH)) {
        P->next = nullptr;
        LH.first = P;
        LH.last = P;
    } else {
        P->next = LH.first;
        LH.first = P;
    }
}

void insertAfterHakim(ListHakim &LH, adrHakim Prec, adrHakim P) {
    if (P == nullptr || Prec == nullptr) return;
    P->next = Prec->next;
    Prec->next = P;
    if (Prec == LH.last) {
        LH.last = P;
    }
}

void insertLastHakim(ListHakim &LH, adrHakim P) {
    if (P == nullptr) return;
    P->next = nullptr;
    if (isEmptyHakim(LH)) {
        LH.first = P;
        LH.last = P;
    } else {
        LH.last->next = P;
        LH.last = P;
    }
}

infotypeHakim inputDataHakim() {
    infotypeHakim x;
    cout << "ID Hakim   : ";
    cin >> x.id_hakim;
    cout << "Nama Hakim : ";
    getline(cin >> ws, x.nama);
    cout << "Jabatan    : ";
    getline(cin >> ws, x.jabatan);
    cout << "Pengadilan : ";
    getline(cin >> ws, x.pengadilan);
    return x;
}