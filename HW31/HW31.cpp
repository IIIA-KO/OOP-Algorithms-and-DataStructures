#include <iostream>
#include <iomanip>
#include <deque>
using namespace std;

class Student {
	int age;
	string name, surname, patronymic;
public:
	Student(int a, string n, string s, string p) {
		age = a;
		name = n;
		surname = s;
		patronymic = p;
	}

	int getAge() const { return age; }
	string getName() const { return name; }
	string getSurname() const { return surname; }
	string getPatronymic() const { return patronymic; }

	void setAge(int a) { age = a; }
	void setName(string n) { name = n; }
	void setSurname(string s) { surname = s; }
	void setPatronymic(string p) { patronymic = p; }

	void Show() const {
		cout << "| " << setw(5) << age << " | " << setw(25) << name << " | " << setw(25) << surname << " | " << setw(25) << patronymic << " |\n";
	}
};

void ShowExact(const deque<Student>& arr, string _name, string _surname, string _patronymic) {
	for (int i = arr.size() - 1; i >= 0; i--) {
		if ((arr[i].getName() == _name) && (arr[i].getSurname() == _surname) && (arr[i].getPatronymic() == _patronymic)) {
			arr[i].Show();
			return;
		}
	}
	cout << "ERROR: There is no such student in array" << endl;
}
void ShowMoreAge(const deque<Student>& arr, int age) {
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i].getAge() > age) {
			arr[i].Show();
		}
	}
}
ostream& operator<<(ostream& out, const deque<Student>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].Show();
	}
	out << endl;
	return out;
}
int main()
{
	deque<Student> arr;
	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Enter 5 students to deque: " << endl;

	int age;
	string name, surname, patronymic;
	Student st(0, "", "", "");
	for (int i = 0; i < 5; i++) {
		cout << "Enter age of " << i + 1 << " student: "; cin >> age;
		cout << "Enter name of " << i + 1 << " student: "; cin >> name;
		cout << "Enter surname of " << i + 1 << " student: "; cin >> surname;
		cout << "Enter patronymic of " << i + 1 << " student: "; cin >> patronymic;
		cout << endl;

		if (age < 0) {
			throw exception("ERROR: invalid value for age");
			st.setAge(0);
		}
		else
			st.setAge(age);
		st.setName(name);
		st.setSurname(surname);
		st.setPatronymic(patronymic);
		arr.push_back(st);
	}
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;


	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Print all students:\n" << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;


	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Enter name of student you want to delete: "; cin >> name;
	cout << "Enter surname of student you want to delete: "; cin >> surname;
	cout << "Enter patronymic of student you want to delete: "; cin >> patronymic;
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i].getName() == name && arr[i].getSurname() == surname && arr[i].getPatronymic() == patronymic) {
			arr.erase(arr.begin() + i);
		}
	}
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;


	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Enter name of student you want to print: "; cin >> name;
	cout << "Enter surname of student you want to print: "; cin >> surname;
	cout << "Enter patronymic of student you want to print: "; cin >> patronymic;
	ShowExact(arr, name, surname, patronymic);
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;


	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Enter age: "; cin >> age;
	ShowMoreAge(arr, age);
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;
	return 0;
}