/* ============================================================
 * FILE        : applicant.cpp
 * MODUL       : ADT List Pelamar — Implementasi
 * DESKRIPSI   : Implementasi subprogram untuk mengelola
 *               daftar pelamar (Singly Linked List, INSERT LAST).
 * DIBUAT OLEH : [ESTEDEH]
 *
 * CATATAN IMPLEMENTASI:
 * - Tidak boleh menggunakan break atau return di dalam perulangan.
 * - Tidak boleh menggunakan variabel global.
 * - Gunakan new/delete untuk manajemen memori.
 * ============================================================ */

#include "applicant.h"

/* -- A1 --
 * I.S.: L sembarang.
 * F.S.: L.First = NULL; list siap digunakan. */
void CreateListPelamar(ListPelamar &L) {
    L.First = NULL;
}

/* -- A2 --
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan true jika L.First = NULL. */
bool IsEmptyPelamar(ListPelamar L) {
    return (L.First == NULL);
}

/* -- A3 — INSERT LAST --
 * I.S.: L terdefinisi; data valid.
 * F.S.: Node baru ditambahkan di akhir L. */
void InsertLastPelamar(ListPelamar &L, InfotypePelamar data) {
    AdrPelamar newNode = new ElmtPelamar;
    newNode->info = data;
    newNode->relFirst = NULL;
    newNode->next = NULL;

    if (IsEmptyPelamar(L)) {
        L.First = newNode;
    } else {
        AdrPelamar curr = L.First;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

/* -- A4 --
 * I.S.: L tidak kosong; ada node dengan id_pelamar == id[];
 *       seluruh relasi milik pelamar ini SUDAH dibersihkan
 *       terlebih dahulu melalui DeleteAllRelasi(P).
 * F.S.: Node dihapus; datanya disalin ke out. */
void DeletePelamarById(ListPelamar &L, char id[], InfotypePelamar &out) {
    AdrPelamar prev = NULL;
    AdrPelamar curr = L.First;

    while (curr != NULL && strcmp(curr->info.id_pelamar, id) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->relFirst == NULL) {
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

/* -- A5 --
 * I.S.: L terdefinisi.
 * F.S.: Semua elemen L dicetak; L tidak berubah. */
void PrintListPelamar(ListPelamar L) {
    if (IsEmptyPelamar(L)) {
        printf("Daftar pelamar kosong.\n");
    } else {
        AdrPelamar curr = L.First;
        while (curr != NULL) {
            printf("ID     : %s\n", curr->info.id_pelamar);
            printf("Nama   : %s\n", curr->info.nama);
            printf("Usia   : %d\n", curr->info.usia);
            printf("Pend.  : %s\n", curr->info.pendidikan);
            printf("Ahli   : %s\n", curr->info.keahlian);
            printf("--------\n");
            curr = curr->next;
        }
    }
}

/* -- A6 --
 * I.S.: L terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id, atau NULL. */
AdrPelamar FindPelamarById(ListPelamar L, char id[]) {
    AdrPelamar curr = L.First;
    AdrPelamar hasil = NULL;

    while (curr != NULL && hasil == NULL) {
        if (strcmp(curr->info.id_pelamar, id) == 0) {
            hasil = curr;
        } else {
            curr = curr->next;
        }
    }

    return hasil;
}
