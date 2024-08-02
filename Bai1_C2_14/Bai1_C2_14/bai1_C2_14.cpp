#include <stdio.h>

// Hàm tìm kiếm tuyến tính
int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i; // Trả về chỉ số của phần tử tìm thấy
    }
    return -1; // Trả về -1 nếu không tìm thấy phần tử
}

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Kiểm tra xem x có ở giữa hay không
        if (arr[mid] == x)
            return mid;

        // Nếu x lớn hơn, bỏ qua nửa bên trái
        if (arr[mid] < x)
            left = mid + 1;

        // Nếu x nhỏ hơn, bỏ qua nửa bên phải
        else
            right = mid - 1;
    }
    return -1; // Trả về -1 nếu không tìm thấy phần tử
}

int main() {
    int arr[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int x[] = { 17, 35, 40, 23, 10, 36 };
    int xSize = sizeof(x) / sizeof(x[0]);
    int choice;

    printf("Choose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        printf("Linear Search:\n");
        for (int i = 0; i < xSize; i++) {
            int result = linearSearch(arr, size, x[i]);
            if (result != -1)
                printf("Element %d is at index %d\n", x[i], result);
            else
                printf("Element %d is not found\n", x[i]);
        }
    }
    else if (choice == 2) {
        printf("Binary Search:\n");
        for (int i = 0; i < xSize; i++) {
            int result = binarySearch(arr, 0, size - 1, x[i]);
            if (result != -1)
                printf("Element %d is at index %d\n", x[i], result);
            else
                printf("Element %d is not found\n", x[i]);
        }
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
