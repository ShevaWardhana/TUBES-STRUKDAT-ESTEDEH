#include "application.h"

/* -- M1 --
 * I.S.: P tidak NULL.
 * F.S.: P->relFirst = NULL. */
void CreateRelasi(AdrPelamar P) {
    // TODO: Set P->relFirst = NULL
}

/* -- M2 — INSERT FIRST pada list relasi --
 * I.S.: P tidak NULL; ptrLow valid; belum ada duplikat lamaran.
 * F.S.: ElmtRelasi baru ditambahkan di awal list relasi P. */
void InsertRelasi(AdrPelamar P, AdrLowongan ptrLow) {
    // TODO: Alokasi ElmtRelasi baru dengan 'new'
    // TODO: Isi ptrLowongan = ptrLow (pointer ke node Lowongan)
    // TODO: next node baru = P->relFirst
    // TODO: P->relFirst = node baru (insert first)
}

/* -- M3 --
 * I.S.: P tidak NULL; id_lowongan[] valid.
 * F.S.: Jika ditemukan relasi ke id_lowongan[], ElmtRelasi dihapus;
 *       jika tidak ditemukan, list relasi P tidak berubah. */
void DeleteRelasi(AdrPelamar P, char id_lowongan[]) {
    // TODO: Guard: jika P == NULL → tidak melakukan apa-apa
    // TODO: Gunakan dua pointer bantu: prev = NULL dan curr = P->relFirst
    // TODO: Traversal dengan flag ketemu (bool ketemu = false):
    //       while (curr != NULL && !ketemu)
    //         jika curr->ptrLowongan != NULL &&
    //              strcmp(curr->ptrLowongan->info.id_lowongan, id_lowongan) == 0
    //           → ketemu = true
    //         else
    //           → prev = curr; curr = curr->next;
    //       (jangan gunakan break/return di dalam perulangan)
    // TODO: Jika ketemu && curr != NULL:
    //       - Jika curr == P->relFirst → P->relFirst = curr->next
    //       - Jika bukan First         → prev->next = curr->next
    //       - Putus pointer sebelum delete: curr->next = NULL; curr->ptrLowongan = NULL;
    //       - Bebaskan memori: delete curr
}

/* -- M4 --
 * I.S.: P tidak NULL.
 * F.S.: Semua lowongan yang dilamar P dicetak. */
void PrintLamaranPelamar(AdrPelamar P) {
    // TODO: Guard: jika P == NULL → keluar tanpa akses pointer
    // TODO: Cetak header: "Lamaran dari [P->info.nama]:"
    // TODO: Jika P->relFirst == NULL → cetak "Belum ada lamaran."
    // TODO: Jika ada, gunakan pointer bantu curr = P->relFirst
    // TODO: Traversal while (curr != NULL):
    //       cek curr->ptrLowongan != NULL sebelum mencetak
    //       curr->ptrLowongan->info (id_lowongan, judul_posisi, perusahaan)
}

/* -- M5 --
 * I.S.: LP terdefinisi; id_lowongan[] valid.
 * F.S.: Setiap pelamar yang melamar ke id_lowongan[] dicetak maksimal satu kali. */
void PrintPelamarLowongan(ListPelamar LP, char id_lowongan[]) {
    // TODO: Cetak header: "Pelamar untuk lowongan [id_lowongan]:"
    // TODO: Pointer bantu currP = LP.First
    // TODO: Loop luar: while (currP != NULL) untuk traversal ListPelamar
    // TODO: Di dalam loop luar:
    //       - Gunakan flag bool ketemu = false dan pointer currR = currP->relFirst
    //       - Loop dalam: while (currR != NULL && !ketemu)
    //         cek currR->ptrLowongan != NULL &&
    //             strcmp(currR->ptrLowongan->info.id_lowongan, id_lowongan) == 0
    //         jika cocok → ketemu = true (hentikan loop dalam tanpa break/return)
    //       - DI LUAR loop dalam: jika ketemu == true → cetak info currP
    //         (menjamin setiap Pelamar tercetak maksimal 1 kali / tidak berulang)
    //       - Geser currP = currP->next
    // TODO: Jangan gunakan break/return di dalam perulangan
}

/* -- M6 --
 * I.S.: P tidak NULL.
 * F.S.: Mengembalikan true jika P sudah melamar ke id_lowongan[]. */
bool IsAlreadyApplied(AdrPelamar P, char id_lowongan[]) {
    // TODO: Gunakan pointer bantu curr = (P != NULL) ? P->relFirst : NULL
    //       dan variabel hasil (bool hasil = false)
    // TODO: Traversal while (curr != NULL && !hasil):
    //       jika curr->ptrLowongan != NULL &&
    //            strcmp(curr->ptrLowongan->info.id_lowongan, id_lowongan) == 0
    //       → hasil = true
    // TODO: Kembalikan hasil setelah perulangan selesai
}

/* -- M7 --
 * I.S.: LP terdefinisi; id_lowongan[] valid.
 * F.S.: Semua ElmtRelasi yang menunjuk ke lowongan tersebut dihapus. */
void DeleteRelasiAllPelamar(ListPelamar &LP, char id_lowongan[]) {
    // TODO: Traversal seluruh ListPelamar (pointer bantu currP = LP.First)
    // TODO: Untuk setiap pelamar (while currP != NULL), panggil DeleteRelasi(currP, id_lowongan)
    //       (aman dipanggil langsung karena DeleteRelasi mengecek ketemu sebelum delete,
    //        sehingga hanya butuh satu kali traversal per pelamar)
    // TODO: Jangan gunakan break/return di dalam perulangan
}

/* -- M8 --
 * I.S.: P tidak NULL.
 * F.S.: Semua ElmtRelasi milik P dihapus; P->relFirst = NULL. */
void DeleteAllRelasi(AdrPelamar P) {
    // TODO: Guard: jika P == NULL → tidak melakukan apa-apa
    // TODO: Inisialisasi SEBELUM loop:
    //       AdrRelasi curr = P->relFirst;
    //       AdrRelasi nextNode = NULL;
    // TODO: Set P->relFirst = NULL sebelum/sesudah loop agar tidak dangling
    // TODO: Traversal while (curr != NULL):
    //       nextNode = curr->next;
    //       curr->next = NULL;
    //       curr->ptrLowongan = NULL;
    //       delete curr;
    //       curr = nextNode;
    //       (jangan akses curr setelah 'delete curr'; gunakan nextNode yang sudah disimpan)
    // TODO: Jangan gunakan break/return di dalam perulangan
}
