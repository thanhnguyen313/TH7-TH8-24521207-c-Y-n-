#include <iostream>
using namespace std;

class NhanVien {
protected:
    string hoTen, ngaySinh;
public:
    void Nhap();
    void Xuat();
};

void NhanVien::Nhap() {
    cout << "--------------------\n";
    cin.ignore();
    cout << "Nhap ten nhan vien: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
}

void NhanVien::Xuat() {
    cout << "--------------------\n";
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
}

class NVSX : public NhanVien {
private:
    double luongCanBan;
    int soSanPham;
public:
    void Nhap();
    double TinhLuong();
    void Xuat();
};

void NVSX::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap luong can ban: ";
    cin >> luongCanBan;
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

double NVSX::TinhLuong() {
    return luongCanBan * soSanPham * 5000;
}

void NVSX::Xuat() {
    NhanVien::Xuat();
    cout << "Luong: " << TinhLuong() << endl;
    cout << "--------------------\n";
}

class NVVP : public NhanVien {
private:
    int soNgayLamViec;
public:
    void Nhap();
    double TinhLuong();
    void Xuat();
};

void NVVP::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
}

double NVVP::TinhLuong() {
    return soNgayLamViec * 100000;
}

void NVVP::Xuat() {
    NhanVien::Xuat();
    cout << "Luong: " << TinhLuong() << endl;
    cout << "--------------------\n";
}

class QuanLy {
private:
    NVSX dsNVSX[100];
    NVVP dsNVVP[100];
    int soNVSX, soNVVP;
public:
    QuanLy();
    void NhapNVSX();
    void NhapNVVP();
    void XuatDanhSach();
    double TongLuong();
    void Menu();
};

QuanLy::QuanLy() : soNVSX(0), soNVVP(0) {}

void QuanLy::NhapNVSX() {
    cout << "Nhap so luong NV san xuat: ";
    cin >> soNVSX;
    for (int i = 0; i < soNVSX; i++) dsNVSX[i].Nhap();
}

void QuanLy::NhapNVVP() {
    cout << "Nhap so luong NV van phong: ";
    cin >> soNVVP;
    for (int i = 0; i < soNVVP; i++) dsNVVP[i].Nhap();
}

void QuanLy::XuatDanhSach() {
    if (soNVSX == 0 && soNVVP == 0) {
        cout << "Danh sach rong.\n";
        return;
    }
    cout << "--------NV San Xuat--------\n";
    for (int i = 0; i < soNVSX; i++) dsNVSX[i].Xuat();
    cout << "--------NV Van Phong--------\n";
    for (int i = 0; i < soNVVP; i++) dsNVVP[i].Xuat();
}

double QuanLy::TongLuong() {
    double sum = 0;
    for (int i = 0; i < soNVSX; i++) sum += dsNVSX[i].TinhLuong();
    for (int i = 0; i < soNVVP; i++) sum += dsNVVP[i].TinhLuong();
    return sum;
}

void QuanLy::Menu() {
    int choice;
    do {
        system("cls");
        cout << "\t------ MENU ------\n";
        cout << "1. Nhap danh sach nhan vien san xuat.\n";
        cout << "2. Nhap danh sach nhan vien van phong.\n";
        cout << "3. Xuat danh sach nhan vien.\n";
        cout << "4. Tinh tong luong cong ty phai tra.\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        switch (choice) {
        case 1: NhapNVSX(); break;
        case 2: NhapNVVP(); break;
        case 3: XuatDanhSach(); break;
        case 4: cout << "Luong cong ty phai tra: " << TongLuong() << "\n"; break;
        case 0: break;
        default: cout << "Lua chon khong hop le!\n";
        }
        cout << "\nNhan phim bat ky de tiep tuc...";
        cin.ignore();
        cin.get();
    } while (choice != 0);
}

int main() {
    QuanLy a;
    a.Menu();
    return 0;
}
