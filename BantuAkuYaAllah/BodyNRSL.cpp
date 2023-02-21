/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include <unistd.h>
#include <conio.h>
#include <stdlib.h>
// #include "SpNRSLL.H"


void DftrMenu(){
    printf("====================\n");
    printf("|Menu              |\n");
    printf("====================\n");
    printf("|1. Entry Data     |\n");
    printf("|2. Hapus Kota     |\n");
    printf("|3. Tampilkan Data |\n");
    printf("====================\n");
    printf("Masukkan Pilihan: ");
}

void init(tElmtList (*data)[5]) {
    for(int i = 0; i < 5; i++) {
        (*data)[i].info = Nil;
    }
}

bool isEmptyKota(tElmtList data[5])
{
    if(data[0].info == Nil ) {
        return true;
    } else return false;
}


int banyakkota(tElmtList data[5]) {
    int i = 0;
    while(data[i].info != Nil) {
        i++;
    }
    if(i > 5){
        return 5;
    }
    return i;
}

int banyakWarga(tElmtList data) {
    int banyakData = 0;
    if(data.next == Nil) {
        return 0;
    }
    address temp = data.next;
    while(temp != Nil  ) {
        banyakData++;
        temp = temp->next;
    }
    return banyakData;
}

void printNama(tElmtList data) {
    address tempP = data.next;
    while(tempP != Nil) {
        printf(" %s, ", tempP->info);
        tempP = tempP->next;
    }
}

void printKota(tElmtList data[5]) {
    int totalWarga = 0,i = 0;
    if(isEmptyKota(data)) {
        printf("=====================\n");
        printf("|Daftar Kota Kosong!|\n");
        printf("=====================\n");
        getch();
        system("cls");
    } else {
        printf("\nDaftar kota saat ini ada %d\n", banyakkota(data));
        while( data[i].info != Nil && i < 5){
            printf("%d. %-20s [%d]: ", i+1, data[i].info, banyakWarga(data[i]));
            printNama(data[i]);
            printf("\n");
            i++;
        }
        printf("################################\n");
        for(int j = 0; j < i; j++) {
            totalWarga += banyakWarga(data[j]);
        }
        printf("Total seluruh warga saat ini : %d\n", totalWarga);
        printf("################################\n");
    }
}

void menuTbhData() {
    printf("Data manakah yang akan anda tambahkan: \n");
    printf("1. Tambahkan kota\n");
    printf("2. Tambahkan nama\n");
    printf("0. Kembali\n");
}

void menuHpsData(int flaghHpsData) {
    if (flaghHpsData == 0)
    {
        printf("\nData mana yang akan anda hapus: \n");
        printf("1. Hapus kota\n");
        printf("2. Hapus nama \n");
        printf("0. Kembali\n");
    } else if (flaghHpsData == 1) {
        printf("\nPilih  yang akan dihapus\n");
        printf("1. Hapus awal\n");
        printf("2. Hapus akhir\n");
        printf("3. Hapus berdasarkan pencarian\n");
        printf("0. Kembali\n");
    }
}

void hapusKota(tElmtList data[5]) {
    address first, last;
    int index;
    bool Avail=false;

    //pilih kota
    do{
        printf("Pilih nomor kota : ");
        scanf("%d", &index);
        index = index - 1;
        if(index >= 0 && index <= 4 && data[index].info != Nil) {
            Avail=true;
        }else printf("\nInputan salah\n");
    }while(Avail == false);

    //hapus kota
    first = &data[index];
    
    if (first->next != Nil)
    {
        last = isiLast(data[index]);
        while (first->next!=Nil){
            address P = first;
            while(P->next != last){
                P = P->next;
            }
            sambungList(&last,P);
            free(P->next);
            P->next = Nil;
        }

    }
    //hapus nama kota
    data[index].info = Nil;
    for (int i = 0; i < 4; i++) {
        if(data[i].info==Nil && data[i+1].info!=Nil) {
            data[i].info=data[i+1].info;
            data[i].next=data[i+1].next;
            data[i+1].info=Nil;
            data[i+1].next=Nil;
        }
    }
}

void hapusFirst(address *First) {
    if((*First)->next == Nil) {
        free((*First));
        (*First) = Nil;
    } else {
        address temp = (*First);
        (*First) = (*First)->next;
        free(temp);
        temp = Nil;
    }
    printf("Penghapusan node First sukses");
    sleep(1);
}

