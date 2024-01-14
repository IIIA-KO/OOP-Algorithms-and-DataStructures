#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <list>
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

	bool operator== (const Student& a){
		if (age == a.getAge() && name == a.getName() && surname == a.getSurname() && patronymic == a.getPatronymic())
			return true;
		else return false;
	}
};

ostream& operator<<(ostream& out, const list<Student>& arr) {
	for (auto it = arr.begin(); it != arr.end(); it++)
		(*it).Show();
	out << endl;
	return out;
}

void show_exact(const list<Student>& arr, string _name, string _surname, string _patronymic) {
	for (auto it : arr) {
		if ((it.getName() == _name) && (it.getSurname() == _surname) && (it.getPatronymic() == _patronymic)) {
			it.Show();
			return;
		}
	}
	cout << "ПОМИЛКА: немає такого студента в списку" << endl;
}
void delete_exact(list<Student>& arr, string _name, string _surname, string _patronymic) {
	for (auto it = arr.begin(); it != arr.end(); it++) {
		if ((it->getName() == _name) && (it->getSurname() == _surname) && (it->getPatronymic() == _patronymic)) {
			arr.erase(it);
			return;
		}
	}
	cout << "ПОМИЛКА: немає такого студента в списку" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	
	list<Student> arr;
	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Додайте двох студентів на початок списку: " << endl;
	int age;
	string name, surname, patronymic;
	Student st(0, "", "", "");
	for (int i = 0; i < 2; i++) {
		cout << "Введіть вік " << i + 1 << "-го студента: "; cin >> age;
		cout << "Введіть ім'я  " << i + 1 << "-го студента: "; cin >> name;
		cout << "Введіть прізвище " << i + 1 << "-го студента: "; cin >> surname;
		cout << "Введіть по батькові " << i + 1 << "-го студента: "; cin >> patronymic;
		cout << endl;

		if (age < 0) {
			throw exception("ПОМИЛКА: некоректний вік");
			st.setAge(0);
		}
		else
			st.setAge(age);
		st.setName(name);
		st.setSurname(surname);
		st.setPatronymic(patronymic);
		arr.emplace_front(st);
	}
	cout << arr;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "Додайте двох студентів в кінець списку: " << endl;
	for (int i = 0; i < 2; i++) {
		cout << "Введіть вік " << i + 1 << "-го студента: "; cin >> age;
		cout << "Введіть ім'я  " << i + 1 << "-го студента: "; cin >> name;
		cout << "Введіть прізвище " << i + 1 << "-го студента: "; cin >> surname;
		cout << "Введіть по батькові " << i + 1 << "-го студента: "; cin >> patronymic;
		cout << endl;

		if (age < 0) {
			throw exception("ПОМИЛКА: некоректний вік");
			st.setAge(0);
		}
		else
			st.setAge(age);
		st.setName(name);
		st.setSurname(surname);
		st.setPatronymic(patronymic);
		arr.emplace_back(st);
	}
	cout << arr;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	int pos;
	cout << "Введіть позицію, куди ви хочете додати студента: "; cin >> pos;
	cout << "Введіть вік студента: "; cin >> age;
	cout << "Введіть ім'я студента: "; cin >> name;
	cout << "Введіть прізвище студента: "; cin >> surname;
	cout << "Введіть по батькові студента: "; cin >> patronymic;
	if (age < 0) {
		throw exception("ПОМИЛКА: некоректний вік");
		st.setAge(0);
	}
	else st.setAge(age);

	if (pos < 0 || pos > arr.size()) throw exception("ПОМИЛКА: некоректна позиція");
	else {
		auto it = arr.begin();
		advance(it, pos);
		st.setName(name);
		st.setSurname(surname);
		st.setPatronymic(patronymic);
		arr.emplace(it, st);
	}
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	/*int age;														МОЖНА ВИКОРИСТАТИ ЦЕЙ СТАНДАРТНИЙ СПИСОК, ЗАМІСТЬ ДОДАВАННЯ ВРУЧНУ;
	string name, surname, patronymic;
	Student s1(20, "Іван", "Іващук", "Іванович");
	Student s2(21, "Петро", "Петрук", "Петрович");
	Student s3(22, "Євген", "Євгенко", "Євгенович");
	Student s4(22, "Євген", "Євгенко", "Євгенович");
	Student s5(23, "Ївга", "Ївго", "Ївгівна");
	Student s6(20, "Ґанс", "Ґюґо", "Ґансович");
	Student s7(20, "Ґанс", "Ґюґо", "Ґансович");
	arr.emplace_back(s1);
	arr.emplace_back(s2);
	arr.emplace_back(s3);
	arr.emplace_back(s4);
	arr.emplace_back(s5);
	arr.emplace_back(s6);
	arr.emplace_back(s7);
	cout << arr;*/

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Видалення конкретного студента:" << endl << endl;
	cout << "Введіть ім'я студента: "; cin >> name;
	cout << "Введіть прізвище студента: "; cin >> surname;
	cout << "Введіть по батькові студента: "; cin >> patronymic;
	delete_exact(arr, name, surname, patronymic);
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Видалення дублікатів зі списку" << endl;
	cout << arr;
	arr.sort([](const Student& a, const Student& b) { return a.getAge() > b.getAge(); });
	arr.unique();
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Видалення студентів старших зазначеного віку" << endl;
	cout << arr;
	cout << "Введіть вік: "; cin >> age;

	for (auto it = arr.begin(); it != arr.end(); )
		if (it->getAge() > age) it = arr.erase(it);
		else it++;

	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Видалення студентів, у яких є набір введених символів у прізвищі" << endl;
	cout << arr;
	string sym;
	cout << "Введіть набір символів: "; cin >> sym;
	for (auto it = arr.begin(); it != arr.end(); )
		if (it->getSurname().find(sym) != -1) it = arr.erase(it);
		else it++;
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Сортування списку за прізвищем від А до Я" << endl;
	arr.sort(
		[](const Student& a, const Student& b) {
			return strcoll(a.getSurname().c_str(), b.getSurname().c_str()) < 0;
		}
	);
	cout << arr;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Сортування списку за прізвищем від Я до А" << endl;
	arr.sort(
		[](const Student& a, const Student& b) {
			return strcoll(a.getSurname().c_str(), b.getSurname().c_str()) > 0;
		}
	);
	cout << arr;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Сортування списку за віком за зростанням" << endl;
	arr.sort(
		[](const Student& a, const Student& b) {
			return a.getAge() < b.getAge();
		}
	);
	cout << arr;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Сортування списку за віком за спаданням" << endl;
	arr.sort(
		[](const Student& a, const Student& b) {
			return a.getAge() > b.getAge();
		}
	);
	cout << arr;
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;

	cout << "+===================================================================================================================================================================+" << endl;
	cout << "Виведення інформації про конкретного студента:" << endl << endl;
	cout << "Введіть ім'я студента: "; cin >> name;
	cout << "Введіть прізвище студента: "; cin >> surname;
	cout << "Введіть по батькові студента: "; cin >> patronymic;
	show_exact(arr, name, surname, patronymic);
	cout << "+===================================================================================================================================================================+" << endl << endl << endl;
	return 0;
}