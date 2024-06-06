#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

void tampilkanBuku(FILE *file) {
    Buku buku;

    // baca setiap record dari file dan tampilkan
    printf("Kode Buku\tJenis\tHarga Sewa\tStok\n");
    while (fread(&buku, sizeof(buku), 1, file) == 1) {
        printf("%d\t\t%d\t%.2f\t\t%d\n", buku.kode_buku, buku.jenis, buku.harga_sewa, buku.stok);
    }
}

int main() {
    FILE *jenis1File, *jenis2File, *jenis3File;

    // buka file jenis1.dat, jenis2.dat, dan jenis3.dat untuk dibaca
    jenis1File = fopen("jenis1.dat", "rb");
    jenis2File = fopen("jenis2.dat", "rb");
    jenis3File = fopen("jenis3.dat", "rb");

    printf("Isi file jenis1.dat:\n");
    tampilkanBuku(jenis1File);

    printf("\nIsi file jenis2.dat:\n");
    tampilkanBuku(jenis2File);

    printf("\nIsi file jenis3.dat:\n");
    tampilkanBuku(jenis3File);

    fclose(jenis1File);
    fclose(jenis2File);
    fclose(jenis3File);

    return 0;
}
