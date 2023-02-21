/* File        : spNRSLL.h */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

// #ifndef spnrsll_H
#define spnrsll_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

typedef char * infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
	 infotype info;
	 address First;
	 address  next;
	 } ElmtList;


void DftrMenu();

// Alokasi memori
address alokasi(infotype X);
void alokString(infotype *value);
void init(tElmtList (*dapen)[5]);
void isiNode(address *P, infotype value);
void sambungList(address *Q, address P);
void createList(address *P);

// Modul Cek
bool isFullKota(tElmtList dapen[5]);
bool isEmptyKota(tElmtList dapen[5]);
address isiLast(tElmtList First);
address lst(address First);
int banyakWarga(tElmtList dapen);
int banyakkota(tElmtList dapen[5]);

// Modul Menu
void listMenu();
void menuTbhtElmtList();
void menuHpstElmtList(int flagHpstElmtList);
void menuTampilkantElmtList();

void inputMenu(int *menu);
void hapusData(int flagHps, tElmtList (*dapen)[5]);


// modul tampilkan tElmtList
void printKota(tElmtList dapen[5]);
void printNama(tElmtList dapen);

// Modul Tambah tElmtList
void tambahtElmtList(int flagtElmtList, tElmtList (*dapen)[5]);
void tambahKotaLast(tElmtList (*dapen)[5]);
void tambahNamaLast(tElmtList (*dapen)[5]);


// Modul Hapus tElmtList
void hapustElmtList (int flagHps, tElmtList (*dapen)[5]);
void hapusLast(address *First);
void hapusKota(tElmtList dapen[5]);
void hapusFirst(address *First);