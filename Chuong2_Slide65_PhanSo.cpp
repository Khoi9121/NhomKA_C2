#include <stdio.h>

// Cau truc de luu tru thong tin cua phan so
struct PhanSo {
	int tu;  // Tu so
	int mau; // Mau so
};

// Ham menu
void menu() {
	printf("\n---- MENU ----\n");
	printf("1. Nhap phan so\n");
	printf("2. Xuat phan so\n");
	printf("3. Toi gian phan so\n");
	printf("4. Tinh tong cua hai phan so\n");
	printf("5. Tinh hieu cua hai phan so\n");
	printf("6. Tinh tich cua hai phan so\n");
	printf("7. Tinh thuong cua hai phan so\n");
	printf("0. Thoat\n");
	printf("---------------------- \n");
	printf("Chon chuc nang: ");
}

// Ham nhap phan so
void nhapPhanSo(struct PhanSo *ps) {
	printf("Nhap tu so: ");
	scanf_s("%d", &ps->tu);
	do {
		printf("Nhap mau so (khac 0): ");
		scanf_s("%d", &ps->mau);
		if (ps->mau == 0) {
			printf("Mau so khong the bang 0. Vui long nhap lai.\n");
		}
	} while (ps->mau == 0);
}

// Ham xuat phan so
void xuatPhanSo(struct PhanSo ps) {
	if (ps.mau == 1) {
		printf("%d\n", ps.tu);
	}
	else {
		printf("%d/%d\n", ps.tu, ps.mau);
	}
}

// Ham tim UCLN
int ucln(int a, int b) {
	if (b == 0) return a;
	return ucln(b, a % b);
}

// Ham toi gian phan so
void toiGianPhanSo(struct PhanSo *ps) {
	int u = ucln(ps->tu, ps->mau);
	ps->tu /= u;
	ps->mau /= u;
}

// Ham tinh tong cua hai phan so
struct PhanSo tong(struct PhanSo ps1, struct PhanSo ps2) {
	struct PhanSo kq;
	kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	kq.mau = ps1.mau * ps2.mau;
	toiGianPhanSo(&kq);
	return kq;
}

// Ham tinh hieu cua hai phan so
struct PhanSo hieu(struct PhanSo ps1, struct PhanSo ps2) {
	struct PhanSo kq;
	kq.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	kq.mau = ps1.mau * ps2.mau;
	toiGianPhanSo(&kq);
	return kq;
}

// Ham tinh tich cua hai phan so
struct PhanSo tich(struct PhanSo ps1, struct PhanSo ps2) {
	struct PhanSo kq;
	kq.tu = ps1.tu * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	toiGianPhanSo(&kq);
	return kq;
}

// Ham tinh thuong cua hai phan so
struct PhanSo thuong(struct PhanSo ps1, struct PhanSo ps2) {
	struct PhanSo kq;
	kq.tu = ps1.tu * ps2.mau;
	kq.mau = ps1.mau * ps2.tu;
	toiGianPhanSo(&kq);
	return kq;
}

int main() {
	struct PhanSo ps1, ps2, kq;
	int choice;

	do {
		menu();
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("Nhap phan so thu nhat:\n");
			nhapPhanSo(&ps1);
			printf("Nhap phan so thu hai:\n");
			nhapPhanSo(&ps2);
			break;
		case 2:
			printf("Phan so thu nhat: ");
			xuatPhanSo(ps1);
			printf("Phan so thu hai: ");
			xuatPhanSo(ps2);
			break;
		case 3:
			toiGianPhanSo(&ps1);
			toiGianPhanSo(&ps2);
			printf("Phan so thu nhat sau khi toi gian: ");
			xuatPhanSo(ps1);
			printf("Phan so thu hai sau khi toi gian: ");
			xuatPhanSo(ps2);
			break;
		case 4:
			kq = tong(ps1, ps2);
			printf("Tong cua hai phan so: ");
			xuatPhanSo(kq);
			break;
		case 5:
			kq = hieu(ps1, ps2);
			printf("Hieu cua hai phan so: ");
			xuatPhanSo(kq);
			break;
		case 6:
			kq = tich(ps1, ps2);
			printf("Tich cua hai phan so: ");
			xuatPhanSo(kq);
			break;
		case 7:
			kq = thuong(ps1, ps2);
			printf("Thuong cua hai phan so: ");
			xuatPhanSo(kq);
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
