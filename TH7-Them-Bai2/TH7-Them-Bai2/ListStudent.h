#pragma once
#include "STUDENT.h"
#include <vector>

class ListStudent
{
private:
	vector<STUDENT*> list;
public:
	void listStudentInput();
	// option 1.
	void listStudentWithScholarShip();
	// option 2.
	void listStudentThatDRLMaxScore();
	// option 3.
	void listStudentThatHaveNoSBV();
	// option 4.
	void totalScholarShip();
	// option 5
	void DTBOfStudentThatHaveScholarShip();
	// option 6
	void listSVLTHaveNoSBVAndHaveHightScore();
	// option 7
	void listSVCQHaveDTBMaxScore();
	// option 8.
	int partition(int low, int high);
	void quickSort(int low, int high);
	void quickSort();
	void listStudentSortByCode();
	void swap(STUDENT*& a, STUDENT*& b);
	// option 9.
	void addStudent();
	// option 10.
	void removeStudent();
	//// option 11.
	void findStudentByCode();
};



