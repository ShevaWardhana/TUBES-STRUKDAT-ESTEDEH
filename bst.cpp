/* ============================================================
 * FILE        : bst.cpp
 * MODUL       : ADT Binary Search Tree (BST) — Implementasi
 * DESKRIPSI   : Implementasi subprogram BST untuk pencarian
 *               data pelamar berdasarkan id_pelamar.
 * DIBUAT OLEH : [ESTEDEH]
 *
 * CATATAN IMPLEMENTASI:
 * - Tidak boleh menggunakan break atau return di dalam perulangan.
 * - Tidak boleh menggunakan variabel global.
 * - Fungsi rekursif (InsertBSTRek, SearchBSTRek, PrintInOrderRek)
 *   boleh menggunakan return untuk hasil rekursi.
 * - Gunakan new/delete untuk manajemen memori.
 * ============================================================ */

#include "bst.h"

/* -- B1 --
 * I.S.: T sembarang.
 * F.S.: T.root = NULL. */
void CreateBST(BSTTree &T) {
    // TODO: Set T.root = NULL
}

/* -- B2 --
 * I.S.: T terdefinisi.
 * F.S.: Mengembalikan true jika T.root = NULL. */
bool IsEmptyBST(BSTTree T) {
    // TODO: Kembalikan (T.root == NULL)
}

/* -- B3 (wrapper) --
 * I.S.: T terdefinisi; data valid; tidak ada duplikat.
 * F.S.: Node baru disisipkan di posisi yang tepat. */
void InsertBST(BSTTree &T, InfotypePelamar data) {
    // TODO: Panggil InsertBSTRek(T.root, data)
}

/* -- B4 (wrapper) --
 * I.S.: T terdefinisi.
 * F.S.: Mengembalikan pointer ke node dengan id, atau NULL. */
AdrBST SearchBST(BSTTree T, char id[]) {
    // TODO: Panggil dan kembalikan SearchBSTRek(T.root, id)
}

/* -- B5 (wrapper) --
 * I.S.: T terdefinisi.
 * F.S.: Jika id[] ditemukan, node dihapus (termasuk bila root) dan
 *       struktur BST tetap valid. Jika tidak ditemukan, T tidak berubah. */
void DeleteBST(BSTTree &T, char id[]) {
    // TODO: Panggil DeleteBSTRek(T.root, id)
    //       Karena DeleteBSTRek menerima T.root secara reference (&P),
    //       perubahan pada root saat root dihapus otomatis memperbarui T.root.
}

/* -- B6 (wrapper) --
 * I.S.: T terdefinisi.
 * F.S.: Semua node dicetak in-order. */
void PrintInOrderBST(BSTTree T) {
    // TODO: Panggil PrintInOrderRek(T.root)
}

/* ============================================================
 * SUBPROGRAM BANTU (HELPER)
 * ============================================================ */

/* -- B7 — Rekursif --
 * I.S.: data valid; tidak ada duplikat.
 * F.S.: Node baru disisipkan pada posisi tepat di subtree P. */
void InsertBSTRek(AdrBST &P, InfotypePelamar data) {
    // TODO: Base case: jika P == NULL
    //       → alokasi node baru, isi info = data, left = right = NULL
    //       → P = node baru
    // TODO: Recursive case:
    //       → jika strcmp(data.id_pelamar, P->info.id_pelamar) < 0
    //          → InsertBSTRek(P->left, data)
    //       → jika strcmp(data.id_pelamar, P->info.id_pelamar) > 0
    //          → InsertBSTRek(P->right, data)
    //       → jika == 0 → duplikat, abaikan
}

/* -- B8 — Rekursif --
 * I.S.: P adalah root subtree yang diperiksa.
 * F.S.: Mengembalikan pointer ke node dengan id, atau NULL. */
AdrBST SearchBSTRek(AdrBST P, char id[]) {
    // TODO: Base case: P == NULL → return NULL (tidak ditemukan)
    // TODO: Jika strcmp(id, P->info.id_pelamar) == 0 → return P
    // TODO: Jika < 0 → return SearchBSTRek(P->left, id)
    // TODO: Jika > 0 → return SearchBSTRek(P->right, id)
    //
    // CATATAN: return di dalam fungsi rekursif diizinkan
    // (larangan hanya untuk return di dalam perulangan)
}

/* -- B9 — Rekursif --
 * I.S.: P adalah root subtree yang akan dicetak.
 * F.S.: Semua node di subtree P dicetak secara in-order. */
void PrintInOrderRek(AdrBST P) {
    // TODO: Base case: P == NULL → langsung return
    // TODO: PrintInOrderRek(P->left)
    // TODO: Cetak P->info (id_pelamar, nama, dll.)
    // TODO: PrintInOrderRek(P->right)
}

/* -- B10 --
 * I.S.: P tidak NULL.
 * F.S.: Mengembalikan pointer ke node paling kiri (nilai terkecil). */
AdrBST FindMinBST(AdrBST P) {
    // TODO: Gunakan pointer bantu curr = P
    // TODO: Traversal ke kiri selama curr != NULL && curr->left != NULL:
    //       geser curr = curr->left
    //       (jangan gunakan break atau return di dalam perulangan)
    // TODO: Setelah perulangan selesai, curr menunjuk tepat ke node paling kiri
    // TODO: Kembalikan curr
}

/* -- B11 — Rekursif --
 * I.S.: P terdefinisi (bisa NULL); id[] adalah key yang dicari.
 * F.S.: Node dengan id_pelamar == id[] dihapus dan memori dibebaskan;
 *       pointer P diperbarui langsung (termasuk jika P adalah T.root). */
void DeleteBSTRek(AdrBST &P, char id[]) {
    // TODO: Base case: jika P == NULL → tidak ditemukan, tidak melakukan apa-apa
    // TODO: Jika strcmp(id, P->info.id_pelamar) < 0
    //       → DeleteBSTRek(P->left, id)
    // TODO: Jika strcmp(id, P->info.id_pelamar) > 0
    //       → DeleteBSTRek(P->right, id)
    // TODO: Jika strcmp(id, P->info.id_pelamar) == 0 (node ketemu, termasuk bila P adalah root):
    //   Kasus 1 - Node adalah daun (P->left == NULL && P->right == NULL):
    //     → AdrBST temp = P;
    //     → P = NULL;
    //     → delete temp;
    //   Kasus 2 - Node punya 1 anak (P->left == NULL atau P->right == NULL):
    //     → AdrBST temp = P;
    //     → P = (P->left != NULL) ? P->left : P->right;
    //     → delete temp;
    //   Kasus 3 - Node punya 2 anak (P->left != NULL && P->right != NULL):
    //     → AdrBST succ = FindMinBST(P->right);
    //     → Salin ID successor ke variabel lokal terlebih dahulu (mis. char succId[10];
    //       strcpy(succId, succ->info.id_pelamar);) sebelum node successor dihapus
    //       agar tidak bergantung pada buffer milik node yang akan dibebaskan
    //     → Salin data successor ke node saat ini: P->info = succ->info;
    //     → Hapus node successor: DeleteBSTRek(P->right, succId);
}
