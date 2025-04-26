#include "SLL.h"

// Modul untuk inisialisasi array kota
void initArrayKota(ArrayKota *arr, int batas) {
    arr->data = (Kota *)malloc(batas * sizeof(Kota));
    arr->jumlah = 0;
    arr->batas = batas;
    
    // Inisialisasi elemen array
    for (int i = 0; i < batas; i++) {
        arr->data[i].Kota = NULL;
        arr->data[i].warga = NULL;
    }
}

// Modul untuk menambahkan kota 
void masukkanKota(ArrayKota *arr, const char *namaKota) {
    // Cek apakah kota sudah ada
    if (cariKota(arr, namaKota)) {
        printf("Kota %s sudah ada dalam daftar!\n", namaKota);
        return;
    }

    // Cek apakah array sudah penuh
    if (arr->jumlah >= arr->batas) {
        // Menambah alokasi array jika penuh
        arr->batas *= 2;
        arr->data = (Kota *)realloc(arr->data, arr->batas * sizeof(Kota));

        // Inisialisasi elemen baru
        for (int i = arr->jumlah; i < arr->batas; i++) {
            arr->data[i].Kota = NULL;
            arr->data[i].warga = NULL;
        }
    }

    int panjangNama = 0;
    while (namaKota[panjangNama] != '\0') {
        panjangNama++;
    }

    arr->data[arr->jumlah].Kota = (char *)malloc((panjangNama + 1) * sizeof(char));
    int j = 0;
    while (namaKota[j] != '\0') {
        arr->data[arr->jumlah].Kota[j] = namaKota[j];
        j++;
    }
    arr->data[arr->jumlah].Kota[j] = '\0';
    arr->data[arr->jumlah].warga = NULL;
    arr->jumlah++;
    printf("Kota %s berhasil ditambahkan!\n", namaKota);
}

// Modul untuk menghapus kota
void hapusKota(ArrayKota *arr, const char *namaKota) {
    int i;
    boolean found = false;
    
    // Mencari kota yang akan dihapus
    for (i = 0; i < arr->jumlah; i++) {
        if (strcmp(arr->data[i].Kota, namaKota) == 0) {
            found = true;
            break;
        }
    }
    
    if (!found) {
        printf("Kota %s tidak ditemukan!\n", namaKota);
        return;
    }
    hapusDataNama(&arr->data[i]); // Hapus semua data warga di kota tersebut
    free(arr->data[i].Kota); // Hapus nama kota
    
	// Menggeser data setelah dihapus
    for (int j = i; j < arr->jumlah - 1; j++) { 
        arr->data[j] = arr->data[j + 1];
    } 
    // Kurangi jumlah data
    arr->jumlah--;
    
    printf("Kota %s berhasil dihapus!\n", namaKota);
}

// isi disini ci

// Modul untuk menghapus semua data nama di kota
void hapusDataNama(Kota *kota) {
    addressWg current = kota->warga;
    addressWg temp;
    
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->nama);
        free(temp);
    }
    
    kota->warga = NULL;
}

// Modul untuk menghapus semua data kota
void HapusDataKota(ArrayKota *arr) {
    for (int i = 0; i < arr->jumlah; i++) {
        hapusDataNama(&arr->data[i]);
        free(arr->data[i].Kota);
    }
    free(arr->data);
    arr->data = NULL;
    arr->jumlah = 0;
    arr->batas = 0;
}
