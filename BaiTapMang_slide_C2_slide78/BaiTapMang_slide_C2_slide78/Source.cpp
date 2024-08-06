#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu tiên của số
bool isFirstDigitOdd(int num) {
    if (num < 0) num = -num;  // Đảm bảo số dương
    while (num >= 10) num /= 10;  // Lấy chữ số đầu tiên
    return (num % 2 != 0);
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddFirstDigit(int arr[][100], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isFirstDigitOdd(arr[i][j])) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int sumGreaterThanAbsNext(int arr[][100], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] > abs(arr[i][j + 1])) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int sumBoundary(int arr[][100], int m, int n) {
    int sum = 0;
    // Tổng hàng đầu và hàng cuối
    for (int j = 0; j < n; j++) {
        sum += arr[0][j];
        sum += arr[m - 1][j];
    }
    // Tổng cột bên trái và bên phải
    for (int i = 1; i < m - 1; i++) {
        sum += arr[i][0];
        sum += arr[i][n - 1];
    }
    return sum;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void countElements(int arr[][100], int m, int n, int* even, int* odd, int* negative, int* positive, int* prime) {
    *even = *odd = *negative = *positive = *prime = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int value = arr[i][j];
            if (value % 2 == 0) (*even)++;
            else (*odd)++;
            if (value < 0) (*negative)++;
            else if (value > 0) (*positive)++;
            if (isPrime(value)) (*prime)++;
        }
    }
}

int main() {
    int m, n;
    printf("Nhập số hàng và số cột của ma trận: ");
    scanf_s("%d %d", &m, &n);
    int arr[100][100];

    printf("Nhập các phần tử của ma trận:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &arr[i][j]);
        }
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tính tổng các phần tử có chữ số đầu là chữ số lẻ\n");
        printf("2. Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó\n");
        printf("3. Tính tổng các giá trị nằm trên biên của ma trận\n");
        printf("4. Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố\n");
        printf("5. Thoát\n");
        printf("Nhập lựa chọn: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Tổng các phần tử có chữ số đầu là chữ số lẻ: %d\n", sumOddFirstDigit(arr, m, n));
            break;
        case 2:
            printf("Tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó: %d\n", sumGreaterThanAbsNext(arr, m, n));
            break;
        case 3:
            printf("Tổng các giá trị nằm trên biên của ma trận: %d\n", sumBoundary(arr, m, n));
            break;
        case 4: {
            int even, odd, negative, positive, prime;
            countElements(arr, m, n, &even, &odd, &negative, &positive, &prime);
            printf("Số lượng số chẵn: %d\n", even);
            printf("Số lượng số lẻ: %d\n", odd);
            printf("Số lượng số âm: %d\n", negative);
            printf("Số lượng số dương: %d\n", positive);
            printf("Số lượng số nguyên tố: %d\n", prime);
            break;
        }
        case 5:
            printf("Thoát chương trình.\n");
            break;
        default:
            printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 5);

    return 0;
}
