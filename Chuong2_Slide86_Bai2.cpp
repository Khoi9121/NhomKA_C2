#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define MAXROW 100
#define MAXCOL 100

void sapXepCotChanLe(int a[][MAXCOL], int m, int n) {
	// Sắp xếp từng cột
	for (int j = 0; j < n; j++) {
		// Sắp xếp cột chẵn tăng dần
		if (j % 2 == 0) {
			for (int i = 0; i < m - 1; i++) {
				for (int k = i + 1; k < m; k++) {
					if (a[i][j] > a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
			}
		}
		// Sắp xếp cột lẻ giảm dần
		else {
			for (int i = 0; i < m - 1; i++) {
				for (int k = i + 1; k < m; k++) {
					if (a[i][j] < a[k][j]) {
						int temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
				}
			}
		}
	}
}


void nhapMaTran(int a[][MAXCOL], int *m, int *n) {
	printf("Nhap so hang: ");
	scanf("%d", m);
	printf("Nhap so cot: ");
	scanf("%d", n);
	for (int i = 0; i < *m; i++)
		for (int j = 0; j < *n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void xuatMaTran(int a[][MAXCOL], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int main() {
	int a[MAXROW][MAXCOL];
	int m, n;

	nhapMaTran(a, &m, &n);
	xuatMaTran(a, m, n);

	//// Sắp xếp các cột chẵn tăng dần, cột lẻ giảm dần
	//sapXepCotChanLe(a, m, n);

	//// Xuất ma trận sau khi sắp xếp
	//printf("Ma tran sau khi sap xep:\n");
	//xuatMaTran(a, m, n);

	return 0;

}