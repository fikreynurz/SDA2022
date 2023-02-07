/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */

#include "BodyNRSL.cpp"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList, List2, List3;
		int i;
		infotype isi;
		address P, Prec;
	/* Program */
	CreateList (&MyList);
/* Menambah List di awal */
	i = 1;
	int a = 65;
	// while (i <= 5)
	// {
	// 	InsVFirst (&MyList, "A");
	// 	i++;
	// }
	InsVFirst(&MyList, "lima");
	InsVFirst(&MyList, "empat");
	InsVFirst(&MyList, "tiga");
	InsVFirst(&MyList, "dua");
	InsVFirst(&MyList, "satu");
	printf ("Hasil InsVFirst 5 x adalah : "); PrintInfo (MyList);

/* Mencari suatu elemen di list */

	P = Search(MyList, "tiga");
	printf ("Search yang berhasil tiga : P = %d, Ketemu = %d \n",P,FSearch(MyList,P));
	// DelP (&MyList, "dua");

/* Insert di Last */
	printf ("Insert di akhir nilai enam : ");
	InsVLast (&MyList, "enam");
	PrintInfo (MyList);

/* Insert diantara 2 elemen */
	printf ("Insert sebelum elemen empat  : ");
	Prec = SearchPrec (MyList, "empat");
	P = Alokasi ("three");
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Menghapus elemen List */
	printf ("\tHasil Delete dari elemen List :\n");
	DelVFirst (&MyList, &isi);
	printf ("DelVFirst adalah %s\t", isi);

	DelVLast (&MyList, &isi);
	printf ("DelVLast adalah %s\t", isi);

/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec (MyList, "empat");	/* Node yang akan dihapus */
	if (Prec != Nil)
	{
		 DelAfter (&MyList, &P, Prec);
		 isi = Info(P);
		 DeAlokasi (P);
		 printf ("DelAfter adalah %s\n", isi);
	}
	printf ("Hasil setelah delete : ");
		  PrintInfo (MyList);

	printf ("Insert sebelum elemen tiga : ");
	Prec = SearchPrec (MyList, "tiga");
	P = Alokasi ("nol");
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Finishing */
	P = First(MyList);
	DeAlokasi (P);
	P = First(List2);
	DeAlokasi (P);
	P = First(List3);
	DeAlokasi (P);
	return 0;
}

