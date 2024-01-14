#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int day, month, year;

	bool Leap(int year) const;

	int maxday();

	Date Add_Days(int add_days);

	Date Subtract_Days(int sub_days);

	void Add_Day();

	void Subtruct_Day();
public:
	Date();

	Date(int d, int m, int y);

	Date(const Date& date);

	void setDay(int d);

	void setMonth(int m);

	void setYear(int y);

	int getDay() const;

	int getMonth() const;

	int getYear() const;

	int rdn(int y, int m, int d);

	bool check_date(int day, int month, int year);

	int difference(const Date& d);

	void Show_Date() const;

	void Input_Date();

	friend ostream& operator<<(ostream& out, const Date& D);

	friend istream& operator>>(istream& in, const Date& D);

	Date& operator=(const Date& D);

	int operator()(int i) const;

	bool operator!=(const Date& D);

	bool operator==(const Date& D);

	bool operator>(const Date& D);

	bool operator<(const Date& D);

	Date& operator+=(int d);

	Date& operator-=(int d);

	Date& operator++();

	Date& operator--();

	Date operator++(int);

	Date operator--(int);
};