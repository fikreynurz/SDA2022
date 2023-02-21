/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "SpNRSLL.H"
#include "BodyNRSL.cpp"
#include <stdio.h>
#include <conio.h>

int main()
{
	/* Kamus Lokal */
	int Menu;
	tElmtList Kota[5]; // Kota merupakan variabel array bertipe tElmList dengan jumlah elemen 5
	bool Status1;

	init(&Kota); // Pemanggilan modul init, untuk menginisiasi bahwa nilai kota bernilai nilla
	/* Program */
	while (true)
	{

		DftrMenu();
		scanf("%d", &Menu);

		switch (Menu)
		{

		// Tambah Data{
		case 1:
			printKota(Kota); // Modul untuk menampilkan daftar kota
			menuTbhData();	 // Modul untuk menampilkan menu jika memilih tambah data
			inputMenu(&Menu);
			if (Menu == 1)
			{
				tambahData(1, &Kota); // Modul untuk menambahkan suatu data baik itu kota maupun nama tergantung parameter yang di passing
			}
			else if (Menu == 2)
			{
				tambahData(2, &Kota);
			}
			else if (Menu == 0)
			{
				Status1 = false;
			}
			else
			{
				printf("Inputan tidak valid"); // Handling error
				sleep(1);
			}
			break;
		// Hapus Data;
		case 2:
			Status1 = true;
			while (Status1)
			{
				system("cls");
				printKota(Kota);
				menuHpsData(0); // Modul untuk menampilkan beberapa pilihan atas apa yang akan kita hapus

				inputMenu(&Menu);
				if (Menu == 1)
				{
					hapusData(0, &Kota); // Modul untuk menghaspus data baik kota maupun data sesuai parameter yang di passing
				}
				else if (Menu == 2)
				{
					hapusData(1, &Kota);
				}
				else if (Menu == 0)
				{
					Status1 = false;
				}
				else
				{
					printf("Inputan tidak valid");
					sleep(1);
				}
			}
			break;
		case 3:
			printKota(Kota); // Modul untuk menampilkan daftar kota dan nama penduduknya
			getch();
			break;
		default:
			printf("Inputan Tidak Valid");
			sleep(1);
		}
	}
	return 0;
}