address isiLast(tElmtList First) {
    address tempP = &First;
    while(tempP->next != Nil) {
        tempP = tempP->next;
    }
    return tempP;
}

address lst(address First) {
    while(First->next != Nil){
        First = First->next;
    }
    return First;
}

void hapusLast(address *First) {
    address Last = lst((*First));
    if((*First) == (Last)) {
        free((*First));
    } else {
        address P = (*First);
        while(P->next != (Last)){
            P = P->next;
        }
        sambungList(&(Last),P);
        free(P->next);
        P->next = Nil;
    }
    printf("Penghapusan item berhasil");
    sleep(1);
}

void hapusData (int flagHps, tElmtList (*data)[5]){
    int menu, index;
    bool Avail;

    if (flagHps == 0 )
    {
        // hapus kota
        hapusKota((*data));
    } else if (flagHps == 1)
    {
        // hapus nama
        menuHpsData(1);
        inputMenu(&menu);
        do{
            printf("Pilih nomor kota : ");
            scanf("%d", &index);
            index = index - 1;
            if(index >= 0 && index <= 4 && (*data)[index].info != Nil) {
                Avail=true;
            }else printf("\nInputan salah\n");
        }while(Avail == false);
        if (menu == 1){     // Hapus node awal
            hapusFirst(&(*data)[index].next);
        } else if (menu == 2)   // Hapus node akhir
        {
            hapusLast(&(*data)[index].next);
            // printf("Fitur belum ada");   
            // sleep(1.5);
        } else if (menu == 3)   // Hapus berdasarkan search
        {
            printf("Fitur belum ada");   
            sleep(1.5);
        }
    }
}

int kotaLast(tElmtList data[5]) {
    int i = 0;
    while(data[i].info != Nil ) {
        i++;
    }
    return i;
}

void inputMenu(int *menu) {
    printf("Silahkan masukan pilihan anda : ");
    scanf("%d", &(*menu));
}

void tambahData(int flagData, tElmtList (*data)[5]) {
    if (flagData == 1){
        tambahKotaLast(&(*data));
    } else if (flagData == 2){
        tambahNamaLast(&(*data));
    }
}

void tambahKotaLast(tElmtList (*data)[5]) {
    int infoLast = kotaLast((*data));
    if(!isFullKota((*data))) {
        alokString(&(*data)[infoLast].info);
        printf("Masukan nama kota : ");
        scanf(" %[^\n]", (*data)[infoLast].info);
        (*data)[infoLast].next = Nil;
    } else if(isFullKota((*data))) {
        printf("Kota sudah penuh\n");
        sleep(1);
    }
}

void tambahNamaLast(tElmtList (*data)[5]) {
    address P, tempP;
    int index;
    bool notValid = false;
    infotype tempNama;
    while(!notValid) {
        printf("Pilih nomor kota : ");
        scanf("%d", &index);
        index-=1;
        if((index >= 0 && index < 5) && (*data)[index].info != Nil ) {
            alokString(&tempNama);
            printf("Masukan nama penduduk %s : ", (*data)[index].info);
            scanf(" %[^\n]", tempNama);
            createList(&P);
            P = alokasi(tempNama);
            tempP = &(*data)[index];
            while(tempP->next != Nil) {
                tempP = tempP->next;
            }
            sambungList(&tempP->next, P);
            notValid = true;
        } else {
            printf("Nomor kota tidak ada\n");
            notValid = true;
            sleep(1);
        }
    }
}



bool isFullKota(tElmtList data[5]){
    if (data[5-1].info != Nil) {
        return true;
    } else {
        return false;
    }
}

void alokString(infotype *value) {
   *value = (char*) malloc(20 * sizeof(char));
}

void createList(address *P) {
    (*P) = Nil;
}

address alokasi (infotype X) {
	/* Kamus Lokal */
	address P;
	/* Algoritma */
	P = (address) malloc (sizeof (tElmtList));
	if (P != Nil)		/* Alokasi berhasil */
	{
        alokString(&P->info);
        P->info = X;
        P->next = Nil;
	}
	return (P);
}

void sambungList(address *Q, address P) {
    (*Q) = P;
}