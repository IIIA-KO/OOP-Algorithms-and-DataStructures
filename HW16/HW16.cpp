#include "Tree.h"

int main()
{
	Tree arr;
	int n;
	String violation;
	cout << "+======================================================+" << endl;
	cout << "Enter 5 violations: " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter number of car: "; cin >> n;
		if (n < 1000 || n > 9999) {
			cout << "Wrong number of car" << endl;
			return -1;
		}
		cout << "Enter violation: "; cin >> violation;
		arr.Insert(n, violation); //можна передавати порушення у вигляді рядка, а не змінної класу String, якщо необхідно
								//використовувати декілька слів з пробілами для опису порушення по типу:  'arr.Insert(n, "License is out of term");' і тд.
	}
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "Print All" << endl;
	arr.Show();
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "Print by number" << endl;
	cout << "Enter number: "; cin >> n;
	arr.Show_by_number(n);
	cout << "+======================================================+" << endl << endl << endl;

	cout << "+======================================================+" << endl;
	cout << "Print by range of numbers" << endl;
	int l, r;
	cout << "Enter left side of range: "; cin >> l;
	cout << "Enter right side of range: "; cin >> r;
	arr.Show_by_range(l, r);
	cout << "+======================================================+" << endl << endl << endl;
	return 0;
}