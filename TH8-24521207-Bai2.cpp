#include <iostream>
using namespace std;

bool ktNamNhuan(int year);
int ktThang(int month, int year);

class BDS {
private:
    string ma;
    int day, month, year;
    double dongia, dientich;
public:
    BDS() {};
    double getDientich() { return dientich; }
    double getDongia() { return dongia; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void Input() {
        cout << "--------------------\n";
        cout << "Nhap ma giao dich: ";
        cin.ignore();
        getline(cin, ma);
        cout << "->Nhap ngay giao dich<-\n";
        cout << "Nhap nam: ";
        cin >> year;
        do {
            cout << "Nhap thang: ";
            cin >> month;
            if (month < 1 || month > 12) cout << "Thang phai > 0 va <= 12! \n";
        } while (month < 1 || month > 12);
        do {
            cout << "Nhap ngay: ";
            cin >> day;
            if (day > ktThang(month, year) || day < 1) cout << "Qua ngay trong thang! \n";
        } while (day > ktThang(month, year) || day < 1);
        cout << "Nhap don gia: ";
        cin >> dongia;
        cout << "Nhap dien tich: ";
        cin >> dientich;
    }
    void Output() {
        cout << "--------------------\n";
        cout << "Ma giao dich: " << ma << endl;
        cout << "Ngay giao dich: " << day << "/" << month << "/" << year << endl;
        cout << "Don gia: " << dongia << endl;
        cout << "Dien tich: " << dientich << endl;
    }
};

class Dat : public BDS {
private:
    string loai;
public:
    void Input() {
        BDS::Input();
        cin.ignore();
        do {
            cout << "Nhap vao loai dat (A/B/C): ";
            getline(cin, loai);
            if (loai != "A" && loai != "B" && loai != "C") cout << "Chi nhap (A/B/C)! \n";
        } while (loai != "A" && loai != "B" && loai != "C");
        cout << "--------------------\n";
    }
    double ThanhTien() {
        if (loai == "B" || loai == "C") return getDientich() * getDongia();
        else if (loai == "A") return getDientich() * getDongia() * 1.5;
        return 0;
    }
    void Output() {
        BDS::Output();
        cout << "Loai dat: " << loai << endl;
        cout << "Thanh tien: " << ThanhTien() << endl;
        cout << "--------------------\n";
    }
};

class NhaPho : public BDS {
private:
    string loai, diachi;
public:
    void Input() {
        BDS::Input();
        cin.ignore();
        do {
            cout << "Nhap loai nha (cao cap/thuong): ";
            getline(cin, loai);
            if (loai != "cao cap" && loai != "thuong") cout << "Chi nhap (cao cap/thuong): \n";
        } while (loai != "cao cap" && loai != "thuong");
        cout << "Nhap dia chi: ";
        getline(cin, diachi);
        cout << "--------------------\n";
    }
    double ThanhTien() {
        if (loai == "cao cap") return getDientich() * getDongia();
        else if (loai == "thuong") return getDientich() * getDongia() * 0.9;
        return 0;
    }
    void Output() {
        BDS::Output();
        cout << "Loai nha: " << loai << endl;
        cout << "Dia chi: " << diachi << endl;
        cout << "Thanh tien: " << ThanhTien() << endl;
        cout << "--------------------\n";
    }
};

class ChungCu:public BDS
{
private:
    string macan;
    int vitri;
public:
    void Input()
    {
        BDS::Input();
        cout << "Nhap ma can ho: ";
        cin.ignore();
        getline(cin,macan);
        cout << "Nhap vi tri tang: ";
        cin >> vitri;
        cout << "--------------------\n";
    }
    double thanhtien()
    {
        if(vitri == 1) return getDientich()*getDongia()*2;
        else if(vitri >= 15) return getDientich()*getDongia()*1.2;
        else return getDientich()*getDongia();
    }
    void Output()
    {
        BDS::Output();
        cout << "Ma can ho: " << macan <<endl;
        cout << "Tang so: " << vitri << endl;
        cout << "Thanh tien: " << thanhtien() <<endl;
        cout << "--------------------\n";
    }
};


class QuanLy {
    private:
        Dat A[100];
        NhaPho B[100];
        ChungCu C[100];
        int a, b, c;
    
