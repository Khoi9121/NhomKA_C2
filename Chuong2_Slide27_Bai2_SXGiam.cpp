#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100  // Định nghĩa kích thước tối đa của mảng

// Hàm hoán đổi hai số nguyên
void swap_int(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi hai số thực
void swap_float(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi hai ký tự
void swap_char(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi hai chuỗi ký tự
void swap_string(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp giảm dần theo PP Interchange Sort cho số nguyên
void interchange_sort_int(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) { // Change from > to <
				swap_int(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp giảm dần theo PP Interchange Sort cho số thực
void interchange_sort_float(float arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) { // Change from > to <
				swap_float(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp giảm dần theo PP Interchange Sort cho ký tự
void interchange_sort_char(char arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) { // Change from > to <
				swap_char(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp giảm dần theo PP Interchange Sort cho chuỗi ký tự
void interchange_sort_string(char* arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[i], arr[j]) < 0) { // Change from > to <
				swap_string(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm hiển thị mảng số nguyên
void print_array_int(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Hàm hiển thị mảng số thực
void print_array_float(float arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
}

// Hàm hiển thị mảng ký tự
void print_array_char(char arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

// Hàm hiển thị mảng chuỗi ký tự
void print_array_string(char* arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%s ", arr[i]);
	}
	printf("\n");
}

// Hàm hiển thị menu
void display_menu() {
	printf("Chon loai du lieu de sap xep:\n");
	printf("1. So nguyen\n");
	printf("2. So thuc\n");
	printf("3. Ky tu\n");
	printf("4. Chuoi ky tu\n");
	printf("5. Thoat\n");
}

int main() {
	int choice;
	do {
		display_menu();
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1: {
			int n;
			printf("Nhap so luong phan tu: ");
			scanf_s("%d", &n);
			if (n > MAX_SIZE) {
				printf("So luong phan tu vuot qua kich thuoc toi da (%d).\n", MAX_SIZE);
				break;
			}
			int arr[MAX_SIZE];
			printf("Nhap cac phan tu: ");
			for (int i = 0; i < n; i++) {
				scanf_s("%d", &arr[i]);
			}
			printf("Mang truoc khi sap xep: ");
			print_array_int(arr, n);
			interchange_sort_int(arr, n);
			printf("Mang sau khi sap xep: ");
			print_array_int(arr, n);
			break;
		}
		case 2: {
			int n;
			printf("Nhap so luong phan tu: ");
			scanf_s("%d", &n);
			if (n > MAX_SIZE) {
				printf("So luong phan tu vuot qua kich thuoc toi da (%d).\n", MAX_SIZE);
				break;
			}
			float arr[MAX_SIZE];
			printf("Nhap cac phan tu: ");
			for (int i = 0; i < n; i++) {
				scanf_s("%f", &arr[i]);
			}
			printf("Mang truoc khi sap xep: ");
			print_array_float(arr, n);
			interchange_sort_float(arr, n);
			printf("Mang sau khi sap xep: ");
			print_array_float(arr, n);
			break;
		}
		case 3: {
			int n;
			printf("Nhap so luong phan tu: ");
			scanf_s("%d", &n);
			if (n > MAX_SIZE) {
				printf("So luong phan tu vuot qua kich thuoc toi da (%d).\n", MAX_SIZE);
				break;
			}
			char arr[MAX_SIZE];
			printf("Nhap cac phan tu: ");
			for (int i = 0; i < n; i++) {
				scanf_s(" %c", &arr[i]);  // Lưu ý khoảng trắng trước %c để bỏ qua khoảng trắng
			}
			printf("Mang truoc khi sap xep: ");
			print_array_char(arr, n);
			interchange_sort_char(arr, n);
			printf("Mang sau khi sap xep: ");
			print_array_char(arr, n);
			break;
		}
		case 4: {
			int n;
			printf("Nhap so luong phan tu: ");
			scanf_s("%d", &n);
			if (n > MAX_SIZE) {
				printf("So luong phan tu vuot qua kich thuoc toi da (%d).\n", MAX_SIZE);
				break;
			}
			char arr[MAX_SIZE][100];
			printf("Nhap cac phan tu: ");
			for (int i = 0; i < n; i++) {
				scanf_s("%s", arr[i]);
			}
			char* arr_ptr[MAX_SIZE];
			for (int i = 0; i < n; i++) {
				arr_ptr[i] = arr[i];
			}
			printf("Mang truoc khi sap xep: ");
			print_array_string(arr_ptr, n);
			interchange_sort_string(arr_ptr, n);
			printf("Mang sau khi sap xep: ");
			print_array_string(arr_ptr, n);
			break;
		}
		case 5:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 5);

	return 0;
}