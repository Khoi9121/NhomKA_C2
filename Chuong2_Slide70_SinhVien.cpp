#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



// Cau truc luu tru thong tin sinh vien
struct SinhVien {
	int stt;
	char mssv[11];
	char hoTen[31];
	float diemTieuLuan;
	float diemThiKetThuc;
	float diemTongKet;
};

// Ham nhap danh sach sinh vien
void nhapDanhSachSinhVien(struct SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		ds[i].stt = i + 1;
		printf("Nhap thong tin sinh vien thu %d:\n", ds[i].stt);
		printf("Ma so sinh vien: ");
		scanf_s("%s", ds[i].mssv);
		printf("Ho ten sinh vien: ");
		scanf_s(" %[^\n]%*c", ds[i].hoTen); // Nhap chuoi co khoang trang
		printf("Diem tieu luan: ");
		scanf_s("%f", &ds[i].diemTieuLuan);
		printf("Diem thi ket thuc: ");
		scanf_s("%f", &ds[i].diemThiKetThuc);

		// Tinh diem tong ket
		ds[i].diemTongKet = 0.3 * ds[i].diemTieuLuan + 0.7 * ds[i].diemThiKetThuc;
	}
}

// Ham xuat danh sach sinh vien
void xuatDanhSachSinhVien(struct SinhVien ds[], int n) {
	printf("\nDanh sach sinh vien:\n");
	printf("%-5s %-10s %-30s %-10s %-10s %-10s\n", "STT", "MSSV", "Ho va ten", "Tieu luan", "Ket thuc", "Tong ket");
	for (int i = 0; i < n; i++) {
		printf("%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f\n", ds[i].stt, ds[i].mssv, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThiKetThuc, ds[i].diemTongKet);
	}
}

// Ham tim sinh vien co diem tong ket cao nhat va thap nhat
void timDiemCaoNhatVaThapNhat(struct SinhVien ds[], int n) {
	int maxIndex = 0, minIndex = 0;
	for (int i = 1; i < n; i++) {
		if (ds[i].diemTongKet > ds[maxIndex].diemTongKet) {
			maxIndex = i;
		}
		if (ds[i].diemTongKet < ds[minIndex].diemTongKet) {
			minIndex = i;
		}
	}
	printf("\nSinh vien co diem tong ket cao nhat:\n");
	printf("%-5s %-10s %-30s %-10s %-10s %-10s\n", "STT", "MSSV", "Ho va ten", "Tieu luan", "Ket thuc", "Tong ket");
	printf("%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f\n", ds[maxIndex].stt, ds[maxIndex].mssv, ds[maxIndex].hoTen, ds[maxIndex].diemTieuLuan, ds[maxIndex].diemThiKetThuc, ds[maxIndex].diemTongKet);

	printf("\nSinh vien co diem tong ket thap nhat:\n");
	printf("%-5s %-10s %-30s %-10s %-10s %-10s\n", "STT", "MSSV", "Ho va ten", "Tieu luan", "Ket thuc", "Tong ket");
	printf("%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f\n", ds[minIndex].stt, ds[minIndex].mssv, ds[minIndex].hoTen, ds[minIndex].diemTieuLuan, ds[minIndex].diemThiKetThuc, ds[minIndex].diemTongKet);
}

// Ham kiem tra so luong sinh vien dat va khong dat
void kiemTraDatKhongDat(struct SinhVien ds[], int n) {
	int soLuongDat = 0;
	for (int i = 0; i < n; i++) {
		if (ds[i].diemTongKet >= 4.0) {
			soLuongDat++;
		}
	}
	printf("\nSo luong sinh vien dat: %d\n", soLuongDat);
	printf("So luong sinh vien khong dat: %d\n", n - soLuongDat);
}

// Ham qui doi diem tu he 10 sang he 4
void quiDoiDiem(struct SinhVien ds[], int n) {
	printf("\nDiem he 4 cua sinh vien:\n");
	printf("%-5s %-10s %-30s %-10s\n", "STT", "MSSV", "Ho va ten", "He 4");
	for (int i = 0; i < n; i++) {
		float diemHe4;
		if (ds[i].diemTongKet >= 8.5) diemHe4 = 4.0;
		else if (ds[i].diemTongKet >= 7.0) diemHe4 = 3.0;
		else if (ds[i].diemTongKet >= 5.5) diemHe4 = 2.0;
		else if (ds[i].diemTongKet >= 4.0) diemHe4 = 1.0;
		else diemHe4 = 0.0;
		printf("%-5d %-10s %-30s %-10.2f\n", ds[i].stt, ds[i].mssv, ds[i].hoTen, diemHe4);
	}
}

