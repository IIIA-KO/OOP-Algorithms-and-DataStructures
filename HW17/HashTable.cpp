#include "HashTable.h"
#include <fstream>

HashTable::HashTable(size_t _n)
{
	n = _n;
	count = 0;
	table = new Node * [n] {};
}

HashTable::~HashTable()
{
	Clear();
	delete table;
}

int HashTable::hash(string str)
{
	int p = 2;
	long long sum = 0;
	for (int i = 0; i < str.size(); i++) {
		sum += str[i] * pow(p, i);
	}
	return sum % n;
}

void HashTable::push(Student str)
{
	count++;
	int p = hash(str.getSurname());
	if (!table[p]) {
		table[p] = new Node(str);
	}
	else {
		table[p] = new Node(str, table[p]);
	}
}


void HashTable::Show() const
{
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getNext() == nullptr)
				cout << i << ": " << table[i]->getValue() << endl;
			else {
				Node* temp = table[i];
				while (temp) {
					temp->Show(); cout << endl;
					temp = temp->getNext();
				}
				cout << endl;
			}
		}
	}
	cout << endl;
}

void HashTable::find_by_surname(string _surname)
{
	//int index = hash(_surname);
	//Node* tmp = table[index];
	///*if (tmp->getValue().getSurname() != _surname) {
	//	cout << "ERROR: Student was not found" << endl;
	//	return;
	//}*/
	//if (!tmp) {
	//	cout << "ERROR: Student was not found" << endl;
	//	return;
	//}
	//else {
	//	if (tmp->getNext() == nullptr) {
	//		tmp->Show();
	//		return;
	//	}
	//	else {
	//		while (tmp) {
	//			if (tmp->getValue().getSurname() == _surname) {
	//				tmp->Show();
	//				return;
	//			}
	//			tmp = tmp->getNext();
	//		}
	//	}
	//}
	int index = hash(_surname);
	Node* tmp = table[index];
	if (!tmp) {
		cout << "ERROR: Student was not found" << endl;
		return;
	}
	if (tmp->getValue().getSurname() == _surname) {
		tmp->Show();
		return;
	}
	else if (tmp->getValue().getSurname() != _surname && tmp->getNext() != nullptr) {
		while (tmp) {
			if (tmp->getValue().getSurname() == _surname) {
				tmp->Show();
				return;
			}
			tmp = tmp->getNext();
		}
	}
	cout << "ERROR: Student was not found" << endl;
}

void HashTable::delete_student(string surname)
{
	int ind = hash(surname);
	Node* prev = nullptr;
	Node* tmp = table[ind];
	if (!tmp) {
		cout << "ERROR: There is no such student in table" << endl;
		return;
	}
	else {
		while (tmp->getNext() && tmp->getValue().getSurname() != surname) {
			prev = tmp;
			tmp = tmp->getNext();
		}
		if (tmp->getValue().getSurname() == surname) {
			if (prev)
				prev->setNext(tmp->getNext());
			else
				table[ind] = nullptr;
			delete tmp;
			return;
		}
	}
}

void HashTable::Save(const char* fname)
{
	ofstream fout;
	fout.open(fname);
	if (!fout.is_open()) {
		throw exception("file was not opened\n");
	}
	fout << n << endl;
	fout << count << endl;
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getNext() == nullptr) {
				fout << table[i]->getValue().getSurname() << endl;
				fout << table[i]->getValue().getBirthDate().getDay() << endl;
				fout << table[i]->getValue().getBirthDate().getMonth() << endl;
				fout << table[i]->getValue().getBirthDate().getYear() << endl;
			}
			else {
				while (table[i]) {
					fout << table[i]->getValue().getSurname() << endl;
					fout << table[i]->getValue().getBirthDate().getDay() << endl;
					fout << table[i]->getValue().getBirthDate().getMonth() << endl;
					fout << table[i]->getValue().getBirthDate().getYear() << endl;
					table[i] = table[i]->getNext();
				}
			}
		}
	}
	fout.close();
}

void HashTable::Load(const char* fname)
{
	ifstream fin;
	fin.open(fname);
	if (!fin.is_open()) {
		throw exception("file was not opened\n");
	}
	Clear();
	delete[] table;
	(fin >> n).get();
	table = new Node * [n] {};
	(fin >> count).get();

	Student tmp;
	Date tmp_bd;
	string surname;
	int day = 0, month = 0, year = 0;

	for (int i = 0; i < count; i++) {
		getline(fin, surname);
		tmp.setSurname(surname);

		fin >> day;
		fin >> month;
		fin >> year;

		fin.get();

		tmp_bd.setDay(day);
		tmp_bd.setMonth(month);
		tmp_bd.setYear(year);

		tmp.setBirthDate(tmp_bd);

		int p = hash(tmp.getSurname());
		if (!table[p]) {
			table[p] = new Node(tmp);
		}
		else {
			table[p] = new Node(tmp, table[p]);
		}
	}
	fin.close();
}

void HashTable::Clear()
{
	for (int i = 0; i < n; i++) {
		while (table[i] != nullptr)
		{
			Node* temp = table[i];
			table[i] = temp->getNext();
			delete temp;
		}
	}
}