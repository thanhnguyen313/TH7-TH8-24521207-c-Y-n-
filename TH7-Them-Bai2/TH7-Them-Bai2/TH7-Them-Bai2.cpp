#include "STUDENT.h"
#include "ListStudent.h"
#include <iostream>
using namespace std;
int main()
{
    ListStudent list;
    list.listStudentInput();
    int choosen;
    do
    {
        cout << "\n==================================================";
        cout << "\n---------- CHUONG TRINH QUAN LY THI SINH ---------";
        cout << "\n 0. Thoat chuong trinh. ";
        cout << "\n 1. Danh sach cac sinh vien va hoc bong tuong ung. ";
        cout << "\n 2. Danh sach cac SVCQ co DRL la 100. ";
        cout << "\n 3. So luong SVLT khong nghi buoi nao. ";
        cout << "\n 4. Tong hoc bong cap cho cac sinh vien. ";
        cout << "\n 5. DTB cua cac SVCQ duoc cap hoc bong.";
        cout << "\n 6. Danh sach SVLT co DTB tu 9 tro len va khong nghi buoi nao. ";
        cout << "\n 7. Danh sach SVCQ co DTB cao nhat. ";
        cout << "\n 8. Danh sach sinh vien tang dan (theo ma so). ";
        cout << "\n 9. Them sinh vien. ";
        cout << "\n10. Xoa sinh vien. ";
        cout << "\n11. Tim kiem sinh vien. ";
        do
        {
            cout << "\nBan chon: "; cin >> choosen;
            if (choosen < 0 || choosen > 11)
                cout << "\nVui long nhap dung lua chon !";
        } while (choosen < 0 || choosen > 11);
        switch (choosen)
        {
        case 0:     // Thoat chuong trinh
            return 0;
        case 1:     //Danh sachs cac sinh vien va hoc bong tuong ung
            list.listStudentWithScholarShip();
            break;
        case 2:     //Danh sach cac SVCQ co DRL la 100
            list.listStudentThatDRLMaxScore();
            break;
        case 3:     //Thi sinh co tong diem cao nhat
            list.listStudentThatHaveNoSBV();
            break;
        case 4:
            list.totalScholarShip();
            break;
        case 5:
            list.DTBOfStudentThatHaveScholarShip();
            break;
        case 6:
            list.listSVLTHaveNoSBVAndHaveHightScore();
            break;
        case 7:
            list.listSVCQHaveDTBMaxScore();
            break;
        case 8:
            list.listStudentSortByCode();
            break;
        case 9:
            list.addStudent();
            break;
        case 10:
            list.removeStudent();
            break;
        case 11:
            break;
        default:
            break;
        }
    } while (choosen != 0);

    return 0;
}

