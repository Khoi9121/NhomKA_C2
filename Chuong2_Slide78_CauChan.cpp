#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define MAXROW 100
#define MAXCOL 100

// Hàm kiểm tra số hoàn thiện
int laSoHoanThien(int n) {
	if (n <= 0) return 0;
	int sum = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0) sum += i;
	return sum == n;
}

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
	if (n <= 1) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

//// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
//int tongPhanTuChuSoDauLe(int a[][MAXCOL], int m, int n) {
//	int tong = 0;
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n; j++) {
//			int num = a[i][j];
//			while (num >= 10) num /= 10;
//			if (num % 2 != 0) tong += a[i][j];
//		}
//	return tong;
//}

// Bài 2: Liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[][MAXCOL], int m, int n) {
	printf("Cac so hoan thien trong ma tran: ");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (laSoHoanThien(a[i][j]))
				printf("%d ", a[i][j]);
	printf("\n");
}

//// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
//int tongPhanTuLonHonLienSau(int a[][MAXCOL], int m, int n) {
//	int tong = 0;
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n - 1; j++)
//			if (a[i][j] > abs(a[i][j + 1]))
//				tong += a[i][j];
//	// Xử lý phần tử cuối cùng của mỗi hàng
//	for (int i = 0; i < m - 1; i++)
//		if (a[i][n - 1] > abs(a[i + 1][0]))
//			tong += a[i][n - 1];
//	return tong;
//}

// Bài 4: Tính tổng các giá trị trên dòng k của ma trận
int tongDongK(int a[][MAXCOL], int n, int k) {
	int tong = 0;
	for (int j = 0; j < n; j++)
		tong += a[k][j];
	return tong;
}

//// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
//int tongBien(int a[][MAXCOL], int m, int n) {
//	int tong = 0;
//	for (int j = 0; j < n; j++) {
//		tong += a[0][j];  // Dòng đầu
//		tong += a[m - 1][j];  // Dòng cuối
//	}
//	for (int i = 1; i < m - 1; i++) {
//		tong += a[i][0];  // Cột đầu
//		tong += a[i][n - 1];  // Cột cuối
//	}
//	return tong;
//}

// Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
int demTanSuat(int a[][MAXCOL], int m, int n, int x) {
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == x)
				dem++;
	return dem;
}

//// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
//void demPhanLoai(int a[][MAXCOL], int m, int n, int *chan, int *le, int *am, int *duong, int *nguyenTo) {
//	*chan = *le = *am = *duong = *nguyenTo = 0;
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n; j++) {
//			if (a[i][j] % 2 == 0) (*chan)++;
//			else (*le)++;
//			if (a[i][j] < 0) (*am)++;
//			else if (a[i][j] > 0) (*duong)++;
//			if (laSoNguyenTo(a[i][j])) (*nguyenTo)++;
//		}
//}

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

void menu() {
	printf("\n---- MENU ----\n");
	printf("11. Nhap va xuat ma tran\n");

	printf("2. Liet ke so hoan thien\n");

	printf("4. Tinh tong gia tri tren dong k\n");

	printf("6. Dem tan suat xuat hien cua x\n");

	printf("0. Thoat\n");
	printf("-------------------------------\n");
	printf("Chon chuc nang: ");

	
}

int main() {
	int a[MAXROW][MAXCOL];
	int m, n, choice, k, x;
	int chan, le, am, duong, nguyenTo;

	do {
		menu();
		scanf("%d", &choice);
		switch (choice) {
		case 11:
			nhapMaTran(a, &m, &n);
			xuatMaTran(a, m, n);
			break;
		/*case 1:
			printf("Tong phan tu co chu so dau le: %d\n", tongPhanTuChuSoDauLe(a, m, n));
			break;*/
		case 2:
			lietKeSoHoanThien(a, m, n);
			break;
		/*case 3:
			printf("Tong phan tu lon hon tri tuyet doi phan tu lien sau: %d\n", tongPhanTuLonHonLienSau(a, m, n));
			break;*/
		case 4:
			printf("Nhap dong k: ");
			scanf("%d", &k);
			printf("Tong gia tri tren dong %d: %d\n", k, tongDongK(a, n, k));
			break;
		/*case 5:
			printf("Tong gia tri tren bien: %d\n", tongBien(a, m, n));
			break;*/
		case 6:
			printf("Nhap gia tri x: ");
			scanf("%d", &x);
			printf("Tan suat xuat hien cua %d: %d\n", x, demTanSuat(a, m, n, x));
			break;
		/*case 7:
			demPhanLoai(a, m, n, &chan, &le, &am, &duong, &nguyenTo);
			printf("So chan: %d\n", chan);
			printf("So le: %d\n", le);
			printf("So am: %d\n", am);
			printf("So duong: %d\n", duong);
			printf("So nguyen to: %d\n", nguyenTo);
			break;*/
		case 0:
			printf("Tam biet!\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 0);

	return 0;
}