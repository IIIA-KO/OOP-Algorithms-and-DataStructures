#include <iostream>
using namespace std;

class Matrix {
private:
	int r, c;
	int** mat_arr = 0;
	void clearMemory(int** a, int n) {
		for (int i = 0; i < n; i++) {
			delete[] a[i];
		}
		delete[] a;
	}
	int findDet(int** a, int n) {
		if (n == 1)
			return a[0][0];
		else if (n == 2)
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];
		else {
			int d = 0;
			for (int k = 0; k < n; k++) {
				int** b = new int* [n - 1];
				for (int i = 0; i < n - 1; i++) {
					b[i] = new int[n - 1];
				}
				for (int i = 1; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (j == k)
							continue;
						else if (j < k)
							b[i - 1][j] = a[i][j];
						else
							b[i - 1][j - 1] = a[i][j];
					}
				}
				d += pow(-1, k + 2) * a[0][k] * findDet(b, n - 1);
				clearMemory(b, n - 1);
			}
			return d;
		}
	}
public:
	~Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& M);

	friend istream& operator>> (istream& in, const Matrix& M);
	friend ostream& operator<< (ostream& out, const Matrix& M);

	Matrix operator+(const Matrix& a);
	Matrix operator+(int value);
	friend Matrix operator+(int val, const Matrix a);

	Matrix operator-(const Matrix& a);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator=(const Matrix& M);
	Matrix operator*(const Matrix& a);

	operator double();
};
Matrix::~Matrix() {
	for (int i = 0; i < r; i++) {
		delete[] mat_arr[i];
	}
	delete[] mat_arr;
}
Matrix::Matrix(int r, int c) {
	if (r < 1 || c < 1) exit(-1);
	this->r = r;
	this->c = c;
	mat_arr = new int* [r];
	for (int i = 0; i < r; i++)
		mat_arr[i] = new int[c] {0};
}
Matrix::Matrix(const Matrix& M) {
	r = M.r;
	c = M.c;
	mat_arr = new int* [M.r];
	for (int i = 0; i < M.r; i++)
		mat_arr[i] = new int[M.c]{ 0 };

	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			mat_arr[i][j] = M.mat_arr[i][j];
		}
	}
}
istream& operator>> (istream& in, const Matrix& M) {
	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			cout << "Enter [" << i << "][" << j << "] element: "; in >> M.mat_arr[i][j];
		}
	}
	return in;
}
ostream& operator<< (ostream& out, const Matrix& M) {
	for (int i = 0; i < M.r; i++) {
		for (int j = 0; j < M.c; j++) {
			out << M.mat_arr[i][j] << " ";
		}
		cout << endl;
	}
	return out;
}
Matrix& Matrix:: operator=(const Matrix& M) {
	if (this != &M) {
		r = M.r;
		c = M.c;
		mat_arr = new int* [M.r];
		for (int i = 0; i < M.r; i++)
			mat_arr[i] = new int[M.c]{ 0 };

		for (int i = 0; i < M.r; i++) {
			for (int j = 0; j < M.c; j++) {
				mat_arr[i][j] = M.mat_arr[i][j];
			}
		}
	}
	return *this;
}
Matrix::operator double() {
	if (this->r == this->c) {
		double det = findDet(this->mat_arr, r);
		return det;
	}
	else {
		cout << "Matrix must have same row and column sizes" << endl;
		exit(-1);
	}
}

int main()
{
	cout << "+======================================================+" << endl;
	Matrix D(3, 3);
	cin >> D;
	cout << "static_cast<double>(D)" << endl;
	cout << "Matrix D: " << endl << D;
	double det = static_cast<double>(D);//double(D);
	cout << "Determinant: " << det << endl;
	cout << "+======================================================+" << endl << endl << endl;
	return 0;
}