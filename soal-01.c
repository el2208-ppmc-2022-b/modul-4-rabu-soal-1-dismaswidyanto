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



/**
 * @brief mencetak matriks A
 * 
 * @param A 
 * @return int 
 */
int printMatrix(Matrix A) {
	int i, j;
	for (i = 0; i < A.nRow; i ++) {
		for (j = 0; j < A.nCol; j ++) {
			printf("%d ", A.matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/**
 * @brief membebaskan memori di matriks A
 * 
 * @param A struct Matrix
 * @return int 
 */
int freeMatrix(Matrix A) {
	int i, j;
	for (i = 0; i < A.nRow; i ++) {
		free(A.matrix[i]);
	}
	free(A.matrix);
	// printf("Success\n");
	return 0;
}

int multiplyMatrix(Matrix A, Matrix B, Matrix C) {
	int i, j, k;
	// Perkalian matrix A*B = C
		for (i = 0; i < C.nRow; i ++) {
			for (j = 0; j < C.nCol; j ++) {
				for (k = 0; k < A.nCol; k ++) {
					C.matrix[i][j] += A.matrix[i][k]*B.matrix[k][j];
				}
			}
		}
	return 0;
}

int main(void) {
	Matrix A, B, C;
	int i, j, k;

	// Inisialisasi matrix A
	printf("Jumlah baris matrix A: "); scanf("%d", &(A.nRow));
	printf("Jumlah kolom matrix A: "); scanf("%d", &(A.nCol));
	A.matrix =  malloc(sizeof(int*)*A.nRow);
	for (i = 0; i < A.nRow; i ++) {
		A.matrix[i] = malloc(sizeof(int*)*A.nCol);
		for (j = 0; j < A.nCol; j ++) {
			A.matrix[i][j] = i*A.nCol + j;
		}
	}

	// Inisialisasi matrix B
	printf("Jumlah baris matrix B: "); scanf("%d", &(B.nRow));
	printf("Jumlah kolom matrix B: "); scanf("%d", &(B.nCol));
	B.matrix =  malloc(sizeof(int*)*B.nRow);
	for (i = 0; i < B.nRow; i ++) {
		B.matrix[i] = malloc(sizeof(int*)*B.nCol);
		for (j = 0; j < B.nCol; j ++) {
			B.matrix[i][j] = i*B.nCol + j;
		}
	}
	
	// Syarat validnya perkalian matrix
	if (A.nCol == B.nRow) {
		// Inisialisasi matrix C
		C.nRow = A.nRow;
		C.nCol = B.nCol;
		C.matrix = malloc(sizeof(int*)*C.nRow);
		for (i = 0; i < C.nRow; i ++) {
			C.matrix[i] = malloc(sizeof(int*)*C.nCol);
			for (j = 0; j < C.nCol; j ++) {
				C.matrix[i][j] = 0;
			}
		}
		// Perkalian matrix A*B = C
		multiplyMatrix(A, B, C);
		printf("Hasil perkalian matriks A*B: \n");
		printMatrix(C);
		freeMatrix(C);
	}
	else {
		printf("Ukuran matriks A dan B tidak sesuai.\n");
	}

	// Bebaskan memory matriks A dan B    
	freeMatrix(A);
	freeMatrix(B);
	
	return 0;
}
