#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

bool kiemTraDoiXung(int arr[], int size) {
	for (int i = 0; i < size / 2; i++) {
		if (arr[i] != arr[size - 1 - i]) {
			return false;  // Nếu có phần tử không đối xứng, trả về false
		}
	}
	return true;  // Nếu tất cả các phần tử đều đối xứng, trả về true
}

void nhapMang(int arr[], int size) {
	printf("Nhap %d phan tu cho mang:\n", size);
	for (int i = 0; i < size; i++) {
		printf("Phan tu %d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}
}

void xuatMang(int arr[], int size) {
	printf("Mang co %d phan tu la:\n", size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

	int arr[] = { 1, 2, 3, 2, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//nhapMang(arr, size);
    xuatMang(arr, size);  // Xuất dữ liệu của mảng
	printf("-------------------\n");
	printf("Ket qua la: ");
	if (kiemTraDoiXung(arr, size)) {
		printf("Mang doi xung.\n");
	}
	else {
		printf("Mang khong doi xung.\n");
	}
	_getch();
	return 0;
}
