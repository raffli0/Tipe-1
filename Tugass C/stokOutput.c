#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

void tampilkanBuku(FILE *file) {
    Buku buku;

    // Baca setiap record dari file dan tampilkan
    printf("Kode Buku\tJenis\tHarga Sewa\tStok\n");
    while (fread(&buku, sizeof(buku), 1, file) == 1) {
        printf("%d\t\t%d\t%.2f\t\t%d\n", buku.kode_buku, buku.jenis, buku.harga_sewa, buku.stok);
    }
}

int main() {
    FILE *stokDiAtas10File, *stokDiBawah10File;

    // Buka file stok_di_atas_10.dat dan stok_di_bawah_10.dat untuk dibaca
    stokDiAtas10File = fopen("stok_di_atas_10.dat", "rb");
    stokDiBawah10File = fopen("stok_di_bawah_10.dat", "rb");
    if (stokDiAtas10File == NULL || stokDiBawah10File == NULL) {
        printf("Gagal membuka file stok_di_atas_10.dat atau stok_di_bawah_10.dat untuk dibaca.\n");
        return 1;
    }

    // Tampilkan isi file stok_di_atas_10.dat
    printf("Isi file stok_di_atas_10.dat:\n");
    tampilkanBuku(stokDiAtas10File);

    // Tampilkan isi file stok_di_bawah_10.dat
    printf("\nIsi file stok_di_bawah_10.dat:\n");
    tampilkanBuku(stokDiBawah10File);

    // Tutup semua file
    fclose(stokDiAtas10File);
    fclose(stokDiBawah10File);

    return 0;
}
