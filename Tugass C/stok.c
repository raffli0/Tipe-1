#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

int main() {
    FILE *bukuFile, *stokDiAtas10File, *stokDiBawah10File;
    Buku buku;

    // Buka file buku.dat untuk dibaca
    bukuFile = fopen("buku.dat", "rb");
    if (bukuFile == NULL) {
        printf("Gagal membuka file buku.dat untuk dibaca.\n");
        return 1;
    }

    // Buka dua file terpisah untuk jumlah stok di atas atau sama dengan 10 dan jumlah stok di bawah 10 untuk ditulis
    stokDiAtas10File = fopen("stok_di_atas_10.dat", "wb");
    stokDiBawah10File = fopen("stok_di_bawah_10.dat", "wb");
    if (stokDiAtas10File == NULL || stokDiBawah10File == NULL) {
        printf("Gagal membuka file stok_di_atas_10.dat atau stok_di_bawah_10.dat untuk ditulis.\n");
        fclose(bukuFile);
        return 1;
    }

    // Baca setiap record dari file buku.dat dan tulis ke file yang sesuai berdasarkan jumlah stoknya
    while (fread(&buku, sizeof(buku), 1, bukuFile) == 1) {
        if (buku.stok >= 10) {
            fwrite(&buku, sizeof(buku), 1, stokDiAtas10File);
        } else {
            fwrite(&buku, sizeof(buku), 1, stokDiBawah10File);
        }
    }

    // Tutup semua file
    fclose(bukuFile);
    fclose(stokDiAtas10File);
    fclose(stokDiBawah10File);

    printf("Pemisahan file berdasarkan jumlah stok berhasil.\n");

    return 0;
}
