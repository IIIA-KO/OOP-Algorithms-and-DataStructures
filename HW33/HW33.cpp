#include <iostream>
#include <set>
using namespace std;

template <class T, class R>
ostream& operator<<(ostream& out, const set<T, R>& arr) {
	for (auto it = arr.begin(); it != arr.end(); it++)
		out << *it << "\t";
	out << endl;
	return out;
}

int main()
{
	//Завдання 1
	{
		cout << "+==================================================================+" << endl;
		set <int> arr;
		int n;
		cout << "Enter how many elements you want to add to set: "; cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cout << "Enter " << i + 1 << " element: "; cin >> x;
			if (arr.find(x) == arr.end()) cout << "NO" << endl;
			else cout << "YES" << endl;
			arr.insert(x);
		}
		cout << "+==================================================================+" << endl << endl << endl;
	}

	//Завдання 2
	{
		cout << "+==================================================================+" << endl;
		int n, m, count = 0, x;
		set <int> s;
		cout << "Enter how many numbers you want to add to first set: "; cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Enter " << i + 1 << " element: "; cin >> x;
			s.insert(x);
		}
		cout << "Enter how many numbers you want to add to first set: "; cin >> m;
		for (int i = 0; i < m; i++) {
			cout << "Enter " << i + 1 << " element: "; cin >> x;
			s.insert(x);
		}
		cout << "Result: " << (m + n) - s.size() << endl;
		cout << "+==================================================================+" << endl << endl << endl;
	}

	//Завдання 3
	{
		cout << "+==================================================================+" << endl;
		set <int> s1, s2;
		int n, m, x;
		cout << "Enter how many numbers you want to add to first set: "; cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter " << i + 1 << " element: "; cin >> x;
			s1.insert(x);
		}
		cout << "Enter how many numbers you want to add to first set: "; cin >> m;
		for (int i = 0; i < m; i++)
		{
			cout << "Enter " << i + 1 << " element: "; cin >> x;
			if (s1.find(x) != s1.end()) s2.insert(x);
		}
		cout << s2;
		cout << "+==================================================================+" << endl << endl << endl;
	}
	return 0;
}
