#include <iostream>
using namespace std;

class Date {
	int day, month, year;
	bool Leap(int year) const {
		return ((year % 4 == 0 && year % 100 != 0) || year % 400);
	}
	int maxday()
	{
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (Leap(year))days[1] = 29;
		return days[month - 1];
	}
	Date Add_Days(int add_days) {
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
	Date Subtract_Days(int sub_days) {
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
	void Add_Day() {
		this->Add_Days(1);
	}
	void Subtruct_Day() {
		this->Subtract_Days(1);
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

	void setDay(int d) {
		day = d;
	}
	void setMonth(int m) {
		month = m;
	}
	void setYear(int y) {
		year = y;
	}

	int rdn(int y, int m, int d) {
		if (m < 3)
			y--, m += 12;
		return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
	}
	bool check_date(int day, int month, int year) {
		if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) return false;
	}
	int difference(const Date& d) {
		return rdn(this->year, this->month, this->day) > rdn(d.year, d.month, d.day) ? rdn(this->year, this->month, this->day) - rdn(d.year, d.month, d.day) : rdn(d.year, d.month, d.day) - rdn(this->year, this->month, this->day);
	}

	void Show_Date() const {
		cout << day << ". " << month << ". " << year << endl;
	}
	void Input_Date() {
		cout << "Enter day of Date: "; cin >> day;
		cout << "Enter month of Date: "; cin >> month;
		cout << "Enter year of Date: "; cin >> year;
	}

	friend ostream& operator<<(ostream& out, const Date& D);
	friend istream& operator>>(istream& in, const Date& D);

	Date& operator=(const Date& D) {
		if (this != &D) {
			day = D.day;
			month = D.month;
			year = D.year;
		}
		return *this;
	}
	int operator()(int i) const {
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

	bool operator!=(const Date& D) {
		return day != D.day && month != D.month && year != D.year;
	}
	bool operator==(const Date& D) {
		return day == D.day && month == D.month && year == D.year;
	}
	bool operator>(const Date& D) {
		if (rdn(year, month, day) > rdn(D.year, D.month, D.day))
			return 1;
		else return 0;
	}
	bool operator<(const Date& D) {
		if (rdn(year, month, day) < rdn(D.year, D.month, D.day))
			return 1;
		else return 0;
	}

	Date& operator+=(int d) {
		this->Add_Days(d);
		return *this;
	}
	Date& operator-=(int d) {
		this->Subtract_Days(d);
		return *this;
	}

	Date& operator++() {
		this->Add_Day();
		return *this;
	}
	Date& operator--() {
		this->Subtruct_Day();
		return *this;
	}
	Date operator++(int) {
		Date tmp(*this);
		this->Add_Day();
		return tmp;
	}
	Date operator--(int) {
		Date tmp(*this);
		this->Subtruct_Day();
		return tmp;
	}
};
ostream& operator<<(ostream& out, const Date& D) {
	D.Show_Date();
	return out;
}
istream& operator>>(istream& in, Date& D) {
	D.Input_Date();
	return in;
}

int main() {
	Date A(23, 12, 2015), B(28, 02, 2020);

	cout << ++B << endl;			//29.2.2020

	cout << "A: " << A << "B: " << B;
	cout << "+======================================================+" << endl;
	cout << "A != B" << endl;
	cout << "Result: " << (A != B) << endl << endl;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A == B" << endl;
	cout << "Result: " << (A == B) << endl << endl;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A > B" << endl;
	cout << "Result: " << (A > B) << endl << endl;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A < B" << endl;
	cout << "Result: " << (A < B) << endl << endl;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A <<" << endl;
	cout << A;
	cout << "B <<" << endl;
	cout << B;
	cout << "+======================================================+" << endl << endl << endl;


	cout << "+======================================================+" << endl;
	cout << "A >>" << endl;
	cin >> A;
	cout << "B >>" << endl;
	cin >> B;
	cout << "A: " << A << endl << "B: " << B;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "C = A" << endl;
	Date C;
	cout << "C: " << C << endl;
	cout << "A: " << A << endl;
	C = A;
	cout << "C: " << C << endl;
	cout << "A: " << A << endl;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A(i) 0 <= i <= 2"<< endl;
	int i;
	cout << "Enter i: "; cin >> i;
	cout << "Result" << A(i) << endl;
	cout << "+======================================================+" << endl << endl << endl;


	cout << "+======================================================+" << endl;
	cout << "A: " << A;
	int days = 0;
	cout << "Enter amount of days you want to add: "; cin >> days;
	cout << "A += days" << endl;
	A += days;
	cout << "A: " << A << endl;

	cout << "Enter amount of days you want to subtract: "; cin >> days;
	cout << "A: " << A;
	cout << "A -= days" << endl;
	A -= days;
	cout << "A: " << A;
	cout << "+======================================================+" << endl << endl << endl;


	Date D;
	cout << "+======================================================+" << endl;
	cout << "B: " << B << "D: " << D;
	cout << "D = ++B" << endl;
	D = ++B;
	cout << "D: " << D << "B: " << B;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "B: " << B << "D: " << D;
	cout << "D = --B" << endl;
	D = --B;
	cout << "D: " << D << "B: " << B;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A: " << A << "D: " << D;
	cout << "D = A++" << endl;
	D = A++;
	cout << "D: " << D << "A: " << A;
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "A: " << A << "D: " << D;
	cout << "D = A--" << endl;
	D = A--;
	cout << "D: " << D << "A: " << A;
	cout << "+======================================================+" << endl << endl << endl;
	return 0;
}