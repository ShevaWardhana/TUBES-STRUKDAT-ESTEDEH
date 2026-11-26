/* ============================================================
 * FILE        : main.cpp
 * MODUL       : Program Utama
 * DESKRIPSI   : Entry point aplikasi Job Portal and Applicant
 *               Management System. Mengelola menu utama dan
 *               mengintegrasikan seluruh modul ADT.
 * DIBUAT OLEH : [ESTEDEH]
 *
 * ATURAN:
 * - Tidak boleh menggunakan break atau return di dalam perulangan.
 * - Tidak boleh menggunakan variabel global.
 * - Semua struktur data dideklarasikan di main() dan dioper
 *   ke subprogram melalui parameter.
 * - Tanggung jawab sinkronisasi antara ListPelamar dan BSTTree
 *   berada pada pengelola sistem (main.cpp), bukan di dalam
 *   InsertBST/DeleteBST atau InsertLastPelamar/DeletePelamarById.
 * ============================================================ */

#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "jobvacancy.h"
#include "application.h"
#include "bst.h"

/* ============================================================
 * PROTOTYPE SUBPROGRAM MENU
 * (Didefinisikan di bawah main, dipanggil dari menu utama)
 * ============================================================ */

/* Menu: Kelola Pelamar
 * I.S.: LP dan T terdefinisi.
 * F.S.: Operasi pengelolaan pelamar dijalankan sesuai pilihan;
 *       penghapusan pelamar selalu didahului pembersihan seluruh relasinya,
 *       dan sinkronisasi data antara LP (ListPelamar) dan T (BSTTree)
 *       tetap terjaga pada setiap operasi tambah dan hapus pelamar. */
void menuKelolaPelamar(ListPelamar &LP, BSTTree &T);

/* Menu: Kelola Lowongan
 * I.S.: LL dan LP terdefinisi.
 * F.S.: Operasi pengelolaan lowongan dijalankan sesuai pilihan;
 *       penghapusan lowongan hanya dilakukan setelah relasi terkait
 *       di LP dibersihkan terlebih dahulu. */
void menuKelolaLowongan(ListLowongan &LL, ListPelamar &LP);

/* Menu: Kelola Lamaran
 * I.S.: LP dan LL terdefinisi.
 * F.S.: Operasi pengelolaan lamaran dijalankan sesuai pilihan. */
void menuKelolaLamaran(ListPelamar &LP, ListLowongan &LL);

/* Menu: Pencarian BST
 * I.S.: T terdefinisi.
 * F.S.: Hasil pencarian ditampilkan sesuai pilihan. */
void menuPencarian(BSTTree T);

/* Mencetak header/judul program ke layar.
 * I.S.: -
 * F.S.: Header program tercetak di layar. */
void printHeader();

/* Mencetak menu utama ke layar.
 * I.S.: -
 * F.S.: Pilihan menu utama tercetak. */
void printMenuUtama();

/* ============================================================
 * MAIN PROGRAM
 * ============================================================ */
int main() {
    /* Deklarasi semua struktur data utama */
    ListPelamar  LP;    /* Daftar semua pelamar (Singly LL)   */
    ListLowongan LL;    /* Daftar semua lowongan (Singly LL)  */
    BSTTree      T;     /* BST untuk pencarian pelamar        */

    /* Inisialisasi semua struktur */
    CreateListPelamar(LP);
    CreateListLowongan(LL);
    CreateBST(T);

    int pilihan;

    /* Loop menu utama
     * I.S.: Semua struktur sudah diinisialisasi.
     * F.S.: Program berjalan sampai pengguna memilih keluar. */

    // TODO: Implementasi loop menu utama
    // PERHATIAN: Tidak boleh menggunakan break atau return
    //            di dalam perulangan. Gunakan kondisi boolean
    //            atau pengecekan langsung pada kondisi while.
    //
    // Contoh pola yang DIIZINKAN:
    //   pilihan = 0;
    //   do {
    //       printHeader();
    //       printMenuUtama();
    //       scanf("%d", &pilihan);
    //       if (pilihan == 1) menuKelolaPelamar(LP, T);
    //       else if (pilihan == 2) menuKelolaLowongan(LL, LP);
    //       else if (pilihan == 3) menuKelolaLamaran(LP, LL);
    //       else if (pilihan == 4) menuPencarian(T);
    //       else if (pilihan != 0) printf("Pilihan tidak valid.\n");
    //   } while (pilihan != 0);

    return 0;
}

