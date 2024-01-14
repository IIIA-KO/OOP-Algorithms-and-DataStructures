#include <iostream>
#include <fstream>
using namespace std;

class Root {
protected:
	virtual void Solve_Root() = 0;
};
class Linear : public Root {
private:
	int a;
	int b;
public:
	Linear(int _a, int _b) : a(_a), b(_b) {}
	void Solve_Root() {
		if (a != 0) {
			if (b != 0) {
				cout << "Root: " << (double)-b / a << endl;
			}
			else {
				cout << "Root: 0" << endl;
			}
		}
		else {
			if (b != 0) {
				cout << "Root: No Roots" << endl;
			}
			else {
				cout << "Root: infinite amount of roots" << endl;
			}
		}
	}
};
class Quadratic : public Root {
private:
	double a;
	double b;
	double c;
public:
	Quadratic(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
	void Discrim() {
		double x1, x2;
		double D = pow(b, 2) - (4 * a * c);
		cout << "D = " << D << endl;
		if (D > 0) {
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << "Root 1: " << x1 << endl << "Root 2: " << x2 << endl;
		}
		else if (D == 0.0) {
			x1 = (-b / (2 * a)); x2 = x1;
			cout << x1;
		}
		else {
			cout << "Root: not found" << endl;
		}
	}
	void Solve_Root() {
		if (a != 0) {
			if (b != 0) {
				if (c != 0) {
					Discrim();
				}
				else {
					Discrim();
				}
			}
			else {
				if (c != 0) {
					if (c > 0) {
						cout << "Root: not found" << endl;
					}
					else {
						Discrim();
					}
				}
				else {
					cout << "Root: 0" << endl;
				}
			}
		}
		else {
			if (b != 0) {
				if (c != 0) {
					cout << "Root: " << (double)-c / b << endl;
				}
				else {
					cout << "Root: 0" << endl;
				}
			}
			else {
				if (c != 0) {
					cout << "Root: not found" << endl;
				}
				else {
					cout << "Root: infinte amount of numbers" << endl;
				}
			}
		}
	}
};
void Task1() {
	/*Linear a(0,0);
	a.Solve_Root();*/

	Quadratic b(0, 0, 0);
	b.Solve_Root();
}


class Shape {
public:
	virtual void Show() const = 0;
	virtual double square() const = 0;
	virtual double length() const = 0;
	virtual void Save(const char* fname) const = 0;
	virtual void Load(const char* fname) = 0;
};
class Point {
protected:
	int x, y;
public:
	Point(int _x, int _y) : x(_x), y(_y) {}
	void Show() const {
		cout << "| X - " << x << " | Y - " << y << endl;
	}
};
class Square : public Shape, public Point {
protected:
	double a;
public:
	explicit Square(int _x, int _y, int _a) : a(_a), Point(_x, _y) {}

	void Show() const override {
		cout << "Square: A - " << a << " | square - " << square() << " | length - " << length(); Point::Show(); cout << endl;
	}
	double square() const override {
		return pow(a, 2);
	}
	double length() const override {
		return a * 4;
	}

	void Save(const char* fname) const override {
		ofstream fout(fname, ios::app);
		if (!fout.is_open()) {
			throw exception("file was not opened\n");
		}
		char s = 's';
		fout << s << endl;
		fout << x << endl;
		fout << y << endl;
		fout << a << endl;
		fout.close();
	}
	void Load(const char* fname) override {
		ifstream fin(fname);
		if (!fin.is_open()) {
			throw exception("file was not opened\n");
		}
		char s;
		fin >> s;
		fin >> x;
		fin >> y;
		fin >> a;
		fin.close();
	}
};
class Rectangle : public Shape, public Point {
protected:
	int a;
	int b;
public:
	Rectangle(int _x, int _y, int _a, int _b) : a(_a), b(_b), Point(_x, _y) {}

	void Show() const override {
		cout << "Rectangle: A - " << a << " | B - " << b << " | square - " << square() << " | length - " << length(); Point::Show(); cout << endl;
	}
	double square() const override {
		return a * b;
	}
	double length() const override {
		return 2 * (a + b);
	}

	void Save(const char* fname) const override {
		ofstream fout(fname, ios::app);
		if (!fout.is_open()) {
			throw exception("file was not opened\n");
		}
		char s = 'r';
		fout << s << endl;
		fout << x << endl;
		fout << y << endl;
		fout << a << endl;
		fout << b << endl;
		fout.close();
	}
	void Load(const char* fname) override {
		ifstream fin(fname);
		if (!fin.is_open()) {
			throw exception("file was not opened\n");
		}
		char s;
		fin >> s;
		fin >> x;
		fin >> y;
		fin >> a;
		fin >> b;
		fin.close();
	}
};
class Circle : public Shape, public Point {
protected:
	const double pi = 3.141592;
	int R;
public:
	explicit Circle(int _x, int _y, int R) : R(R), Point(_x, _y) {}