    public:
        QuanLy() : a(0), b(0), c(0) {}
    
        void nhapDat(Dat A[], int &a) {
            cout << "Nhap so giao dich dat: ";
            cin >> a;
            for (int i = 0; i < a; i++) {
                A[i].Input();
            }
        }
    
        void nhapNhapho(NhaPho B[], int &b) {
            cout << "Nhap so giao dich nha pho: ";
            cin >> b;
            for (int i = 0; i < b; i++) {
                B[i].Input();
            }
        }
    
        void nhapChungcu(ChungCu C[], int &c) {
            cout << "Nhap so giao dich chung cu: ";
            cin >> c;
            for (int i = 0; i < c; i++) {
                C[i].Input();
            }
        }
    
        double tbtienchungcu(ChungCu C[], int &c) {
            if (c == 0) return 0;
            double sum = 0;
            for (int i = 0; i < c; i++) {
                sum += C[i].thanhtien();
            }
            return sum / c;
        }
    
        void nhaphocaoI(NhaPho B[], int &b) {
            if (b == 0) return;
            double max = B[0].ThanhTien();
            for (int i = 1; i < b; i++) {
                if (max < B[i].ThanhTien()) {
                    max = B[i].ThanhTien();
                }
            }
            for (int i = 0; i < b; i++) {
                if (B[i].ThanhTien() == max) {
                    B[i].Output();
                }
            }
        }
    
        void timkiem(Dat A[], NhaPho B[], ChungCu C[], int a, int b, int c) {
            cout << "\nGiao dich dat trong thang 12/2024:\n";
            for (int i = 0; i < a; i++) {
                if (A[i].getMonth() == 12 && A[i].getYear() == 2024) {
                    A[i].Output();
                }
            }
            cout << "\nGiao dich nha pho trong thang 12/2024:\n";
            for (int i = 0; i < b; i++) {
                if (B[i].getMonth() == 12 && B[i].getYear() == 2024) {
                    B[i].Output();
                }
            }
            cout << "\nGiao dich chung cu trong thang 12/2024:\n";
            for (int i = 0; i < c; i++) {
                if (C[i].getMonth() == 12 && C[i].getYear() == 2024) {
                    C[i].Output();
                }
            }
        }
    
        void Menu() {
            int choice;
            do {
                cout << "\t MENU \t \n";
                cout << "1. Nhap danh sach giao dich dat.\n";
                cout << "2. Nhap danh sach giao dich nha pho.\n";
                cout << "3. Nhap danh sach giao dich chung cu.\n";
                cout << "4. Tinh trung binh thanh tien cua giao dich chung cu.\n";
                cout << "5. Xuat nha pho co gia tri cao nhat.\n";
                cout << "6. Xuat giao dich cua thang 12 nam 2024.\n";
                cout << "0. Thoat.\n";
                cout << "Chon: ";
                cin >> choice;
    
                switch (choice) {
                    case 1:
                        nhapDat(A, a);
                        break;
                    case 2:
                        nhapNhapho(B, b);
                        break;
                    case 3:
                        nhapChungcu(C, c);
                        break;
                    case 4:
                        cout << "Trung binh thanh tien cua giao dich chung cu: " 
                             << tbtienchungcu(C, c) << "\n";
                        break;
                    case 5:
                        cout << "Nha pho co gia tri cao nhat:\n";
                        nhaphocaoI(B, b);
                        break;
                    case 6:
                        timkiem(A, B, C, a, b, c);
                        break;
                    case 0:
                        cout << "Thoat chuong trinh.\n";
                        break;
                    default:
                        cout << "Lua chon khong hop le! Vui long nhap lai.\n";
                }
                if (choice != 0) {
                    cout << "\nNhan phim bat ky de tiep tuc...";
                    cin.ignore();
                    cin.get();
                }
            } while (choice != 0);
        }
};



bool ktNamNhuan(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int ktThang(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: return ktNamNhuan(year) ? 29 : 28;
    default: return -1;
    }
}

int main() {
    QuanLy a;
    a.Menu();
    return 0;
}