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

	Fraction operator+ (const Fraction& B)const {
		return Fraction(numeral * B.denominator + B.numeral * denominator, denominator * B.denominator);
	}
	Fraction operator-(const Fraction& B)const {
		return Fraction(numeral * B.denominator - B.numeral * denominator, denominator * B.denominator);
	}
	Fraction operator*(const Fraction& B)const {
		return Fraction(numeral * B.numeral, denominator * B.denominator);
	}
	Fraction operator/(const Fraction& B)const {
		return Fraction(numeral * B.denominator, denominator * B.numeral);
	}
};

class Complex {
	double R;
	double I;
public:
	Complex(double r, double i) {
		R = r;
		I = i;
	}
	Complex() {
		R = 0;
		I = 0;
	}

	void Show() const {
		if (I > 0)
			cout << R << " +" << I << "*i" << endl;
		else cout << R << " " << I << "*i" << endl;
	}

	Complex operator+ (const Complex& b) const {
		return Complex(R + b.R, I + b.I);
	}
	Complex operator- (const Complex& b) {
		return Complex(R - b.R, I - b.I);
	}
	Complex operator* (const Complex& b) {
		return Complex((R * b.R) - (I * b.I), (R * b.I) + (I * b.R));
	}

	Complex operator/(const Complex& b) {
		return Complex((R * b.R + I * b.I) / (b.R * b.R + b.I * b.I), (I * b.R - b.I * R) / (b.R * b.R + b.I * b.I));
	}
};

int main()
{
	{
		cout << "Fractions: " << endl;
		int an, ad, bn, bd;

		cout << "Enter numeral for fraction A: "; cin >> an; cout << endl;
		cout << "Enter denominator for fraction A: "; cin >> ad; cout << endl;
		cout << "Enter numeral for fraction B: "; cin >> bn; cout << endl;
		cout << "Enter denominator for fraction b: "; cin >> bd; cout << endl;

		Fraction A(an, ad);
		Fraction B(bn, bd);
		Fraction C = A + B;

		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A + B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A - B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A - B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A * B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A * B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A / B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A / B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
	}

	{
		cout << "Complex: " << endl;
		double ar, ai, br, bi;

		cout << "Enter Realparty for Complex A: "; cin >> ar; cout << endl;
		cout << "Enter Imaginarypart for Complex A: "; cin >> ai; cout << endl;
		cout << "Enter Realparty for Complex B: "; cin >> br; cout << endl;
		cout << "Enter Imaginarypart for Complex b: "; cin >> bi; cout << endl;

		Complex A(ar, ai);
		Complex B(br, bi);
		Complex C = A + B;

		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A + B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A - B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A - B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A * B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A * B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
		C = A / B;
		cout << "A: "; A.Show(); cout << endl;
		cout << "B: "; B.Show(); cout << endl;
		cout << "C = A / B: "; C.Show(); cout << endl;
		cout << "+===========================================================================+" << endl;
	}
	return 0;
}
