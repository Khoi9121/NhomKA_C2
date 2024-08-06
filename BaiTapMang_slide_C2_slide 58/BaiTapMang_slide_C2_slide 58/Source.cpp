#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm kiểm tra số nguyên tố
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm đếm số phần tử là số nguyên tố trong mảng
int count_primes(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            count++;
        }
    }
    return count;
}

// Hàm tìm vị trí số lớn nhất cuối cùng trong mảng
int find_last_max_position(int arr[], int n) {
    int max_val = arr[0];
    int max_pos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= max_val) {
            max_val = arr[i];
            max_pos = i;
        }
    }
    return max_pos;
}

// Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
bool is_alternate_even_odd(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] % 2 == 0 && arr[i + 1] % 2 == 0) ||
            (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

// Hàm hiển thị menu
void display_menu() {
    printf("Chon chuc nang:\n");
    printf("1. Nhap mang\n");
    printf("2. Dem so phan tu la so nguyen to\n");
    printf("3. Tim vi tri so lon nhat (cuoi cung)\n");
    printf("4. Kiem tra mang co phai la day so chan le xen ke khong\n");
    printf("5. Thoat\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;

    do {
        display_menu();
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

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
            printf("So phan tu la so nguyen to trong mang: %d\n", count_primes(arr, n));
            break;

        case 3:
            printf("Vi tri so lon nhat cuoi cung trong mang: %d\n", find_last_max_position(arr, n));
            break;

        case 4:
            if (is_alternate_even_odd(arr, n)) {
                printf("Mang la day so chan le xen ke.\n");
            }
            else {
                printf("Mang khong la day so chan le xen ke.\n");
            }
            break;

        case 5:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);

    return 0;
}