// Ham sap xep danh sach sinh vien theo diem tong ket
void sapXepDanhSachSinhVien(struct SinhVien ds[], int n, int tangDan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tangDan && ds[i].diemTongKet > ds[j].diemTongKet) ||
				(!tangDan && ds[i].diemTongKet < ds[j].diemTongKet)) {
				struct SinhVien temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}

// Ham tinh diem trung binh cua tat ca sinh vien
void tinhDiemTrungBinh(struct SinhVien ds[], int n) {
	float tongDiem = 0;
	for (int i = 0; i < n; i++) {
		tongDiem += ds[i].diemTongKet;
	}
	printf("\nDiem trung binh cua tat ca sinh vien: %.2f\n", tongDiem / n);
}

// Ham luu du lieu vao file
void luuDuLieuVaoFile(struct SinhVien ds[], int n, const char* fileName) {
	FILE *file = fopen(fileName, "w");
	if (file == NULL) {
		printf("Khong the mo file de ghi du lieu.\n");
		return;
	}
	fprintf(file, "%-5s %-10s %-30s %-10s %-10s %-10s\n", "STT", "MSSV", "Ho va ten", "Tieu luan", "Ket thuc", "Tong ket");
	for (int i = 0; i < n; i++) {
		fprintf(file, "%-5d %-10s %-30s %-10.2f %-10.2f %-10.2f\n", ds[i].stt, ds[i].mssv, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThiKetThuc, ds[i].diemTongKet);
	}
	fclose(file);
	printf("Da luu du lieu vao file %s thanh cong.\n", fileName);
}

// Ham doc du lieu tu file
void docDuLieuTuFile(struct SinhVien ds[], int *n, const char* fileName) {
	FILE *file = fopen(fileName, "r");
	if (file == NULL) {
		printf("Khong the mo file de doc du lieu.\n");
		return;
	}
	fscanf_s(file, "%*s %*s %*s %*s %*s %*s"); // Bo qua dong tieu de
	*n = 0;
	while (fscanf_s(file, "%d %s %[^\n]%*c %f %f %f", &ds[*n].stt, ds[*n].mssv, ds[*n].hoTen, &ds[*n].diemTieuLuan, &ds[*n].diemThiKetThuc, &ds[*n].diemTongKet) != EOF) {
		(*n)++;
	}
	fclose(file);
	printf("Da doc du lieu tu file %s thanh cong.\n", fileName);
}

// Ham menu chinh
void menu() {
	printf("\n---- MENU ----\n");
	printf("1. Nhap danh sach sinh vien\n");
	printf("2. Xuat danh sach sinh vien\n");
	printf("3. Tim diem tong ket cao nhat va thap nhat\n");
	printf("4. Kiem tra so luong sinh vien dat va khong dat\n");
	printf("5. Qui doi diem tu he 10 sang he 4\n");
	printf("6. Sap xep danh sach sinh vien tang/giam dan theo diem tong ket\n");
	printf("7. Tinh diem trung binh cua tat ca sinh vien\n");
	printf("8. Luu du lieu vao file\n");
	printf("9. Doc du lieu tu file\n");
	printf("0. Thoat\n");
	printf("----------------------\n");
	printf("Chon chuc nang: ");
}

int main() {
	struct SinhVien ds[100];
	int n = 0;
	int choice;
	do {
		menu();
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap so luong sinh vien: ");
			scanf_s("%d", &n);
			nhapDanhSachSinhVien(ds, n);
			break;
		case 2:
			xuatDanhSachSinhVien(ds, n);
			break;
		case 3:
			timDiemCaoNhatVaThapNhat(ds, n);
			break;
		case 4:
			kiemTraDatKhongDat(ds, n);
			break;
		case 5:
			quiDoiDiem(ds, n);
			break;
		case 6: {
			int tangDan;
			printf("Chon 1 de sap xep tang dan, 0 de sap xep giam dan: ");
			scanf_s("%d", &tangDan);
			sapXepDanhSachSinhVien(ds, n, tangDan);
			xuatDanhSachSinhVien(ds, n);
			break;
		}
		case 7:
			tinhDiemTrungBinh(ds, n);
			break;
		case 8:
			luuDuLieuVaoFile(ds, n, "sinhvien.txt");
			break;
		case 9:
			docDuLieuTuFile(ds, &n, "sinhvien.txt");
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