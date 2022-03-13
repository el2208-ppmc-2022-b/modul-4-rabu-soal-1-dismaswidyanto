/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : -
*Hari dan Tanggal : Rabu, 16 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int nRow;
	int nCol;
	int **matrix;
} Matrix;



int main(void) {


	// Inisialisasi matrix A
	printf("Jumlah baris matrix A: ");
	scanf("%d", ...);
	printf("Jumlah kolom matrix A: ");
	scanf("%d", ...);
	

	// Inisialisasi matrix B
	printf("Jumlah baris matrix B: ");
	scanf("%d", ...);
	printf("Jumlah kolom matrix B: ");
	scanf("%d", ...);
	
	

	//template output
	printf("Hasil perkalian matriks A*B: \n");
	printf("%d ", ...);
	printf("\n");

	printf("Ukuran matriks A dan B tidak sesuai.\n");


	// Bebaskan memory matriks A dan B    
	freeMatrix(A);
	freeMatrix(B);
	
	return 0;
}
