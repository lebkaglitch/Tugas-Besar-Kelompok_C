# Tugas-BesarKelompok-C-Topik-13

## Deskripsi
Aplikasi pengelolaan persidangan (Adil.in) mencatat hakim dan terdakwa yang terlibat dalam berbagai perkara. Seorang hakim dapat menangani banyak perkara dan seorang terdakwa dapat terlibat dalam beberapa perkara yang ditangani oleh hakim berbeda. Setiap perkara memiliki nomor perkara, jadwal sidang, dan penugasan hakim. Data penanganan perkara dikelola melalui Multi Linked List, sedangkan putusan persidangan dicatat dalam Binary Search Tree.

---

## Struktur Data

| List | Deskripsi |
|----------|--------|
| Hakim (Parent) | Hakim (id hakim, nama, jabatan, pengadilan) |
| Terdakwa (Child) | Terdakwa (id terdakwa, nama, alamat) |
| Perkara (Relasi) | Penanganan Perkara (nomor perkara, tanggal sidang, peran hakim, status perkara, biaya perkara) |
| Binary Search Tree | Putusan persidangan dengan key nomor putusan (nomor perkara, id hakim, id terdakwa, tanggal putusan, hasil keputusan, jenis hukuman, status banding) |

> **Catatan Relasi:** Hubungan hakim dan terdakwa dibedakan berdasarkan nomor perkara. Satu terdakwa dapat terlibat dalam beberapa perkara dengan hakim yang berbeda.

---

## Fitur / Fungsional Program
### Fungsional Umum
Fungsionalitas yang harus terpenuhi untuk **Multi-Linked List** adalah 
1. Menyisipkan elemen Hakim, Terdakwa, dan Perkara (first, last, after).
2. Menghapus elemen Hakim, Terdakwa, dan Perkara (first, last, after).
3. Mencari elemen Hakim, Terdakwa, dan Perkara.
4. Menampilkan seluruh data pada list (Hakim, Terdakwa, Perkara).
5. Membuat data dummy untuk masing-masing list minimal 5 data (Hakim, Terdakwa) dan 10 data (Perkara).
6. Main Program (interface).

Fungsionalitas yang harus terpenuhi untuk **Binary Search Tree** adalah 
1. Menyisipkan node berisikan putusan persidangan berdasarkan nomor putusan.
2. Menghapus node berisikan putusan persidangan berdasarkan nomor putusan. 
3. Mencari node berisikan putusan persidangan berdasarkan nomor putusan.
4. Menampilkan seluruh data secara traversal (in-order, pre-order, dan post-order).
5. Menampilkan nilai minimum, maksimum, tinggi pohon, dan jumlah node.
6. Membuat data dummy untuk BST minimal 10 node berisikan putusan persidangan.
7. Melengkapi Main Program (interface).

### Fungsional Khusus
Fungsionalitas / studi kasus yang dipilih dari topik ini adalah
1. Melakukan pencatatan penanganan perkara dengan memilih hakim dan terdakwa yang terlibat. Satu hakim dapat menangani beberapa perkara dan satu terdakwa dapat terlibat dalam beberapa perkara yang ditangani oleh hakim berbeda.
2. Mencatat putusan persidangan untuk setiap perkara yang telah disidangkan ke dalam BST berdasarkan nomor putusan.
3. Menampilkan daftar perkara dan putusan persidangan berdasarkan
