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

    // buka file buku.dat untuk dibaca
    bukuFile = fopen("buku.dat", "rb");
    if (bukuFile == NULL) {
        printf("Gagal membuka file buku.dat untuk dibaca.\n");
        return 1;
    }

    // buka dua file terpisah untuk jumlah stok >= 10 dan jumlah stok < 10. untuk ditulis
    stokDiAtas10File = fopen("stok_di_atas_10.dat", "wb");
    stokDiBawah10File = fopen("stok_di_bawah_10.dat", "wb");

    // baca setiap record dari file buku.dat dan tulis ke file yang sesuai jumlah stoknya
    while (fread(&buku, sizeof(buku), 1, bukuFile) == 1) {
        if (buku.stok >= 10) {
            fwrite(&buku, sizeof(buku), 1, stokDiAtas10File);
        } else {
            fwrite(&buku, sizeof(buku), 1, stokDiBawah10File);
        }
    }

    fclose(bukuFile);
    fclose(stokDiAtas10File);
    fclose(stokDiBawah10File);

    printf("Pemisahan file berdasarkan jumlah stok berhasil.\n");

    return 0;
}
