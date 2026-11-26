/* ============================================================
 * FILE        : application.h
 * MODUL       : ADT Multi Linked-List (MLL-01) — Relasi Lamaran
 * DESKRIPSI   : Deklarasi tipe data dan prototype subprogram
 *               untuk mengelola relasi many-to-many antara
 *               Pelamar dan Lowongan Pekerjaan.
 * MODEL MLL   : MLL-01 — List relasi sebagai bagian dari
 *               elemen list parent (ElmtPelamar.relFirst).
 * STRATEGI    : INSERT FIRST pada list relasi
 * DIBUAT OLEH : [ESTEDEH]
 * ============================================================ */

#ifndef APPLICATION_H
#define APPLICATION_H

#include <stdio.h>
#include <string.h>
#include "applicant.h"
#include "jobvacancy.h"

/* ============================================================
 * BAGIAN 1 — DEFINISI PENUH ELMT RELASI
 * (Forward declaration ada di applicant.h;
 *  definisi lengkap struct ada di sini)
 *
 * CATATAN PENTING:
 * - AdrRelasi sudah di-typedef di applicant.h
 * - Di sini hanya mendefinisikan isi struct-nya
 * ============================================================ */
struct ElmtRelasi {
    AdrLowongan ptrLowongan;    /* pointer langsung ke node Lowongan  */
    AdrRelasi   next;           /* pointer ke ElmtRelasi berikutnya   */
};
/* PERINGATAN: ptrLowongan adalah pointer ke node asli di ListLowongan,
 * BUKAN salinan data. Sebelum DeleteLowonganById dipanggil oleh
 * pengelola sistem, relasi yang menunjuk ke lowongan terkait harus
 * dibersihkan terlebih dahulu melalui DeleteRelasiAllPelamar. */

/* ============================================================
 * BAGIAN 2 — PROTOTYPE SUBPROGRAM
 * ============================================================ */

/* -- M1 --
 * Menginisialisasi list relasi milik sebuah node pelamar.
 * I.S.: P tidak NULL (node pelamar sudah dialokasi).
 * F.S.: P->relFirst = NULL; pelamar P belum memiliki lamaran. */
void CreateRelasi(AdrPelamar P);

/* -- M2 --
 * Menambahkan relasi lamaran baru di AWAL list relasi pelamar P
 * (INSERT FIRST). Pelamar P melamar ke lowongan yang ditunjuk ptrLow.
 * I.S.: P tidak NULL; ptrLow tidak NULL dan menunjuk ke node
 *       Lowongan yang valid; P belum melamar ke lowongan tersebut.
 * F.S.: ElmtRelasi baru dengan ptrLowongan = ptrLow ditambahkan
 *       di awal list relasi P; P->relFirst diperbarui. */
void InsertRelasi(AdrPelamar P, AdrLowongan ptrLow);

/* -- M3 --
 * Menghapus relasi lamaran pelamar P ke lowongan dengan id tertentu.
 * I.S.: P tidak NULL; id_lowongan[] valid.
 * F.S.: Jika terdapat ElmtRelasi di relasi P yang ptrLowongan-nya
 *       menunjuk ke node dengan id_lowongan == id[], elemen tersebut
 *       dihapus dari list relasi P dan memorinya dibebaskan;
 *       jika tidak ditemukan, list relasi P tidak berubah. */
void DeleteRelasi(AdrPelamar P, char id_lowongan[]);

/* -- M4 --
 * Mencetak semua lowongan yang telah dilamar oleh pelamar P.
 * I.S.: P tidak NULL.
 * F.S.: Semua data lowongan yang ada di list relasi P dicetak;
 *       list relasi P tidak berubah. */
void PrintLamaranPelamar(AdrPelamar P);

/* -- M5 --
 * Mencetak semua pelamar yang melamar ke lowongan dengan id tertentu.
 * (Traversal seluruh ListPelamar dan list relasinya)
 * I.S.: LP terdefinisi; id_lowongan[] valid.
 * F.S.: Setiap pelamar yang relasinya menunjuk ke lowongan dengan
 *       id_lowongan == id[] dicetak maksimal satu kali (tidak berulang);
 *       LP tidak berubah. */
void PrintPelamarLowongan(ListPelamar LP, char id_lowongan[]);

/* -- M6 --
 * Memeriksa apakah pelamar P sudah pernah melamar ke lowongan id[].
 * I.S.: P tidak NULL.
 * F.S.: Mengembalikan true jika ada ElmtRelasi di P dengan
 *       ptrLowongan->info.id_lowongan == id[]; P tidak berubah. */
bool IsAlreadyApplied(AdrPelamar P, char id_lowongan[]);

/* -- M7 --
 * Menghapus semua relasi lamaran yang menunjuk ke lowongan dengan
 * id tertentu dari SEMUA pelamar. Dipanggil sebelum menghapus
 * sebuah lowongan dari ListLowongan.
 * I.S.: LP terdefinisi; id_lowongan[] valid.
 * F.S.: Semua ElmtRelasi di seluruh pelamar yang ptrLowongan-nya
 *       menunjuk ke lowongan tersebut dihapus; memori dibebaskan. */
void DeleteRelasiAllPelamar(ListPelamar &LP, char id_lowongan[]);

/* -- M8 --
 * Menghapus seluruh list relasi milik pelamar P.
 * Dipanggil sebelum menghapus node pelamar dari ListPelamar.
 * I.S.: P tidak NULL.
 * F.S.: Semua ElmtRelasi di P->relFirst dihapus; memori dibebaskan;
 *       P->relFirst = NULL. */
void DeleteAllRelasi(AdrPelamar P);

#endif /* APPLICATION_H */
