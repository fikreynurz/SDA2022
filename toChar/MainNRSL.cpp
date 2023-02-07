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
	while (i <= 5)
	{
		InsVFirst (&MyList, a++);
		i++;
	}
	printf ("Hasil InsVFirst 5 x adalah : "); PrintInfo (MyList);

/* Mencari suatu elemen di list */

	P = Search(MyList, 'C');
	printf ("Search yang berhasil (15) : P = %d, Ketemu = %d \n",P,FSearch(MyList,P));
	DelP (&MyList, 'C');

/* Insert di Last */
	printf ("Insert di akhir nilai Z : ");
	InsVLast (&MyList, 'Z');
	PrintInfo (MyList);

/* Insert diantara 2 elemen */
	printf ("Insert sebelum elemen 'B'  : ");
	Prec = SearchPrec (MyList, 'B');
	P = Alokasi ('C');
	if (P != Nil)
	{   InsertAfter (&MyList, P, Prec);	}
	PrintInfo (MyList);

/* Menghapus elemen List */
	printf ("\tHasil Delete dari elemen List :\n");
	DelVFirst (&MyList, &isi);
	printf ("DelVFirst adalah %c\t", isi);

	DelVLast (&MyList, &isi);
	printf ("DelVLast adalah %c\t", isi);

/* Menghapus elemen di tengah-tengah */
	Prec = SearchPrec (MyList, 'C');	/* Node yang akan dihapus */
	if (Prec != Nil)
	{
		 DelAfter (&MyList, &P, Prec);
		 isi = Info(P);
		 DeAlokasi (P);
		 printf ("DelAfter adalah %c\n", isi);
	}
	printf ("Hasil setelah delete : ");
		  PrintInfo (MyList);

	printf ("Insert sebelum elemen A : ");
	Prec = SearchPrec (MyList, 'A');
	P = Alokasi ('Z');
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

