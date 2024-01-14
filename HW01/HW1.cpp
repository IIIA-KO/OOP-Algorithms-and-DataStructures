#include <iostream>
using namespace std;

class Fraction {
private:
	int numeral, denominator;
	void GCD() {
		int a = abs(numeral), b = abs(denominator);
		a = a ? a : 1;
		while (a != b)
		{
			if (a > b) a -= b;
			else b -= a;
		}
		numeral = numeral / a;
		denominator = denominator / a;
		if (denominator < 0) {
			numeral *= -1;
			denominator *= -1;
		}
	}
public:
	Fraction(int ch = 0, int zn = 1, int c = 0) {
		this->numeral = c * zn + ch;
		setZn(zn);
		GCD();
	}

	void setCh(int ch1) {
		numeral = ch1;
		GCD();
	}
	void setZn(int zn1) {
		if (zn1 != 0) denominator = zn1;
		else denominator = 1;
		GCD();
	}
	void Show() const {
		cout << numeral;
		if (denominator != 1) cout << "/" << denominator;
	}

	Fraction Add(const Fraction& B) {
		return Fraction(numeral * B.denominator + B.numeral * denominator, denominator * B.denominator);
	}
	Fraction Minus(const Fraction& B) {
		return Fraction(numeral * B.denominator - B.numeral * denominator, denominator * B.denominator);
	}
	Fraction Mult(const Fraction& B) {
		return Fraction(numeral * B.numeral, denominator * B.denominator);
	}
	Fraction Div(const Fraction& B) {
		return Fraction(numeral * B.denominator, denominator * B.numeral);
	}
};

int main()
{
	int n, d;
	cout << "First fraction: " << endl << "Enter numeral for 1st fraction: "; cin >> n; cout << endl;
	cout << "Enter denominator for 1st fraction: "; cin >> d;
	Fraction F1(n, d);
	cout << endl;

	cout << "Second fraction: " << endl << "Enter numeral for 2nd fraction: "; cin >> n; cout << endl;
	cout << "Enter denominator for 2nd fraction: "; cin >> d;
	Fraction F2(n, d);
	cout << endl;

	Fraction R;
	int operation;
	cout << "Enter operation" << endl << "1) - Add; 2) - Minus; 3) - Multiplication; 4) - Divide : " << endl; cin >> operation;
	switch (operation)
	{
	case 1:
		R = F1.Add(F2);
		cout << "Result: ";  R.Show();
		break;

	case 2:
		R = F1.Minus(F2);
		cout << "Result: ";  R.Show();
		break;

	case 3:
		R = F1.Mult(F2);
		cout << "Result: ";  R.Show();
		break;

	case 4:
		R = F1.Div(F2);
		cout << "Result: ";  R.Show();
		break;
	}
}