	void Show() const override
	{
		cout << "Circle: R - " << R << " | square - " << square() << " | length - " << length(); Point::Show(); cout << endl;
	}
	double square() const override {
		return pi * pow(R, 2);
	}
	double length() const override {
		return pi * 2 * R;
	}

	void Save(const char* fname) const override {
		ofstream fout(fname, ios::app);
		if (!fout.is_open()) {
			throw exception("file was not opened\n");
		}
		char s = 'c';
		fout << s << endl;
		fout << x << endl;
		fout << y << endl;
		fout << R << endl;
		fout.close();
	}
	void Load(const char* fname) override {
		ifstream fin(fname);
		if (!fin.is_open()) {
			throw exception("file was not opened\n");
		}
		char s;
		fin >> s;
		fin >> x;
		fin >> y;
		fin >> R;
		fin.close();
	}
};
class Ellipse : public Shape, public Point {
protected:
	const double pi = 3.141592;
	int a;
	int b;
public:
	Ellipse(int _x, int _y, int _a, int _b) : a(_a), b(_b), Point(_x, _y) {}

	void Show() const override {
		cout << "Ellipse: A - " << a << " | B - " << b << " | square - " << square() << " | length - " << length() << endl;
	}
	double square() const override {
		return pi * a * b;
	}
	double length() const override {
		return pi * (a + b);
	}

	void Save(const char* fname) const override {
		ofstream fout(fname, ios::app);
		if (!fout.is_open()) {
			throw exception("file was not opened\n");
		}
		char s = 'e';
		fout << s << endl;
		fout << x << endl;
		fout << y << endl;
		fout << a << endl;
		fout << b << endl;
		fout.close();
	}
	void Load(const char* fname) override {
		ifstream fin(fname);
		if (!fin.is_open()) {
			throw exception("file was not opened\n");
		}
		char s;
		fin >> s;
		fin >> x;
		fin >> y;
		fin >> a;
		fin >> b;
		fin.close();
	}
};
void Task2(const char* filename) {
	int n;
	cout << "Enter size of array: "; cin >> n;
	if (!n || n < 0) {
		throw exception("Wrong array size");
	}

	Shape** arr = new Shape * [n];
	for (int i = 0; i < n; i++) {
		int r = rand() % 4;
		switch (r) {
		case 0:
			arr[i] = new Circle(0, 0, 12);
			break;

		case 1:
			arr[i] = new Rectangle(0, 0, 5, 7);
			break;

		case 2:
			arr[i] = new Square(0, 0, 4);
			break;

		case 3:
			arr[i] = new Ellipse(0, 0, 7, 5);
			break;
		}
	}

	cout << "Random genereted array of shapes: " << endl << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i])
			arr[i]->Show();
	}

	for (int i = 0; i < n; i++) {
		arr[i]->Save(filename);
		delete arr[i];
		arr[i] = nullptr;
	}
	cout << "Aray was saved to file" << endl << endl;

	ifstream fin(filename);
	if (!fin.is_open()) {
		throw exception("file was not opened\n");
	}

	char type;
	int a = 0, b = 0, x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		fin >> type;
		switch (type) {
		case 's':
			fin >> x;
			fin >> y;
			fin >> a;
			arr[i] = new Square(x, y, a);
			break;

		case 'r':
			fin >> x;
			fin >> y;
			fin >> a;
			fin >> b;
			arr[i] = new Rectangle(x, y, a, b);
			break;

		case 'c':
			fin >> x;
			fin >> y;
			fin >> a;
			arr[i] = new Circle(x, y, a);
			break;

		case 'e':
			fin >> x;
			fin >> y;
			fin >> a;
			fin >> b;
			arr[i] = new Ellipse(x, y, a, b);
			break;

		default:
			throw exception("There is no such class");
		}
	}

	cout << "Copy of array read from file: " << endl << endl;
	for (int i = 0; i < n; i++) {
		if (arr[i])
			arr[i]->Show();
	}

	fin.close();

	for (int i = 0; i < n; i++)
		delete arr[i];
	delete[] arr;
	remove(filename);
}

int main()
{
	srand(time(0));
	try {
		cout << "+========================================================+" << endl;
		Task1();
		cout << "+========================================================+" << endl << endl << endl;

		/*cout << "+========================================================+" << endl;
		const char* filename = "Shapes_Array.txt";
		Task2(filename);
		cout << "+========================================================+" << endl << endl << endl;*/
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}