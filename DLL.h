#ifndef DLL_H
#define DLL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define MAX_NAME_LENGTH 50

typedef struct NameNode *addressName;
typedef struct KotaNode *addressKota;

// Definisi struct NameNode untuk data warga (double linked list)
typedef struct NameNode {
    char *name;
    addressName next;  // Pointer next untuk warga
    addressName prev;  // Pointer prev untuk warga (tambahan untuk double linked list)
} NameNode;

// Definisi struct KotaNode terpisah
typedef struct KotaNode {
    char *Kota;        // Nama kota
    addressName nama;  // Pointer ke daftar nama di kota ini
} KotaNode;

// Array untuk menyimpan daftar kota
typedef struct {
    KotaNode *data;
    int count;
    int capacity;
} ArrayKota;

// Modul untuk inisialisasi array
void initArrayKota(ArrayKota *arr, int capacity);

// Modul untuk operasi pada kota
void masukkanKota(ArrayKota *arr, const char *namaKota);
void hapusKota(ArrayKota *arr, const char *namaKota);
boolean cariKota(ArrayKota *arr, const char *namaKota);

// Modul untuk operasi pada nama/warga
void masukkanNama(KotaNode *kota, const char *nama);
void hapusNama(KotaNode *kota, const char *nama);

// Modul untuk menampilkan data
void tampilanKota(ArrayKota arr);
void tampilanNama(KotaNode *kota);

// Modul untuk menghapus semua data
void hapusDataNama(KotaNode *kota);
void HapusDataKota(ArrayKota *arr);
#endif
