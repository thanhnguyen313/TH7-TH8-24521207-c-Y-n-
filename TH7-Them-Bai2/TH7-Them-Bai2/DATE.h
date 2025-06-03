#pragma once
#include <iostream>
using namespace std;
class DATE
{
private:
	int iDay, iMonth, iYear;
public:
	void Input();
	void Output();
	void NextDay();
	friend istream& operator>>(istream& is, DATE& date);
	friend ostream& operator<<(ostream& os, const DATE& date);
	bool checkDays(const DATE& date);
	int getDays();
};

