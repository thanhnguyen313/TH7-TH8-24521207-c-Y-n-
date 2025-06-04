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
	cout << "\nNhap danh sach sinh vien: \n";
	for (int i = 0; i < n; i++)
	{
		int type; cout << "\nSinh vien (1. SVCQ; 2. SVLT):  "; cin >> type;
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
	cout << "\nDanh sach sinh vien nhan hoc bong la ";
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->scholarShip();
		if(list[i]->getScholarShip() != 0)
			list[i]->OutputCommon();
	}
}
void ListStudent::listStudentThatDRLMaxScore()
{
	cout << "\nDanh sach SVCQ co DRL la 100 ";
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->type)
		{
			SVCQ* sv = dynamic_cast<SVCQ*>(list[i]);
			if (sv->getDRL() == 100)
				cout << list[i]->getName();
		}
	}
}
void ListStudent::listStudentThatHaveNoSBV()
{
	cout << "\nDanh sach SVLT co SBV la 0 ";
	for (int i = 0; i < list.size(); i++)
	{
		if(!list[i]->type)
		{
			SVLT* sv = dynamic_cast<SVLT*>(list[i]);
			if (sv->getSBV() == 0)
				cout << list[i]->getName();
		}
	}
}
void ListStudent::totalScholarShip()
{
	int total = 0;
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->scholarShip();
		total += list[i]->getScholarShip();
	}
	cout << "\nTong hoc bong cap cho cac sinh vien: " << total;
}
void ListStudent::DTBOfStudentThatHaveScholarShip()
{
	cout << "\nDTB cua cac sinh vien dat hoc bong la ";
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->scholarShip();
		if (list[i]->getScholarShip() != 0)
			cout << list[i]->getName() << ": " << list[i]->DTB();
	}
}
void ListStudent::listSVLTHaveNoSBVAndHaveHightScore()
{
	cout << "\nDanh sach SVLT co SBV la 0 va DTB >= 9 ";
	for (int i = 0; i < list.size(); i++)
	{
		if (!list[i]->type)
		{
			SVLT* sv = dynamic_cast<SVLT*>(list[i]);
			if (sv->getSBV() == 0 && sv->DTB() >= 9)
				cout << sv->getName();
		}
	}
}
void ListStudent::listSVCQHaveDTBMaxScore()
{
	float maxScore = 0;
	for (int i = 0; i < list.size(); i++)
		if (maxScore < list[i]->DTB()) maxScore = list[i]->DTB();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->type)
		{
			SVCQ* sv = dynamic_cast<SVCQ*>(list[i]);
			if (sv->DTB() == maxScore)
				cout << sv->getName();
		}
	}
}
void ListStudent::swap(STUDENT*& a, STUDENT*& b)
{
	STUDENT* temp;
	temp = b;
	b = a;
	a = temp;
}
int ListStudent::partition(int low, int high)
{
	STUDENT* pivot = list[high];
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (list[j]->getCode() < pivot->getCode())
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[high]);
	return i + 1;
}
void ListStudent::quickSort(int low, int high)
{
	if (low < high)
	{
		int pivot = partition(low, high);

		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}
void ListStudent::quickSort()
{
	quickSort(0, list.size() - 1);
}
void ListStudent::listStudentSortByCode()
{
	quickSort();
	cout << "\nDanh sach sinh vien sap xep tang dan theo MSSV la: ";
	for (int i = 0; i < list.size(); i++)
	{
		cout << endl << list[i]->getCode() << ". " << list[i]->getName();
	}
}
void ListStudent::addStudent()
{
	int type; cout << "\nSinh vien (1. SVCQ; 2. SVLT):  "; cin >> type;
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
void ListStudent::removeStudent()
{
	int code; cout << "\nNhap MSSV cua sinh vien can xoa: "; cin >> code;
	bool found = false;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		if ((*it)->getCode() == code)
		{
			delete* it;             
			list.erase(it);          
			found = true;
			cout << "Da xoa sinh vien co MSSV: " << code << endl;
			break;
		}
	}
	if (!found)
		cout << "Khong tim thay sinh vien co MSSV: " << code << endl;
}
void ListStudent::findStudentByCode()
{
	int code; cout << "\nNhap MSSV cua sinh vien can tim: "; cin >> code;
	bool found = false;
	for (auto sv : list)
	{
		if (sv->getCode() == code)
		{
			sv->OutputCommon();
			found = true;
			break; 
		}
	}
	if (!found)
		cout << "Khong tim thay sinh vien co MSSV: " << code << endl;
}
