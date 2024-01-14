#include <iostream>
using namespace std;

class Date {
	int day, month, year;
	bool Leap(int year) const {
		bool leap = false;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			leap = true;
		}
		else {
			leap = false;
		}
		return leap;
	}
	int rdn(int y, int m, int d) {
		if (m < 3)
			y--, m += 12;
		return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
	}
public:
	Date() {
		day = 1;
		month = 1;
		year = 1;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}
	Date(const Date& date) {
		day = date.day;
		month = date.month;
		year = date.year;
	}

	bool check_date(int day, int month, int year) {
		if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) return false;
	}

	int difference(const Date& d) {
		return rdn(this->year, this->month, this->day) > rdn(d.year, d.month, d.day) ? rdn(this->year, this->month, this->day) - rdn(d.year, d.month, d.day) : rdn(d.year, d.month, d.day) - rdn(this->year, this->month, this->day);
	}
	Date Add_Days(int add_days) {
		int monthdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int addyears, leftoverdays;
		addyears = add_days / 365;
		leftoverdays = add_days % 365;
		year += addyears;

		for (int i = 0; i <= leftoverdays; i++)
			if (day < monthdays[month - 1])
				day++;
			else if ((day == monthdays[month - 1]) && (month < 12))
			{
				day = 1;
				month++;
			}
			else if ((day == monthdays[month - 1]) && (month == 12))
			{
				day = 1;
				month = 1;
				year++;
			}
		return *this;
	}
	void Show_Date() const {
		cout << day << ". " << month << ". " << year << endl;
	}
};

class String {
	char* str;
	static int count;
public:
	~String() {
		delete[] str;
		count--;
	}
	String(int capacity) {
		str = new char[capacity + 1];
		count++;
	}
	String(const char* string) {
		str = _strdup(string);
		count++;
	}
	String() : String(81){}
	String(const String& s) : String(s.str){}

	void Show_Str() const {
		cout << str << endl;
	}
	void Input_Str() {
		delete[] str;
		char string[81];
		cin >> string;
		str = _strdup(string);
	}
	static void Show_count() {
		cout << "Created objects: " << count << endl;
	}

	String& operator=(const String& string)
	{
		if (this == &string)
			return *this;
		delete[] str;
		str = _strdup(string.str);
		return *this;
	}
	String operator*(const String& str2){
		int l = 1;
		int len = strlen(str) + 1;
		int len2 = strlen(str2.str) + 1;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len2; j++)
				if (str[i] == str2.str[i])
					l++;

		char* str3 = new char[l + 2];
		str3[0] = '\0';

		for (int i = 0; i < len; i++)
			for (int j = 0; j < len2; j++)
				if (str[i] == str2.str[j])
					strncat(str3, &str[i], 1);

		String tmp(str3);
		return tmp;
	}
};
int String::count = 0;

int main()
{
	//Date
	{
		cout << "+=========================================================================================+" << endl;
		cout << "The program takes two dates and determines the difference between them in days" << endl;
		int year, month, day, difference = 0;

		cout << "Enter the year of first date: "; cin >> year;
		cout << "Enter the month of first date: "; cin >> month;
		cout << "Enter the day of first date: "; cin >> day;
		Date date1(day, month, year);
		if (!date1.check_date(day, month, year)) {
			cout << "Error: wrongly entered date" << endl;
			return 1;
			cout << "+=========================================================================================+" << endl << endl << endl;
		}

		cout << "Enter the year of second date: "; cin >> year;
		cout << "Enter the month of second date: "; cin >> month;
		cout << "Enter the day of second date: "; cin >> day;
		Date date2(day, month, year);
		if (!date2.check_date(day, month, year)) {
			cout << "Error: wrongly entered date" << endl;
			return 1;
			cout << "+=========================================================================================+" << endl << endl << endl;
		}

		difference = date1.difference(date2);
		cout << "Difference: " << difference << endl;

		cout << "Enter the year of third date: "; cin >> year;
		cout << "Enter the month of third date: "; cin >> month;
		cout << "Enter the day of third date: "; cin >> day;
		Date date3(day, month, year);
		if (!date3.check_date(day, month, year)) {
			cout << "Error: wrongly entered date" << endl;
			return 1;
			cout << "+=========================================================================================+" << endl << endl << endl;
		}
		int add_days = 0;
		cout << "Enter count of days you want to add to third date (more than 0): "; cin >> add_days;
		if (add_days < 0) {
			cout << "Wrong number" << endl;
			return 1;
			cout << "+=========================================================================================+" << endl << endl << endl;
		}
		date3.Add_Days(add_days);
		cout << "Result date: "; date3.Show_Date();
		cout << "+=========================================================================================+" << endl << endl << endl;
	}

	//String
	{
		String str1, str2;
		cout << "Enter first string: "; str1.Input_Str();
		cout << "Enter second string: "; str2.Input_Str();

		String str3;
		str3 = str1 * str2;
		cout << "Intersection: "; str3.Show_Str();
	}
	return 0;
}