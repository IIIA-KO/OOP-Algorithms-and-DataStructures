#include "Date.h"

bool Date::Leap(int year) const {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400);
}

int Date::maxday()
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Leap(year))days[1] = 29;
	return days[month - 1];
}

Date Date::Add_Days(int add_days) {
	if (day + add_days > maxday()) {
		add_days -= maxday() - day;
		if (++month > 12) {
			month = 1;
			year++;
		}
		while (add_days / maxday()) {
			if (++month > 12) {
				month = 1;
				year++;
			}
			add_days -= maxday();
		}
		day = add_days;
	}
	else day += add_days;
	return *this;
}

Date Date::Subtract_Days(int sub_days) {
	if (day - sub_days < 1) {
		sub_days -= day;
		if (--month == 0) {
			month = 12;
			year--;
		}
		while (sub_days / maxday()) {
			sub_days -= maxday();
			if (--month == 0) {
				month = 12;
				year--;
			}
		}
		day = maxday() - sub_days;
	}
	else day -= sub_days;
	return *this;
}

void Date::Add_Day() {
	this->Add_Days(1);
}

void Date::Subtruct_Day() {
	this->Subtract_Days(1);
}

Date::Date() {
	day = 1;
	month = 1;
	year = 1;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

Date::Date(const Date& date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

void Date::setDay(int d) {
	day = d;
}

void Date::setMonth(int m) {
	month = m;
}

void Date::setYear(int y) {
	year = y;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

int Date::rdn(int y, int m, int d) {
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

bool Date::check_date(int day, int month, int year) {
	if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) return false;
}

int Date::difference(const Date& d) {
	return rdn(this->year, this->month, this->day) > rdn(d.year, d.month, d.day) ? rdn(this->year, this->month, this->day) - rdn(d.year, d.month, d.day) : rdn(d.year, d.month, d.day) - rdn(this->year, this->month, this->day);
}

void Date::Show_Date() const {
	cout << day << ". " << month << ". " << year << endl;
}

void Date::Input_Date() {
	cout << "Enter day of Date: "; cin >> day;
	cout << "Enter month of Date: "; cin >> month;
	cout << "Enter year of Date: "; cin >> year;
}

Date& Date::operator=(const Date& D) {
	if (this != &D) {
		day = D.day;
		month = D.month;
		year = D.year;
	}
	return *this;
}

int Date::operator()(int i) const {
	switch (i)
	{
	case 0:
		return day;
		break;
	case 1:
		return month;
		break;
	case 2:
		return year;
		break;
	default:
		cout << "Error index" << endl;
		exit(-1);
	}
}

bool Date::operator!=(const Date& D) {
	return day != D.day && month != D.month && year != D.year;
}

bool Date::operator==(const Date& D) {
	return day == D.day && month == D.month && year == D.year;
}

bool Date::operator>(const Date& D) {
	if (rdn(year, month, day) > rdn(D.year, D.month, D.day))
		return 1;
	else return 0;
}

bool Date::operator<(const Date& D) {
	if (rdn(year, month, day) < rdn(D.year, D.month, D.day))
		return 1;
	else return 0;
}

Date& Date::operator+=(int d) {
	this->Add_Days(d);
	return *this;
}
Date& Date::operator-=(int d) {
	this->Subtract_Days(d);
	return *this;
}

Date& Date::operator++() {
	this->Add_Day();
	return *this;
}

Date& Date::operator--() {
	this->Subtruct_Day();
	return *this;
}

Date Date::operator++(int) {
	Date tmp(*this);
	this->Add_Day();
	return tmp;
}

Date Date::operator--(int) {
	Date tmp(*this);
	this->Subtruct_Day();
	return tmp;
}

ostream& operator<<(ostream& out, const Date& D) {
	D.Show_Date();
	return out;
}

istream& operator>>(istream& in, Date& D) {
	D.Input_Date();
	return in;
}