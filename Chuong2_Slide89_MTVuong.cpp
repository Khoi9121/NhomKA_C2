#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 100

void menu() {
	printf("\n---- MENU ----\n");
	printf("1. Nhap ma tran\n");
	printf("2. Tinh tong duong cheo chinh\n");
	printf("3. Tinh tong duong cheo phu\n");
	printf("4. Tinh tong cac phan tu tren duong cheo chinh\n");
	printf("5. Tinh tong cac phan tu tren duong cheo phu\n");
	printf("0. Thoat\n");
	printf("---------------------- \n");
	printf("Chon chuc nang: ");
}

void nhapMaTran(int a[][MAX_SIZE], int *n) {
	printf("Nhap kich thuoc ma tran vuong n: ");
	scanf("%d", n);

	printf("Nhap ma tran:\n");
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatMaTran(int a[][MAX_SIZE], int n) {
	printf("Ma tran:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int tongDuongCheoChinh(int a[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i][i];
	}
	return tong;
}

int tongDuongCheoPhu(int a[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += a[i][n - i - 1];
	}
	return tong;
}

int tongTrenDuongCheoChinh(int a[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}

int tongTrenDuongCheoPhu(int a[][MAX_SIZE], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			tong += a[i][j];
		}
	}
	return tong;
}

int main() {
	int a[MAX_SIZE][MAX_SIZE];
	int n;
	int choice;

	do {
		menu();
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			nhapMaTran(a, &n);
			xuatMaTran(a, n);
			break;
		case 2:
			printf("Tong duong cheo chinh: %d\n", tongDuongCheoChinh(a, n));
			break;
		case 3:
			printf("Tong duong cheo phu: %d\n", tongDuongCheoPhu(a, n));
			break;
		case 4:
			printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongTrenDuongCheoChinh(a, n));
			break;
		case 5:
			printf("Tong cac phan tu tren duong cheo phu: %d\n", tongTrenDuongCheoPhu(a, n));
			break;
		case 0:
			printf("Tam biet!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 0);

	return 0;
}
