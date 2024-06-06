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
    FILE *hargaDiAtas1000File, *hargaDiBawah1000File;

    // buka file harga_di_atas_1000.dat dan harga_di_bawah_1000.dat untuk dibaca
    hargaDiAtas1000File = fopen("harga_di_atas_1000.dat", "rb");
    hargaDiBawah1000File = fopen("harga_di_bawah_1000.dat", "rb");

    // tampilkan isi file harga_di_atas_1000.dat
    printf("Isi file harga_di_atas_1000.dat:\n");
    tampilkanBuku(hargaDiAtas1000File);

    // tampilkan isi file harga_di_bawah_1000.dat
    printf("\nIsi file harga_di_bawah_1000.dat:\n");
    tampilkanBuku(hargaDiBawah1000File);

    fclose(hargaDiAtas1000File);
    fclose(hargaDiBawah1000File);

    return 0;
}
