/* ============================================================
 * FILE        : bst.h
 * MODUL       : ADT Binary Search Tree (BST) Pelamar
 * DESKRIPSI   : Deklarasi tipe data dan prototype subprogram
 *               untuk pencarian data pelamar secara efisien
 *               menggunakan Binary Search Tree.
 * KUNCI BST   : id_pelamar (perbandingan leksikografis)
 * DIBUAT OLEH : [ESTEDEH]
 * ============================================================ */

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <string.h>
#include "applicant.h"

/* ============================================================
 * BAGIAN 1 — DEKLARASI NODE & TREE BST
 * ============================================================ */
typedef struct NodeBST *AdrBST;

typedef struct NodeBST {
    InfotypePelamar info;   /* salinan data pelamar (key = id_pelamar) */
    AdrBST          left;   /* child kiri  — id lebih kecil (strcmp < 0) */
    AdrBST          right;  /* child kanan — id lebih besar (strcmp > 0) */
} NodeBST;

typedef struct {
    AdrBST root;            /* pointer ke root BST */
} BSTTree;

/* ============================================================
 * BAGIAN 2 — PROTOTYPE SUBPROGRAM
 * ============================================================ */

/* -- B1 --
 * Menginisialisasi BST sebagai tree kosong.
 * I.S.: T sembarang.
 * F.S.: T.root = NULL; tree siap digunakan. */
void CreateBST(BSTTree &T);

/* -- B2 --
 * Memeriksa apakah BST kosong.
 * I.S.: T terdefinisi.
 * F.S.: Mengembalikan true jika T.root = NULL; T tidak berubah. */
bool IsEmptyBST(BSTTree T);

/* -- B3 --
 * Menyisipkan data pelamar ke dalam BST.
 * I.S.: T terdefinisi; data berisi informasi pelamar yang valid;
 *       tidak ada duplikat id_pelamar di T.
 * F.S.: Node baru disisipkan pada posisi yang tepat sesuai
 *       perbandingan id_pelamar (strcmp); struktur BST tetap valid. */
void InsertBST(BSTTree &T, InfotypePelamar data);

/* -- B4 --
 * Mencari node BST berdasarkan id_pelamar.
 * I.S.: T terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id_pelamar == id[];
 *       mengembalikan NULL jika tidak ditemukan; T tidak berubah. */
AdrBST SearchBST(BSTTree T, char id[]);

/* -- B5 --
 * Menghapus node BST berdasarkan id_pelamar.
 * I.S.: T terdefinisi (dapat kosong atau berisi data).
 * F.S.: Jika id[] ditemukan, node dihapus dan memori dibebaskan;
 *       struktur BST tetap valid untuk 3 kasus (daun, 1 anak, 2 anak),
 *       termasuk pembaruan T.root jika node yang dihapus adalah root.
 *       Jika T kosong atau id[] tidak ditemukan, T tidak berubah. */
void DeleteBST(BSTTree &T, char id[]);

/* -- B6 --
 * Mencetak semua node BST secara in-order (urutan id_pelamar naik).
 * I.S.: T terdefinisi.
 * F.S.: Semua node dicetak dalam urutan id_pelamar ascending;
 *       T tidak berubah. */
void PrintInOrderBST(BSTTree T);

/* ============================================================
 * BAGIAN 3 — SUBPROGRAM BANTU (HELPER) — INTERNAL
 * Dipanggil oleh subprogram utama di atas, tidak langsung
 * dipanggil dari main.
 * ============================================================ */

/* -- B7 (helper) --
 * Menyisipkan data secara rekursif ke subtree dengan root P.
 * I.S.: data valid; tidak ada duplikat.
 * F.S.: Node baru disisipkan pada posisi yang tepat di subtree P. */
void InsertBSTRek(AdrBST &P, InfotypePelamar data);

/* -- B8 (helper) --
 * Mencari node secara rekursif di subtree dengan root P.
 * I.S.: P adalah root subtree yang diperiksa.
 * F.S.: Mengembalikan pointer ke node dengan id, atau NULL. */
AdrBST SearchBSTRek(AdrBST P, char id[]);

/* -- B9 (helper) --
 * Mencetak in-order secara rekursif mulai dari subtree root P.
 * I.S.: P adalah root subtree yang akan dicetak.
 * F.S.: Semua node di subtree P dicetak secara in-order. */
void PrintInOrderRek(AdrBST P);

/* -- B10 (helper) --
 * Mencari node dengan nilai terkecil di subtree (paling kiri).
 * Digunakan saat menghapus node dengan 2 anak (successor).
 * I.S.: P tidak NULL.
 * F.S.: Mengembalikan pointer ke node paling kiri di subtree P;
 *       struktur subtree P tidak berubah. */
AdrBST FindMinBST(AdrBST P);

/* -- B11 (helper) --
 * Menghapus node dengan id_pelamar == id[] secara rekursif pada
 * subtree berakar di P. Parameter reference AdrBST &P memungkinkan
 * pembaruan pointer subtree (termasuk T.root) secara langsung.
 * I.S.: P terdefinisi (bisa NULL); id[] adalah key yang dicari.
 * F.S.: Jika ditemukan, node dihapus dan memori dibebaskan untuk
 *       3 kasus (daun, 1 anak, 2 anak dengan in-order successor)
 *       serta pointer P diperbarui. Jika P == NULL, tidak berubah. */
void DeleteBSTRek(AdrBST &P, char id[]);

#endif /* BST_H */
