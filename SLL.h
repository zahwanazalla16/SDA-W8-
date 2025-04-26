#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#define MAX_NAME_LENGTH 50

typedef struct Warga *addressWg;
typedef struct Kota *addressKt;

typedef struct Warga {
    char *nama; 	  // Nama warga
    addressWg next;  // Pointer ke node Warga berikutnya
} Warga;

typedef struct Kota {
    char *Kota;        // Nama kota
    addressWg warga;  // Pointer ke struct Warga di Kota
} Kota;

// Array untuk daftar kota
typedef struct {
    Kota *data;
    int jumlah;
    int batas;
} ArrayKota;

// Modul untuk inisialisasi array kota
void initArrayKota(ArrayKota *arr, int capacity);

// Modul untuk input dan hapus kota
void masukkanKota(ArrayKota *arr, const char *namaKota);
void hapusKota(ArrayKota *arr, const char *namaKota);
boolean cariKota(ArrayKota *arr, const char *namaKota);

// Modul untuk input dan hapus nama warga
void masukkanNama(Kota *kota, const char *warga);
void hapusNama(Kota *kota, const char *warga);

// Modul untuk menampilkan
void tampilanKota(ArrayKota arr);
void tampilanNama(Kota *kota);

// Modul untuk menghapus
void hapusDataNama(Kota *kota);
void HapusDataKota(ArrayKota *arr);

#endif
