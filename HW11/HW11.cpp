#include <iostream>
using namespace std;

template <class t>
class Matrix {
private:
	int r, c;
	t** mat_arr = NULL;
public:
	~Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& M);

	template <class t3>
	friend istream& operator>> (istream& in, const Matrix<t3>& M);
	template <class t2>
	friend ostream& operator<< (ostream& out, const Matrix<t2>& M);
	Matrix operator+(const Matrix& a);
	Matrix operator-(const Matrix& a);
	Matrix operator*(const Matrix& a);

	void SetRND(int min, int max);
	void Clear();
};
template <class t>
Matrix<t>::~Matrix() {
	Clear();
}
template <class t>
Matrix<t>::Matrix(int r, int c) {
	if (r < 1 || c < 1) {
		cout << "ERROR: Wrong value for rows or columns" << endl;
		exit(-1);
	}
	this->r = r;
	this->c = c;
	mat_arr = new t* [r];
	for (int i = 0; i < r; i++)
		mat_arr[i] = new t[c];
}
template <class t>
Matrix<t>::Matrix(const Matrix& M) {
	r = M.r;
	c = M.c;
	mat_arr = new t* [M.r];
	for (int i = 0; i < M.r; i++)
		mat_arr[i] = new t[M.c]{ 0 };

	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			mat_arr[i][j] = M.mat_arr[i][j];
		}
	}
}

template<class t>
void Matrix<t>::SetRND(int min, int max) {
	if (min > max) swap(min, max);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			mat_arr[i][j] = min + (double)(max - min) * rand() / RAND_MAX;
		}
	}
}
template<class t>
void Matrix<t>::Clear() {
	for (int i = 0; i < r; i++) {
		delete[] mat_arr[i];
	}
	delete[] mat_arr;
}

template <class t2>
istream& operator>> (istream& in, const Matrix<t2>& M) {
	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			cout << "Enter [" << i << "][" << j << "] element: "; in >> M.mat_arr[i][j];
		}
	}
	return in;
}
template <class t2>
ostream& operator<< (ostream& out, const Matrix<t2>& M) {
	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			out << M.mat_arr[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}
template <class t>
Matrix<t> Matrix<t>::operator+(const Matrix<t>& a) {
	if ((r * c) != (a.r * a.c)) {
		exit(-1);
	}
	Matrix tmp(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp.mat_arr[i][j] = mat_arr[i][j] + a.mat_arr[i][j];
		}
	}
	return tmp;
}
template <class t>
Matrix<t> Matrix<t>::operator-(const Matrix<t>& a) {
	if ((r * c) != (a.r * a.c)) {
		exit(-1);
	}
	Matrix tmp(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp.mat_arr[i][j] = mat_arr[i][j] - a.mat_arr[i][j];
		}
	}
	return tmp;
}
template <class t>
Matrix<t> Matrix<t>::operator*(const Matrix<t>& a) {
	if ((r * c) != (a.r * a.c)) {
		exit(-1);
	}
	Matrix tmp(r, c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp.mat_arr[i][j] = mat_arr[i][j] * a.mat_arr[i][j];
		}
	}
	return tmp;
}

int main()
{
	size_t ROWS = 1, COLUMNS = 1;
	//INTEGER
	{
		cout << "+============================================================================================+" << endl;
		cout << "I N T E G E R" << endl;
		cout << "Enter rows for INTEGER Matrix A: "; cin >> ROWS;
		cout << "Enter columns for INTEGER Matrix A: "; cin >> COLUMNS;
		Matrix<int>a(ROWS, COLUMNS);
		Matrix<int>b(ROWS, COLUMNS);
		b.SetRND(-12, 12);

		cout << "Enter INTEGER Matrix A: " << endl;
		cin >> a;
		cout << "Matrix A: " << endl; cout << a;

		cout << "Random generated INTEGER  Matrix B: " << endl; cout << b;

		cout << endl << "A + B" << endl << a + b << endl << "A - B" << endl << a - b << endl << "A * B" << endl << a * b << endl;
		cout << "+============================================================================================+" << endl << endl << endl;
	}
	//DOUBLE
	{
		cout << "+============================================================================================+" << endl;
		cout << "D O U B L E" << endl;
		cout << "Enter rows for DOUBLE Matrix A: "; cin >> ROWS;
		cout << "Enter columns for DOUBLE Matrix A: "; cin >> COLUMNS;
		Matrix<double>a(ROWS, COLUMNS);
		Matrix<double>b(ROWS, COLUMNS);
		b.SetRND(-12, 12);
		cout << "Enter DOUBLE Matrix A: " << endl;
		cin >> a;
		cout << "Matrix A: " << endl; cout << a;

		cout << "Random generated DOUBLE  Matrix B: " << endl; cout << b;

		cout << endl << "A + B" << endl << a + b << endl << "A - B" << endl << a - b << endl << "A * B" << endl << a * b << endl;
		cout << "+============================================================================================+" << endl << endl << endl;
	}
	//CHAR
	{
		cout << "+============================================================================================+" << endl;
		cout << "C H A R" << endl;
		cout << "Enter rows for CHAR Matrix A: "; cin >> ROWS;
		cout << "Enter columns for CHAR Matrix A: "; cin >> COLUMNS;
		Matrix<char>a(ROWS, COLUMNS);
		Matrix<char>b(ROWS, COLUMNS);
		b.SetRND(-12, 12);
		cout << "Enter CHAR Matrix A: " << endl;
		cin >> a;
		cout << "Matrix A: " << endl; cout << a;

		cout << "Random generated CHAR  Matrix B: " << endl; cout << b;

		cout << endl << "A + B" << endl << a + b << endl << "A - B" << endl << a - b << endl << "A * B" << endl << a * b << endl;
		cout << "+============================================================================================+" << endl;
	}
	return 0;
}
