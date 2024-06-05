#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

int main() {
    FILE *bukuFile, *jenis1File, *jenis2File, *jenis3File;
    Buku buku;

    // Buka file buku.dat untuk dibaca
    bukuFile = fopen("buku.dat", "rb");
    if (bukuFile == NULL) {
        printf("Gagal membuka file buku.dat untuk dibaca.\n");
        return 1;
    }

    // Buka tiga file terpisah untuk jenis buku 1, 2, dan 3 untuk ditulis
    jenis1File = fopen("jenis1.dat", "wb");
    jenis2File = fopen("jenis2.dat", "wb");
    jenis3File = fopen("jenis3.dat", "wb");
    if (jenis1File == NULL || jenis2File == NULL || jenis3File == NULL) {
        printf("Gagal membuka file jenis1.dat, jenis2.dat, atau jenis3.dat untuk ditulis.\n");
        fclose(bukuFile);
        return 1;
    }

    // Baca setiap record dari file buku.dat dan tulis ke file yang sesuai berdasarkan jenis buku
    while (fread(&buku, sizeof(buku), 1, bukuFile) == 1) {
        if (buku.jenis == 1) {
            fwrite(&buku, sizeof(buku), 1, jenis1File);
        } else if (buku.jenis == 2) {
            fwrite(&buku, sizeof(buku), 1, jenis2File);
        } else if (buku.jenis == 3) {
            fwrite(&buku, sizeof(buku), 1, jenis3File);
        }
    }

    // Tutup semua file
    fclose(bukuFile);
    fclose(jenis1File);
    fclose(jenis2File);
    fclose(jenis3File);

    printf("Pemisahan file berdasarkan jenis buku berhasil.\n");

    return 0;
}
