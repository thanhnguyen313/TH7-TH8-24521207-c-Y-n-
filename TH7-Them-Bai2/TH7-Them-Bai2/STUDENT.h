#pragma once
#include <iostream>
#include <string>
#include "DATE.h"
using namespace std;

class STUDENT
{
private:
	string name;
	int code;
	DATE dateOfBirth;
	float mathScore;
	float literatureScore;
	float englishScore;
	string deparment;
	float sum;
	int scholarShipMoney;
public:
	void InputCommon();
	void OutputCommon();
	virtual void Input() = 0;
	bool type = true;
	bool isValidName(const string& name);
	void standardizeNames(string& str);
	STUDENT& operator=(const STUDENT& otherStudent);
	string getName();
	float getSum();
	int getScholarShip();
	float DTB();
	void setScholarShip(int price);
	virtual void scholarShip() = 0;
	int getCode();
};

class SVCQ : public STUDENT 
{
private:
	int DRL;
public:
	SVCQ() { this->type = true; } // type true la SVCQ, false la SVLT
	void Input() override;
	void scholarShip() override;
	int getDRL() { return DRL; }
};

class SVLT : public STUDENT 
{
private:
	int SBV;
public:
	SVLT() { this->type = false; } // type true la SVCQ, false la SVLT
	void Input() override;
	void scholarShip() override;
	int getSBV() { return SBV; }
};