/* ============================================================
 * IMPLEMENTASI SUBPROGRAM MENU
 * ============================================================ */

void printHeader() {
    /* I.S.: -
     * F.S.: Header tercetak. */
    // TODO: printf("============================================\n");
    // TODO: printf("  JOB PORTAL AND APPLICANT MANAGEMENT SYSTEM\n");
    // TODO: printf("============================================\n");
}

void printMenuUtama() {
    /* I.S.: -
     * F.S.: Menu utama tercetak. */
    // TODO:
    // printf("\n1. Kelola Pelamar\n");
    // printf("2. Kelola Lowongan Pekerjaan\n");
    // printf("3. Kelola Lamaran\n");
    // printf("4. Pencarian (BST)\n");
    // printf("0. Keluar\n");
    // printf("Pilih: ");
}

void menuKelolaPelamar(ListPelamar &LP, BSTTree &T) {
    /* I.S.: LP dan T terdefinisi.
     * F.S.: Operasi pelamar dijalankan sesuai sub-pilihan dengan
     *       menjaga sinkronisasi LP dan T. */
    // TODO: Tampilkan sub-menu (tanpa break/return dalam perulangan):
    //   1.1 Tambah Pelamar   → input data
    //                          1) Validasi duplikat ID dulu (SearchBST / FindPelamarById)
    //                          2) Jika unik, jaga sinkronisasi LP dan T dengan memanggil
    //                             InsertLastPelamar(LP, data) dan InsertBST(T, data)
    //   1.2 Hapus Pelamar    → input id
    //                          1) Cari node pelamar via FindPelamarById(LP, id)
    //                          2) Jika ditemukan:
    //                             a) Panggil DeleteAllRelasi(P) terlebih dahulu
    //                             b) Jaga sinkronisasi LP dan T dengan memanggil
    //                                DeletePelamarById(LP, id, out) dan DeleteBST(T, id)
    //   1.3 Tampilkan Semua  → PrintListPelamar(LP)
    //   0.  Kembali
}

void menuKelolaLowongan(ListLowongan &LL, ListPelamar &LP) {
    /* I.S.: LL dan LP terdefinisi.
     * F.S.: Operasi lowongan dijalankan sesuai sub-pilihan. */
    // TODO: Tampilkan sub-menu (tanpa break/return dalam perulangan):
    //   2.1 Tambah Lowongan  → input data, InsertFirstLowongan(LL, data)
    //   2.2 Hapus Lowongan   → input id
    //                          1) Pastikan lowongan ada via FindLowonganById(LL, id)
    //                          2) WAJIB bersihkan seluruh relasi yang menunjuk ke
    //                             lowongan ini lebih dulu: DeleteRelasiAllPelamar(LP, id)
    //                          3) Baru panggil DeleteLowonganById(LL, id, out)
    //   2.3 Tampilkan Semua  → PrintListLowongan(LL)
    //   0.  Kembali
}

void menuKelolaLamaran(ListPelamar &LP, ListLowongan &LL) {
    /* I.S.: LP dan LL terdefinisi.
     * F.S.: Operasi lamaran dijalankan sesuai sub-pilihan. */
    // TODO: Tampilkan sub-menu:
    //   3.1 Ajukan Lamaran       → input id pelamar & id lowongan
    //                              cek IsAlreadyApplied
    //                              InsertRelasi
    //   3.2 Lamaran per Pelamar  → input id pelamar
    //                              FindPelamarById → PrintLamaranPelamar
    //   3.3 Pelamar per Lowongan → input id lowongan
    //                              PrintPelamarLowongan
    //   0.  Kembali
}

void menuPencarian(BSTTree T) {
    /* I.S.: T terdefinisi.
     * F.S.: Hasil pencarian ditampilkan. */
    // TODO: Tampilkan sub-menu:
    //   4.1 Cari Pelamar berdasarkan ID → input id, SearchBST, cetak hasil
    //   4.2 Tampilkan Semua (In-Order)  → PrintInOrderBST
    //   0.  Kembali
}
