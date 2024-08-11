#include <stdio.h>

#define MAX_SIZE 100

// Hàm nhập mảng
void inputArray(int a[], int *n) {
	printf("Nhap so luong phan tu cua mang: ");
	scanf_s("%d", n);
	printf("Nhap cac phan tu cua mang:\n");
	for (int i = 0; i < *n; i++) {
		scanf_s("%d", &a[i]);
	}
}

// Hàm xuất mảng
void printArray(int a[], int n) {
	printf("Mang a: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// Tìm max/min của mảng
int findMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int findMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

// Đếm số phần tử chẵn/lẻ
int countEven(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}

int countOdd(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			count++;
		}
	}
	return count;
}

// Tìm kiếm phần tử x
int linearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

// Đếm số lần xuất hiện của x
int countElement(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	return count;
}

// Đếm số phần tử lớn hơn x
int countGreaterThan(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			count++;
		}
	}
	return count;
}

// Tính tổng các phần tử
int sum(int a[], int n) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i];
	}
	return total;
}

// Kiểm tra số nguyên tố
int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

// Xuất các số nguyên tố
void printPrimes(int a[], int n) {
	printf("Cac so nguyen to trong mang: ");
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

// Kiểm tra số hoàn thiện
int isPerfect(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	return sum == n;
}

// Xuất các số hoàn thiện
void printPerfect(int a[], int n) {
	printf("Cac so hoan thien trong mang: ");
	for (int i = 0; i < n; i++) {
		if (isPerfect(a[i])) {
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

// Xuất các phần tử ở vị trí chẵn/lẻ
void printEvenPositions(int a[], int n) {
	printf("Cac phan tu o vi tri chan: ");
	for (int i = 0; i < n; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void printOddPositions(int a[], int n) {
	printf("Cac phan tu o vi tri le: ");
	for (int i = 1; i < n; i += 2) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// Xuất giá trị max/min và vị trí
void printMaxMinPosition(int a[], int n) {
	int max = findMax(a, n);
	int min = findMin(a, n);
	printf("Gia tri max: %d (vi tri %d)\n", max, linearSearch(a, n, max));
	printf("Gia tri min: %d (vi tri %d)\n", min, linearSearch(a, n, min));
}

// Ghép 2 mảng tăng dần
void mergeArrays(int a[], int b[], int m, int c[], int n, int *p) {
	int i = 0, j = 0, k = 0;
	while (i < m && j < n) {
		if (a[i] <= c[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = c[j++];
		}
	}
	while (i < m) {
		b[k++] = a[i++];
	}
	while (j < n) {
		b[k++] = c[j++];
	}
	*p = k;
}

void menu() {
	printf("\n---- MENU ----\n");
	printf("1. Nhap mang va xuat mang\n");
	printf("2. Tim max/min cua mang\n");
	printf("4. Tim kiem phan tu x\n");
	printf("6. Dem so phan tu lon hon x\n");
	printf("8. Xuat cac so nguyen to\n");
	printf("10. Xuat cac phan tu o vi tri chan/le\n");
	printf("12. Ghep 2 mang tang dan\n");
	printf("0. Thoat\n");
	printf("---------------------- \n");
	printf("Chon chuc nang: ");
}


int main() {
	int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
	int n = 0, m, p;
	int choice, x;

	do {
		menu();
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			inputArray(a, &n);
			printArray(a, n);
			break;
		case 2:
			printf("Gia tri max: %d\n", findMax(a, n));
			printf("Gia tri min: %d\n", findMin(a, n));
			break;
		
		case 4:
		{
			printf("Nhap phan tu can tim: ");
			scanf_s("%d", &x);
			int index = linearSearch(a, n, x);
			if (index == -1) {
				printf("Khong tim thay %d trong mang\n", x);
			}
			else {
				printf("Tim thay %d tai vi tri %d (tim kiem tuyen tinh)\n", x, index);
			}
			index = binarySearch(a, n, x);
			if (index == -1) {
				printf("Khong tim thay %d trong mang\n", x);
			}
			else {
				printf("Tim thay %d tai vi tri %d (tim kiem nhi phan)\n", x, index);
			}
			break;
		}
		case 6:
			printf("Nhap x: ");
			scanf_s("%d", &x);
			printf("So phan tu lon hon %d: %d\n", x, countGreaterThan(a, n, x));
			break;
		case 8:
			printPrimes(a, n);
			break;
		case 10:
			printEvenPositions(a, n);
			printOddPositions(a, n);
			break;
		case 12:
			printf("Nhap so luong phan tu cua mang b: ");
			scanf_s("%d", &m);
			printf("Nhap cac phan tu cua mang b:\n");
			for (int i = 0; i < m; i++) {
				scanf_s("%d", &b[i]);
			}
			printf("Nhap so luong phan tu cua mang c: ");
			scanf_s("%d", &n);
			printf("Nhap cac phan tu cua mang c:\n");
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &c[i]);
			}
			mergeArrays(b, a, m, c, n, &p);
			printf("Mang a sau khi ghep: ");
			for (int i = 0; i < p; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
			n = p;
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