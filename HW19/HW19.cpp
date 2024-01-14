#include <iostream>
using namespace std;

class Circle {
protected:
	int R;
public:
	const double pi = 3.14159265359;
	Circle(int R);
	void Show() const;
	double Length() const;
	double Square() const;
};
Circle::Circle(int R) : R(R) {}
void Circle::Show() const
{
	cout << "R - " << R << " ";
}
double Circle::Length() const
{
	return pi * 2 * R;
}
double Circle::Square() const
{
	return pi * pow(R, 2);
}

class Kvadrat
{
protected:
	int a;
public:
	Kvadrat(int _a);
	void Show() const;
	double Square() const;
	int Length() const;
};
Kvadrat::Kvadrat(int _a) : a(_a){}
void Kvadrat::Show() const
{
	cout << "Side - " << a << endl;
}
double Kvadrat::Square() const
{
	return a * a;
}
int Kvadrat::Length() const
{
	return 4 * a;
}

class Circle_in_Square : public Circle, public Kvadrat
{
public:
	Circle_in_Square(int R);
	double Square_k() const;
	double Square_c() const;
	double Square_diff() const;
	void Show() const;
};
Circle_in_Square::Circle_in_Square(int R) : Circle(R), Kvadrat(R * 2)
{}
double Circle_in_Square::Square_k() const
{
	return Kvadrat::Square();
}
double Circle_in_Square::Square_c() const
{
	return Circle::Square();
}
double Circle_in_Square::Square_diff() const
{
	double dif = Square_k() - Square_c();
	if (dif > 0) return dif;
	else
		cout << "Wrong variables" << endl;
}
void Circle_in_Square::Show() const
{
	Circle::Show();
	Kvadrat::Show();
}




class Wheels
{
protected:
	double size;
public:
	Wheels(double s);
	void Show() const {
		cout << "Wheel's size: " << size << endl;
	}
};
Wheels::Wheels(double s) : size(s) {}

class Motor
{
protected:
	double capacity;
	int horse_powers;
	string gas_type;
public:
	Motor(double c, int hp, string gt);
	void Show() const {
		cout << "Capacity: " << capacity << endl;
		cout << "Horse powers: " << horse_powers << endl;
		cout << "Gas type: " << gas_type << endl;
	}
};
Motor::Motor(double c, int hp, string gt) :capacity(c), horse_powers(hp), gas_type(gt) {}

class Doors
{
protected:
	int quantity;
	double Size;
public:
	Doors(int q, double s);
	void Show() const {
		cout << "Door quantity: " << quantity << endl;
		cout << "Door quantity: " <<  Size << endl;
	}
};
Doors::Doors(int q, double s) :quantity(q), Size(s) {}

class Car : public Wheels, public Doors, public Motor
{
protected:
	string mark;
	string color;
	double speed;
public:
	Car(string m, string col, double sp, double size, double capacity, int horse_powes, string gas_type, int quantity, double Size);
	void Show() const;
};
Car::Car(string m, string col, double sp, double size, double capacity, int horse_powers, string gas_type, int quantity, double Size) :
	Wheels(size), Doors(quantity, Size), Motor(capacity, horse_powers, gas_type)
{
	mark = m;
	color = col;
	speed = sp;
}
void Car::Show() const
{
	cout << "Mark: " << mark << endl;
	cout << "Color: " << color << endl;
	cout << "Speed: " << speed << endl;
	Wheels::Show();
	Doors::Show();
	Motor::Show();
}

int main()
{
	//Завдання 1
	{
		cout << "-----------INSCRIBED CIRCLE-----------" << endl;
		Circle_in_Square a(15);
		a.Show();
		cout << "Square Kvadrat: " << a.Square_k() << endl;
		cout << "Square Circle: " << a.Square_c() << endl;
		cout << "Difference of squares: " << a.Square_diff() << endl;
	}

	//Завдання 2
	{
		cout << "-----------CAR-----------" << endl;
		string mark = "Audi";
		string color = "White";
		string gas_type = "Solyara";

		Car a(mark, color, 180, 35, 6, 200, gas_type, 4, 200);
		a.Show();
	}
	return 0;
}