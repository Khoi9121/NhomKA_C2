#include <stdio.h>
#include <stdbool.h>

// Hàm nhập mảng
void nhapMang(int arr[], int size) {
    printf("Nhập %d phần tử:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Phần tử %d: ", i + 1);
        scanf_s("%d", &arr[i]);
    }
}

// Hàm xuất mảng
void xuatMang(int arr[], int size) {
    printf("Các phần tử trong mảng là:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hàm đếm số phần tử chẵn/lẻ
void demChanLe(int arr[], int size, int* demChan, int* demLe) {
    *demChan = 0;
    *demLe = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            (*demChan)++;
        else
            (*demLe)++;
    }
}

// Hàm đếm số lần xuất hiện của một giá trị x
int demGiaTri(int arr[], int size, int x) {
    int dem = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            dem++;
    }
    return dem;
}

// Hàm tính tổng các phần tử của mảng
int tongMang(int arr[], int size) {
    int tong = 0;
    for (int i = 0; i < size; i++) {
        tong += arr[i];
    }
    return tong;
}

// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int n) {
    int tong = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong == n;
}

// Hàm xuất các số hoàn thiện
void xuatSoHoanThien(int arr[], int size) {
    printf("Các số hoàn thiện trong mảng là:\n");
    bool coSoHoanThien = false;
    for (int i = 0; i < size; i++) {
        if (laSoHoanThien(arr[i])) {
            printf("%d ", arr[i]);
            coSoHoanThien = true;
        }
    }
    if (!coSoHoanThien) {
        printf("Không có số hoàn thiện nào trong mảng.\n");
    }
    printf("\n");
}

// Hàm tìm giá trị lớn nhất/nhỏ nhất kèm theo vị trí của chúng
void timMaxMin(int arr[], int size, int* max, int* maxIndex, int* min, int* minIndex) {
    *max = arr[0];
    *min = arr[0];
    *maxIndex = 0;
    *minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
            *maxIndex = i;
        }
        if (arr[i] < *min) {
            *min = arr[i];
            *minIndex = i;
        }
    }
}

int main() {
    int n, x;
    int arr[100];  // Giới hạn kích thước mảng là 100

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Nhập mảng\n");
        printf("2. Xuất mảng\n");
        printf("3. Đếm số phần tử chẵn/lẻ\n");
        printf("4. Đếm số lần xuất hiện của một giá trị x\n");
        printf("5. Tính tổng các phần tử\n");
        printf("6. Xuất các số hoàn thiện\n");
        printf("7. Tìm giá trị lớn nhất/nhỏ nhất và vị trí\n");
        printf("8. Thoát\n");
        printf("Chọn một tùy chọn: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhập kích thước của mảng (tối đa 100): ");
            scanf_s("%d", &n);
            if (n > 100) {
                printf("Kích thước mảng không hợp lệ.\n");
                n = 100;
            }
            nhapMang(arr, n);
            break;

        case 2:
            xuatMang(arr, n);
            break;

        case 3:
        {
            int demChan, demLe;
            demChanLe(arr, n, &demChan, &demLe);
            printf("Số phần tử chẵn: %d\n", demChan);
            printf("Số phần tử lẻ: %d\n", demLe);
        }
        break;

        case 4:
            printf("Nhập giá trị x cần đếm: ");
            scanf_s("%d", &x);
            printf("Số lần xuất hiện của %d là: %d\n", x, demGiaTri(arr, n, x));
            break;

        case 5:
            printf("Tổng các phần tử của mảng là: %d\n", tongMang(arr, n));
            break;

        case 6:
            xuatSoHoanThien(arr, n);
            break;

        case 7:
        {
            int max, maxIndex, min, minIndex;
            timMaxMin(arr, n, &max, &maxIndex, &min, &minIndex);
            printf("Giá trị lớn nhất là %d tại vị trí %d\n", max, maxIndex);
            printf("Giá trị nhỏ nhất là %d tại vị trí %d\n", min, minIndex);
        }
        break;

        case 8:
            printf("Thoát chương trình.\n");
            return 0;

        default:
            printf("Tùy chọn không hợp lệ. Vui lòng chọn lại.\n");
        }
    }

    return 0;
}
