#include <iostream>
using namespace std;

class Shape {
public:
	virtual double Square() const = 0;
	virtual double Length() const = 0;
	virtual void Show() const = 0;
};
class Circle : public Shape {
protected:
	const double pi = 3.14159265359;
	int R;
public:
	Circle(int R) : R(R) {}

	void Show() const override
	{
		cout << "Circle: R - " << R << endl;
	}
	double Square() const override {
		return pi * pow(R, 2);
	}
	double Length() const override {
		return pi * 2 * R;
	}
};
class Rectangle : public Shape {
protected:
	int a;
	int b;
public:
	Rectangle(int _a, int _b) : a(_a), b(_b) {}

	void Show() const override {
		cout << "Rectangle: A - " << a << " B - " << b << endl;
	}
	double Square() const override {
		return a * b;
	}
	double Length() const override {
		return 2 * (a + b);
	}
};
class Right_Triangle : public Shape {
protected:
	double catet1;
	double catet2;
public:
	Right_Triangle(double c1, double c2) : catet1(c1), catet2(c2) {}

	void Show() const override {
		cout << "Right_Triangle: Catet_1 - " << catet1 << " Catet_2 - " << catet2 << " Hipotenuza - " << Hipotenuza() << endl;
	}
	double Square() const override {
		return (1.0 / 2) * catet1 * catet2;
	}
	double Hipotenuza() const {
		return sqrt(pow(catet1, 2) + pow(catet2, 2));
	}
	double Length() const {
		double h = Hipotenuza();
		return catet1 + catet2 + h;
	}
};
class Trapezoid : public Shape {
protected:
	double base_a, base_b, side, h;
public:
	Trapezoid(double ba, double bb, double s, double _h) : base_a(ba), base_b(bb), side(s), h(_h) {}

	void Show() const override {
		cout << "Trapezoid: Base_A - " << base_a << " Base_B - " << base_b << " Middle_Line - " << (base_a + base_b) / 2 << " Side - " << side << " Height - " << h << endl;
	}
	double Square() const override {
		return ((base_a + base_b) / 2) * h;
	}
	double Length() const override {
		return 2 * side + base_a + base_b;
	}
};

class Employer {
public:
	virtual void Print() const = 0;
};
class President : public Employer {
public:
	void Print() const override {
		cout << " Position - President" << endl;
	}
};
class Manager : public Employer {
public:
	void Print() const override {
		cout << " Position - Manager" << endl;
	}
};
class Worker : public Employer {
public:
	void Print() const override {
		cout << " Position - Worker" << endl;
	}
};

void Randon_Show_Positions(int n) {
	Employer** arr = new Employer * [n];
	for (int i = 0; i < n; i++) {
		int r = rand() % 3;
		switch (r) {
		case 0:
			arr[i] = new President;
			break;

		case 1:
			arr[i] = new Manager;
			break;

		case 2:
			arr[i] = new Worker;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		arr[i]->Print();
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete[] arr;
}
void Randon_Show_Shapes(int n) {
	Shape** arr = new Shape * [n];
	for (int i = 0; i < n; i++) {
		int r = rand() % 4;
		switch (r) {
		case 0:
			arr[i] = new Circle(12);
			break;

		case 1:
			arr[i] = new Rectangle(5, 7);
			break;

		case 2:
			arr[i] = new Right_Triangle(3, 4);
			break;

		case 3:
			arr[i] = new Trapezoid(4, 7, 5, 6);
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		arr[i]->Show();
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	delete[] arr;
}
int main()
{
	//Завдання 1
	{
		cout << "+====================================+" << endl;
		Randon_Show_Positions(10);
		cout << "+====================================+" << endl << endl << endl;
	}
	//Завдання 2
	{
		cout << "+====================================+" << endl;
		Randon_Show_Shapes(10);
		cout << "+====================================+" << endl << endl << endl;
	}
	return 0;
}
