#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

int main() {
    FILE *bukuFile;
    Buku buku;

    // Buka file buku.dat untuk ditulis
    bukuFile = fopen("buku.dat", "wb");
    if (bukuFile == NULL) {
        printf("Gagal membuka file buku.dat untuk ditulis.\n");
        return 1;
    }

    // Tulis data buku ke dalam file
    buku.kode_buku = 1021;
    buku.jenis = 1;
    buku.harga_sewa = 2500;
    buku.stok = 15;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 1022;
    buku.jenis = 1;
    buku.harga_sewa = 2300;
    buku.stok = 3;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 1024;
    buku.jenis = 1;
    buku.harga_sewa = 2700;
    buku.stok = 20;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 2023;
    buku.jenis = 2;
    buku.harga_sewa = 4900;
    buku.stok = 1;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 2025;
    buku.jenis = 2;
    buku.harga_sewa = 4700;
    buku.stok = 10;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 2026;
    buku.jenis = 2;
    buku.harga_sewa = 4500;
    buku.stok = 4;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 3021;
    buku.jenis = 3;
    buku.harga_sewa = 500;
    buku.stok = 20;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 3025;
    buku.jenis = 3;
    buku.harga_sewa = 400;
    buku.stok = 30;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    buku.kode_buku = 3027;
    buku.jenis = 3;
    buku.harga_sewa = 900;
    buku.stok = 25;
    fwrite(&buku, sizeof(buku), 1, bukuFile);

    // Tutup file
    fclose(bukuFile);

    printf("Data buku telah ditulis ke dalam file buku.dat.\n");

    return 0;
}
