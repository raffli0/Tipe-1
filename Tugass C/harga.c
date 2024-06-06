#include <stdio.h>

typedef struct {
    int kode_buku;
    int jenis;
    float harga_sewa;
    int stok;
} Buku;

int main() {
    FILE *bukuFile, *hargaDiAtas1000File, *hargaDiBawah1000File;
    Buku buku;

    // buka file buku.dat untuk dibaca
    bukuFile = fopen("buku.dat", "rb");
    if (bukuFile == NULL) {
        printf("Gagal membuka file buku.dat untuk dibaca.\n");
        return 1;
    }

    // buka dua file terpisah untuk harga sewa >= Rp. 1.000 dan harga sewa di < Rp. 1.000 untuk ditulis
    hargaDiAtas1000File = fopen("harga_di_atas_1000.dat", "wb");
    hargaDiBawah1000File = fopen("harga_di_bawah_1000.dat", "wb");

    // baca setiap record dari file buku.dat dan tulis ke file yang sesuai harga
    while (fread(&buku, sizeof(buku), 1, bukuFile) == 1) {
        if (buku.harga_sewa >= 1000) {
            fwrite(&buku, sizeof(buku), 1, hargaDiAtas1000File);
        } else {
            fwrite(&buku, sizeof(buku), 1, hargaDiBawah1000File);
        }
    }

    fclose(bukuFile);
    fclose(hargaDiAtas1000File);
    fclose(hargaDiBawah1000File);

    printf("Pemisahan file berdasarkan harga sewa berhasil.\n");

    return 0;
}
