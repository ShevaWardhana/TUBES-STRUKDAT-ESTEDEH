/* ============================================================
 * FILE        : jobvacancy.h
 * MODUL       : ADT List Lowongan Pekerjaan
 * DESKRIPSI   : Deklarasi tipe data dan prototype subprogram
 *               untuk mengelola daftar lowongan pekerjaan.
 * STRUKTUR    : Singly Linked List — Strategi INSERT FIRST
 * DIBUAT OLEH : [ESTEDEH]
 * ============================================================ */

#ifndef JOBVACANCY_H
#define JOBVACANCY_H

#include <stdio.h>
#include <string.h>

/* ============================================================
 * BAGIAN 1 — INFOTYPE LOWONGAN
 * ============================================================ */
typedef struct {
    char id_lowongan[10];  /* Primary key — contoh: "LK001"      */
    char judul_posisi[50]; /* Nama posisi yang ditawarkan         */
    char perusahaan[50];   /* Nama perusahaan pembuka lowongan    */
    int  gaji;             /* Kisaran gaji (dalam rupiah)         */
    char kategori[30];     /* Bidang: "IT","Finance","Marketing"  */
} InfotypeLowongan;

/* ============================================================
 * BAGIAN 2 — DEKLARASI ELEMEN & LIST LOWONGAN
 * ============================================================ */
typedef struct ElmtLowongan *AdrLowongan;

typedef struct ElmtLowongan {
    InfotypeLowongan info;      /* data isi node lowongan             */
    AdrLowongan      next;      /* pointer ke elemen Lowongan berikutnya */
} ElmtLowongan;

typedef struct {
    AdrLowongan First;          /* pointer ke elemen pertama list     */
} ListLowongan;

/* ============================================================
 * BAGIAN 3 — PROTOTYPE SUBPROGRAM
 * ============================================================ */

/* -- J1 --
 * Menginisialisasi list lowongan sebagai list kosong.
 * I.S.: L sembarang.
 * F.S.: L.First = NULL; list siap digunakan. */
void CreateListLowongan(ListLowongan &L);

/* -- J2 --
 * Memeriksa apakah list lowongan kosong.
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan true jika L.First = NULL, false jika tidak.
 *       L tidak berubah. */
bool IsEmptyLowongan(ListLowongan L);

/* -- J3 --
 * Menambahkan lowongan baru di AWAL list (INSERT FIRST).
 * I.S.: L terdefinisi; data berisi informasi lowongan yang valid.
 * F.S.: Node baru dengan info = data ditambahkan di awal L;
 *       next node baru = L.First lama; L.First = node baru. */
void InsertFirstLowongan(ListLowongan &L, InfotypeLowongan data);

/* -- J4 --
 * Menghapus lowongan dari list berdasarkan id_lowongan.
 * I.S.: L tidak kosong; terdapat node dengan id_lowongan == id[];
 *       seluruh relasi pada ListPelamar yang menunjuk ke lowongan
 *       dengan id[] SUDAH dibersihkan terlebih dahulu oleh pengelola
 *       sistem (melalui DeleteRelasiAllPelamar).
 * F.S.: Node dengan id dihapus dari L dan memori dibebaskan;
 *       data lowongan yang dihapus disalin ke out. */
void DeleteLowonganById(ListLowongan &L, char id[], InfotypeLowongan &out);

/* -- J5 --
 * Mencetak seluruh data lowongan di list ke layar.
 * I.S.: L terdefinisi.
 * F.S.: Semua elemen L dicetak secara berurutan dari First;
 *       L tidak berubah. */
void PrintListLowongan(ListLowongan L);

/* -- J6 --
 * Mencari node lowongan berdasarkan id_lowongan (linear search).
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id_lowongan == id[];
 *       mengembalikan NULL jika tidak ditemukan; L tidak berubah. */
AdrLowongan FindLowonganById(ListLowongan L, char id[]);

#endif /* JOBVACANCY_H */
