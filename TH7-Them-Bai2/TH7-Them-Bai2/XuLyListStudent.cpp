#include "ListStudent.h"
#include "STUDENT.h"
#pragma once

void ListStudent::listStudentInput()
{
	int n;
	do
	{
		cout << "\nNhap so luong sinh vien: "; cin >> n;
		if (n < 0)
			cout << "\nVui long nhap so luong hop le !";
	} while (n < 0);
	list.resize(n);
	cout << "\nNhap danh sach sinh vien: \n";
	for (int i = 0; i < n; i++)
	{
		int type; cout << "\nSinh viên (1. SVCQ; 2. SVLT):  "; cin >> type;
		STUDENT* sv = nullptr;
		if (type == 1)
			sv = new SVCQ();
		else if (type == 2)
			sv = new SVLT();
		if (sv)
		{
			sv->Input();
			list.push_back(sv);
		}
	}
}
void ListStudent::listStudentWithScholarShip()
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->type)
			list[i]->scholarShip();
		else
		list[i]->OutputCommon();
	}
}
//void ListStudent::swap(STUDENT& a, STUDENT& b)
//{
//	STUDENT temp;
//	temp = b;
//	b = a;
//	a = temp;
//}
//int ListStudent::partitionDecrease(int low, int high)
//{
//	STUDENT pivot = list[high];
//	int i = low - 1;
//	for (int j = low; j < high; j++)
//	{
//		if (list[j].getSum() > pivot.getSum())
//		{
//			i++;
//			swap(list[i], list[j]);
//		}
//	}
//	swap(list[i + 1], list[high]);
//	return i + 1;
//}
//void ListStudent::quickSortDecrease(int low, int high)
//{
//	if (low < high)
//	{
//		int pivot = partitionDecrease(low, high);
//
//		quickSortDecrease(low, pivot - 1);
//		quickSortDecrease(pivot + 1, high);
//	}
//}
//void ListStudent::quickSortDecrease()
//{
//	quickSortDecrease(0, list.size() - 1);
//}
//void ListStudent::listStudentDecrease()
//{
//	quickSortDecrease();
//	cout << "\nDanh sach hoc sinh giam dan theo tong diem: ";
//	for (int i = 0; i < list.size(); i++)
//	{
//		cout << endl << list[i]->getName() << " " << list[i]->getSum() << " Diem.";
//	}
//}