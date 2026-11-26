/* ============================================================
 * FILE        : jobvacancy.cpp
 * MODUL       : ADT List Lowongan Pekerjaan — Implementasi
 * DESKRIPSI   : Implementasi subprogram untuk mengelola
 *               daftar lowongan (Singly Linked List, INSERT FIRST).
 * DIBUAT OLEH : [ESTEDEH]
 *
 * CATATAN IMPLEMENTASI:
 * - Tidak boleh menggunakan break atau return di dalam perulangan.
 * - Tidak boleh menggunakan variabel global.
 * - Gunakan new/delete untuk manajemen memori.
 * ============================================================ */

#include "jobvacancy.h"

/* -- J1 --
 * I.S.: L sembarang.
 * F.S.: L.First = NULL; list siap digunakan. */
void CreateListLowongan(ListLowongan &L) {
    L.First = NULL;
}

/* -- J2 --
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan true jika L.First = NULL. */
bool IsEmptyLowongan(ListLowongan L) {
    return (L.First == NULL);
}

/* -- J3 — INSERT FIRST --
 * I.S.: L terdefinisi; data valid.
 * F.S.: Node baru ditambahkan di AWAL L. */
void InsertFirstLowongan(ListLowongan &L, InfotypeLowongan data) {
    AdrLowongan newNode = new ElmtLowongan;
    newNode->info = data;
    newNode->next = L.First;
    L.First = newNode;
}

/* -- J4 --
 * I.S.: L tidak kosong; ada node dengan id_lowongan == id[];
 *       seluruh relasi yang menunjuk ke lowongan ini SUDAH dibersihkan
 *       terlebih dahulu oleh pengelola sistem (DeleteRelasiAllPelamar).
 * F.S.: Node dihapus; datanya disalin ke out. */
void DeleteLowonganById(ListLowongan &L, char id[], InfotypeLowongan &out) {
    AdrLowongan prev = NULL;
    AdrLowongan curr = L.First;

    while (curr != NULL && strcmp(curr->info.id_lowongan, id) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (curr == L.First) {
            L.First = curr->next;
        } else {
            prev->next = curr->next;
        }
        out = curr->info;
        curr->next = NULL;
        delete curr;
    }
}

/* -- J5 --
 * I.S.: L terdefinisi.
 * F.S.: Semua elemen L dicetak; L tidak berubah. */
void PrintListLowongan(ListLowongan L) {
    if (IsEmptyLowongan(L)) {
        printf("Daftar lowongan kosong.\n");
    } else {
        AdrLowongan curr = L.First;
        while (curr != NULL) {
            printf("ID       : %s\n", curr->info.id_lowongan);
            printf("Posisi   : %s\n", curr->info.judul_posisi);
            printf("Perusahaan: %s\n", curr->info.perusahaan);
            printf("Gaji     : %d\n", curr->info.gaji);
            printf("Kategori : %s\n", curr->info.kategori);
            printf("--------\n");
            curr = curr->next;
        }
    }
}

/* -- J6 --
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id, atau NULL. */
AdrLowongan FindLowonganById(ListLowongan L, char id[]) {
    AdrLowongan curr = L.First;
    AdrLowongan hasil = NULL;

    while (curr != NULL && hasil == NULL) {
        if (strcmp(curr->info.id_lowongan, id) == 0) {
            hasil = curr;
        } else {
            curr = curr->next;
        }
    }

    return hasil;
}
