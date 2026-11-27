#ifndef APPLICANT_H
#define APPLICANT_H

#include <stdio.h>
#include <string.h>

/* ============================================================
 * BAGIAN 1 — INFOTYPE PELAMAR
 * ============================================================ */
typedef struct {
    char id_pelamar[10];   /* Primary key — contoh: "P001"      */
    char nama[50];         /* Nama lengkap pelamar               */
    int  usia;             /* Usia pelamar (tahun)               */
    char pendidikan[20];   /* Jenjang pendidikan: "S1","D3","SMA"*/
    char keahlian[50];     /* Keahlian utama pelamar             */
} InfotypePelamar;

/* ============================================================
 * BAGIAN 2 — FORWARD DECLARATION
 * ElmtRelasi didefinisikan penuh di application.h.
 * Digunakan di sini hanya sebagai tipe pointer (AdrRelasi).
 * ============================================================ */
struct ElmtRelasi;
typedef struct ElmtRelasi *AdrRelasi;

/* ============================================================
 * BAGIAN 3 — DEKLARASI ELEMEN & LIST PELAMAR
 * ============================================================ */
typedef struct ElmtPelamar *AdrPelamar;

typedef struct ElmtPelamar {
    InfotypePelamar info;       /* data isi node pelamar              */
    AdrRelasi       relFirst;   /* pointer ke list relasi (MLL-01)    */
    AdrPelamar      next;       /* pointer ke elemen Pelamar berikutnya */
} ElmtPelamar;

typedef struct {
    AdrPelamar First;           /* pointer ke elemen pertama list     */
} ListPelamar;

/* ============================================================
 * BAGIAN 4 — PROTOTYPE SUBPROGRAM
 * ============================================================ */

/* -- A1 --
 * Menginisialisasi list pelamar sebagai list kosong.
 * I.S.: L sembarang.
 * F.S.: L.First = NULL; list siap digunakan. */
void CreateListPelamar(ListPelamar &L);

/* -- A2 --
 * Memeriksa apakah list pelamar kosong.
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan true jika L.First = NULL, false jika tidak.
 *       L tidak berubah. */
bool IsEmptyPelamar(ListPelamar L);

/* -- A3 --
 * Menambahkan pelamar baru di AKHIR list (INSERT LAST).
 * I.S.: L terdefinisi; data berisi informasi pelamar yang valid.
 * F.S.: Node baru dengan info = data ditambahkan di akhir L;
 *       relFirst node baru = NULL; next node baru = NULL. */
void InsertLastPelamar(ListPelamar &L, InfotypePelamar data);

/* -- A4 --
 * Menghapus pelamar dari list berdasarkan id_pelamar.
 * I.S.: L tidak kosong; terdapat node dengan id_pelamar == id[];
 *       seluruh list relasi milik node pelamar tersebut SUDAH
 *       dibersihkan terlebih dahulu melalui DeleteAllRelasi(P)
 *       sebelum node pelamar dihapus agar tidak terjadi memory leak.
 * F.S.: Node dengan id dihapus dari L dan memori dibebaskan;
 *       data pelamar yang dihapus disalin ke out. */
void DeletePelamarById(ListPelamar &L, char id[], InfotypePelamar &out);

/* -- A5 --
 * Mencetak seluruh data pelamar di list ke layar.
 * I.S.: L terdefinisi.
 * F.S.: Semua elemen L dicetak secara berurutan dari First;
 *       L tidak berubah. */
void PrintListPelamar(ListPelamar L);

/* -- A6 --
 * Mencari node pelamar berdasarkan id_pelamar (linear search).
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id_pelamar == id[];
 *       mengembalikan NULL jika tidak ditemukan; L tidak berubah. */
AdrPelamar FindPelamarById(ListPelamar L, char id[]);

#endif /* APPLICANT_H */
