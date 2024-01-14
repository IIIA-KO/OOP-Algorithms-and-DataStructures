#include <iostream>
#include <iomanip>
#include <chrono>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
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

	int getDay() const {
		return day;
	}
	int getMonth()const {
		return month;
	}
	int getYear()const {
		return year;
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
	int rdn() {
		if (this->month < 3)
			this->year--, this->month += 12;
		return 365 * this->year + this->year / 4 - this->year / 100 + this->year / 400 + (153 * this->month - 457) / 5 + this->day - 306;
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
	bool operator>=(const Date& D) {
		if (rdn(year, month, day) >= rdn(D.year, D.month, D.day))
			return 1;
		else return 0;
	}
	bool operator<=(const Date& D) {
		if (rdn(year, month, day) <= rdn(D.year, D.month, D.day))
			return 1;
		else return 0;
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
};
ostream& operator<<(ostream& out, const Date& D) {
	D.Show_Date();
	return out;
}
istream& operator>>(istream& in, Date& D) {
	D.Input_Date();
	return in;
}

class product {
private:
	string name;
	double weight, price;
	int shelf_life;
	Date date;
public:
	product(string n, double w, double p, int sl, int d, int m, int y) : name(n), price(p), weight(w), shelf_life(sl), date(d, m, y) {}
	product(string n, double w, double p, int sl, Date d) : name(n), price(p), weight(w), shelf_life(sl), date(d) {}

	string getName() const { return name; }
	double getWeight() const { return weight; }
	double getPrice() const { return price; }
	int getShelfLife() const { return shelf_life; }
	int getDay() const { return date.getDay(); }
	int getMonth() const { return date.getMonth(); }
	int getYear() const { return date.getYear(); }
	Date getDate() const { return date; }

	void setName(string n) { name = n; }
	void setWeight(double w) { weight = w; }
	void setPrice(double p) { price = p; }
	void setShelfLife(int sl) { shelf_life = sl; }
	void setDay(int d) { date.setDay(d); }
	void setMonth(int m) { date.setMonth(m); }
	void setYear(int y) { date.setYear(y); }

	void Show() const {
		cout << setw(20) << name << " | " << setw(8) << weight << " | " << setw(6) << price << " | " << setw(4) << shelf_life << " | " << setw(11) << date.getDay() << "." << date.getMonth() << "." << date.getYear() << " |" << endl;
	}
};
ostream& operator<<(ostream& out, const product& p) {
	p.Show();
	return out;
}
struct CMP {
	bool operator()(const product& a, const product& b) const {
		return strcoll(a.getName().c_str(), b.getName().c_str()) > 0;
	}
};

template <class value_type, class container_type, class functor>
ostream& operator<<(ostream& out, priority_queue<value_type, container_type, functor> arr) {
	while (!arr.empty()) {
		cout << arr.top();
		arr.pop();
	}
	out << endl;
	return out;
}


void WriteProducts(const string& fname, priority_queue<product, vector<product>, CMP> arr) {
	ofstream fout(fname);
	if (!fout.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	fout << arr.size() << endl;
	while (!arr.empty()) {
		fout << arr.top().getName() << endl;
		fout << arr.top().getWeight() << endl;
		fout << arr.top().getPrice() << endl;
		fout << arr.top().getShelfLife() << endl;
		fout << arr.top().getDay() << endl;
		fout << arr.top().getMonth() << endl;
		fout << arr.top().getYear() << endl;
		arr.pop();
	}
	fout.close();
}

Date CurrentDate() {
	auto start = chrono::system_clock::now();
	auto end = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(end);
	tm* local_time = localtime(&end_time);
	int local_day = local_time->tm_mday;
	int local_month = local_time->tm_mon + 1;
	int local_year = local_time->tm_year + 1900;

	return { local_day, local_month, local_year };
}

void SeparateProduts(Date current_date, const string& overdue_file, const string& promotion_file, priority_queue<product, vector<product>, CMP> products) {
	while (!products.empty()) {
		product tmp = products.top();
		if (current_date.rdn()	>=	(tmp.getDate().rdn() + tmp.getShelfLife()) ) {
			ofstream fout(overdue_file, ios::app);
			if (!fout.is_open()) {
				throw exception("ERROR: File was not opened");
			}
			fout << products.top().getName() << endl;
			fout << products.top().getWeight() << endl;
			fout << products.top().getPrice() << endl;
			fout << products.top().getShelfLife() << endl;
			fout << products.top().getDay() << endl;
			fout << products.top().getMonth() << endl;
			fout << products.top().getYear() << endl;
			fout.close();
		}
		else if (current_date.rdn() + 2 == (tmp.getDate().rdn() + tmp.getShelfLife()) ) {
			ofstream fout(promotion_file, ios::app);
			if (!fout.is_open()) {
				throw exception("ERROR: File was not opened");
			}
			fout << products.top().getName() << endl;
			fout << products.top().getWeight() << endl;
			fout << (products.top().getPrice() * 0.55) << endl;
			fout << products.top().getShelfLife() << endl;
			fout << products.top().getDay() << endl;
			fout << products.top().getMonth() << endl;
			fout << products.top().getYear() << endl;
			fout.close();
		}
		products.pop();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	Date current_date = CurrentDate();

	product p1("Сир",		100, 25, 2,	current_date.getDay(), current_date.getMonth(), current_date.getYear());		//Акція
	product p2("Помідори",	100, 15, -10,	current_date.getDay(), current_date.getMonth(), current_date.getYear());	//Списано
	product p3("Салат",		100, 20, -1,	current_date.getDay(), current_date.getMonth(), current_date.getYear());	//Списано
	product p4("Морква",	100, 10, 2,	current_date.getDay(), current_date.getMonth(), current_date.getYear());		//Акція
	product p5("Картопля",	100, 12, 15,	current_date.getDay(), current_date.getMonth(), current_date.getYear());

	priority_queue<product, vector<product>, CMP> products;
	products.emplace(p1);
	products.emplace(p2);
	products.emplace(p3);
	products.emplace(p4);
	products.emplace(p5);
	cout << "Список продуктів: " << endl << products << endl;

	string fname = "Продукти.txt", promotion_file = "Акція.txt", overdue_file = "Списано ";
	string d = to_string(current_date.getDay());
	overdue_file += d;
	overdue_file += ".";
	string m = to_string(current_date.getMonth());
	overdue_file += m;
	overdue_file += ".";
	string y = to_string(current_date.getYear());
	overdue_file += y;
	overdue_file += ".txt";

	WriteProducts(fname, products);

	SeparateProduts(current_date, overdue_file, promotion_file, products);

	return 0;
}