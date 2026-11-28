#include "dummy.h"

namespace {
    void appendPerkara(ListHakim &LH, ListTerdakwa &LT,
                       const string &idHakim, const string &idTerdakwa,
                       const string &noPerkara, const string &tglSidang,
                       const string &peranHakim, const string &statusPerkara,
                       long biayaPerkara) {
        adrHakim parent = findHakim(LH, idHakim);
        adrTerdakwa child = findTerdakwa(LT, idTerdakwa);
        if (parent != nullptr && child != nullptr) {
            infotypePerkara info = {noPerkara, tglSidang, peranHakim, statusPerkara, biayaPerkara};
            adrPerkara node = alokasiPerkara(info, child);
            insertLastPerkara(parent->listPerkara, node);
        }
    }

    infotypePutusan makePutusan(const string &noPutusan, const string &noPerkara,
                                const string &idHakim, const string &idTerdakwa,
                                const string &tglPutusan, const string &hasilKeputusan,
                                const string &jenisHukuman, const string &statusBanding) {
        infotypePutusan info;
        info.nomor_putusan = noPutusan;
        info.nomor_perkara = noPerkara;
        info.id_hakim = idHakim;
        info.id_terdakwa = idTerdakwa;
        info.tanggal_putusan = tglPutusan;
        info.hasil_keputusan = hasilKeputusan;
        info.jenis_hukuman = jenisHukuman;
        info.status_banding = statusBanding;
        return info;
    }
}

void dummyHakim(ListHakim &LH) {
    infotypeHakim data[5] = {
        {"HKM-001", "Hiromi Higuruma, S.H., M.H.", "Hakim Ketua", "PN Jakarta Pusat"},
        {"HKM-002", "Dr. Artidjo Alkostar, S.H., LL.M.", "Hakim Agung", "MA Republik Indonesia"},
        {"HKM-003", "Ratna Sari Dewi, S.H., M.H.", "Hakim Anggota", "PN Bandung"},
        {"HKM-004", "Bambang Widjojanto, S.H., M.H.", "Hakim Ketua", "PN Surabaya"},
        {"HKM-005", "Siti Nurhaliza, S.H., M.Kn.", "Hakim Anggota", "PN Medan"}
    };

    for (int i = 0; i < 5; i++) {
        insertLastHakim(LH, alokasiHakim(data[i]));
    }
}

void dummyTerdakwa(ListTerdakwa &LT) {
    infotypeTerdakwa data[5] = {
        {"TDW-001", "Ahmad Subardjo", "Jl. Merdeka No. 12, Jakarta"},
        {"TDW-002", "Budi Santoso", "Jl. Dago No. 45, Bandung"},
        {"TDW-003", "Citra Kirana", "Jl. Sudirman No. 88, Surabaya"},
        {"TDW-004", "Dimas Anggara", "Jl. Gatot Subroto No. 21, Medan"},
        {"TDW-005", "Eka Saputra", "Jl. Diponegoro No. 10, Semarang"}
    };

    for (int i = 0; i < 5; i++) {
        insertLastTerdakwa(LT, alokasiTerdakwa(data[i]));
    }
}

void dummyPerkara(ListHakim &LH, ListTerdakwa &LT) {
    // 10 Perkara yang sudah diputus (terhubung dengan 10 node Putusan di BST)
    appendPerkara(LH, LT, "HKM-001", "TDW-001", "PRK-001", "2026-10-01", "Hakim Ketua", "Putus", 5000000);
    appendPerkara(LH, LT, "HKM-001", "TDW-002", "PRK-002", "2026-10-05", "Hakim Ketua", "Putus", 7500000);
    appendPerkara(LH, LT, "HKM-002", "TDW-001", "PRK-003", "2026-10-10", "Hakim Tunggal", "Putus", 10000000);
    appendPerkara(LH, LT, "HKM-002", "TDW-003", "PRK-004", "2026-10-12", "Hakim Ketua", "Putus", 4500000);
    appendPerkara(LH, LT, "HKM-003", "TDW-002", "PRK-005", "2026-10-15", "Hakim Anggota", "Putus", 3000000);
    appendPerkara(LH, LT, "HKM-003", "TDW-004", "PRK-006", "2026-10-18", "Hakim Ketua", "Putus", 6000000);
    appendPerkara(LH, LT, "HKM-004", "TDW-005", "PRK-007", "2026-10-20", "Hakim Ketua", "Putus", 8000000);
    appendPerkara(LH, LT, "HKM-004", "TDW-001", "PRK-008", "2026-10-25", "Hakim Anggota", "Putus", 5500000);
    appendPerkara(LH, LT, "HKM-005", "TDW-003", "PRK-009", "2026-11-02", "Hakim Ketua", "Putus", 4000000);
    appendPerkara(LH, LT, "HKM-005", "TDW-004", "PRK-010", "2026-11-08", "Hakim Tunggal", "Putus", 3500000);

    // 2 Perkara tambahan yang masih berjalan (memudahkan testing input putusan baru nanti)
    appendPerkara(LH, LT, "HKM-001", "TDW-005", "PRK-011", "2026-11-20", "Hakim Ketua", "Sidang Lanjutan", 2500000);
    appendPerkara(LH, LT, "HKM-003", "TDW-001", "PRK-012", "2026-11-24", "Hakim Anggota", "Tahap Pembuktian", 4200000);
}

void dummyPutusan(BST &T) {
    // Dimasukkan dengan urutan nomor_putusan acak agar struktur BST seimbang
    infotypePutusan data[10] = {
        makePutusan("PTS-005", "PRK-005", "HKM-003", "TDW-002", "2026-10-22", "Bersalah", "Penjara 2 Tahun", "Tidak Banding"),
        makePutusan("PTS-002", "PRK-002", "HKM-001", "TDW-002", "2026-10-12", "Bersalah", "Denda Rp50.000.000", "Banding"),
        makePutusan("PTS-008", "PRK-008", "HKM-004", "TDW-001", "2026-11-01", "Bersalah", "Penjara 3 Tahun", "Banding"),
        makePutusan("PTS-001", "PRK-001", "HKM-001", "TDW-001", "2026-10-08", "Bersalah", "Penjara 5 Tahun", "Banding"),
        makePutusan("PTS-004", "PRK-004", "HKM-002", "TDW-003", "2026-10-19", "Bebas", "Bebas Murni", "Tidak Banding"),
        makePutusan("PTS-007", "PRK-007", "HKM-004", "TDW-005", "2026-10-27", "Bersalah", "Penjara 4 Tahun", "Banding"),
        makePutusan("PTS-010", "PRK-010", "HKM-005", "TDW-004", "2026-11-15", "Lepas", "Rehabilitasi", "Tidak Banding"),
        makePutusan("PTS-003", "PRK-003", "HKM-002", "TDW-001", "2026-10-17", "Bersalah", "Penjara 6 Tahun", "Banding"),
        makePutusan("PTS-006", "PRK-006", "HKM-003", "TDW-004", "2026-10-25", "Bersalah", "Denda Rp25.000.000", "Tidak Banding"),
        makePutusan("PTS-009", "PRK-009", "HKM-005", "TDW-003", "2026-11-09", "Bersalah", "Penjara 1 Tahun", "Banding")
    };

    for (int i = 0; i < 10; i++) {
        insertPutusan(T, alokasiPutusan(data[i]));
    }
}
