#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm kiểm tra xem từng chữ số của một số có phải là số lẻ không
bool all_digits_odd(int num) {
	while (num > 0) {
		int digit = num % 10;
		if (digit % 2 == 0) {
			return false;
		}
		num /= 10;
	}
	return true;
}

// Hàm xuất các phần tử mà từng chữ số của nó là số lẻ
void print_all_odd_digits(int arr[], int n) {
	printf("Cac phan tu ma tung chu so cua no la so le: ");
	for (int i = 0; i < n; i++) {
		if (all_digits_odd(arr[i])) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

// Hàm kiểm tra mảng có toàn là số chẵn không
bool all_even(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0) {
			return false;
		}
	}
	return true;
}

// Hàm hiển thị menu
void display_menu() {
	printf("Chon chuc nang:\n");
	printf("1. Nhap mang\n");
	printf("2. Xuat cac phan tu ma tung chu so cua no la so le\n");
	printf("3. Kiem tra mang co toan la so chan khong\n");
	printf("4. Thoat\n");
}

int main() {
	int arr[MAX_SIZE];
	int n = 0;
	int choice;

	do {
		display_menu();
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);
		printf("---------------------\n");

		switch (choice) {
		case 1:
			printf("Nhap so luong phan tu: ");
			scanf_s("%d", &n);
			if (n > MAX_SIZE) {
				printf("So luong phan tu vuot qua kich thuoc toi da (%d).\n", MAX_SIZE);
				break;
			}
			printf("Nhap cac phan tu: ");
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &arr[i]);
			}
			break;

		case 2:
			print_all_odd_digits(arr, n);
			break;

		case 3:
			if (all_even(arr, n)) {
				printf("Mang toan la so chan.\n");
			}
			else {
				printf("Mang khong toan la so chan.\n");
			}
			break;

		case 4:
			printf("Thoat chuong trinh.\n");
			break;

		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 4);

	return 0;
}
