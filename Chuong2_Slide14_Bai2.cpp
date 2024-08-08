#include <stdio.h>
#include <conio.h>

// Hàm tìm kiếm nhị phân cho ký tự
int BinarySearchChar(char a[], int n, char x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x)
			return mid; // Tìm thấy x trong a tại mid
		else if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1; // Không tìm thấy x trong a
}

// Hàm sắp xếp mảng ký tự theo thứ tự tăng dần
void SortArray(char a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main() {
	char arr[] = { 'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A' };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Sắp xếp mảng ký tự
	SortArray(arr, n);

	char targets1[] = { 'R', 'C' };
	char targets2[] = { 'D', 'Q' };
	int m1 = sizeof(targets1) / sizeof(targets1[0]);
	int m2 = sizeof(targets2) / sizeof(targets2[0]);

	printf("-----Tim R va C----- \n");
	printf("Ket qua tim kiem cho cac phan tu trong day ki tu:\n");
	for (int i = 0; i < m1; i++) {
		int result = BinarySearchChar(arr, n, targets1[i]);
		printf("Tim %c: %d\n", targets1[i], result);
	}

	printf("-----Tim D va Q:----- \n");
	printf("Ket qua tim kiem cho cac phan tu trong day ki tu:\n");
	for (int i = 0; i < m2; i++) {
		int result = BinarySearchChar(arr, n, targets2[i]);
		printf("Tim %c: %d\n", targets2[i], result);
	}

	_getch();

}
