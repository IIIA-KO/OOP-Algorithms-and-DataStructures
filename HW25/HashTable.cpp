#include "HashTable.h"

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

void HashTable::push(Firm str)
{
	count++;
	int p = hash(str.getName());
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
				table[i]->Show();
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

void HashTable::find_by_name(string _name)
{
	int index = hash(_name);
	Node* tmp = table[index];
	if (!tmp) {
		cout << "ERROR: Firm was not found" << endl;
		return;
	}
	if (tmp->getValue().getName() == _name) {
		tmp->Show();
		return;
	}
	else if (tmp->getValue().getName() != _name && tmp->getNext() != nullptr) {
		while (tmp) {
			if (tmp->getValue().getName() == _name) {
				tmp->Show();
				return;
			}
			tmp = tmp->getNext();
		}
	}
	cout << "ERROR: Firm was not found" << endl;
}

void HashTable::find_by_owner(string _owner)
{
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getValue().getOwner() == _owner && table[i]->getNext() == nullptr) {
				table[i]->Show();
				return;
			}
			else if (table[i]->getValue().getOwner() != _owner && table[i]->getNext() != nullptr) {
				Node* tmp = table[i];
				while (tmp) {
					if (tmp->getValue().getOwner() == _owner) {
						tmp->Show();
						return;
					}
				}
			}
		}
	}
	cout << "ERROR: Firm was not found" << endl;
}

void HashTable::find_by_phone(string _phone)
{
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getValue().getPhone() == _phone && table[i]->getNext() == nullptr) {
				table[i]->Show();
				return;
			}
			else if (table[i]->getValue().getPhone() != _phone && table[i]->getNext() != nullptr) {
				Node* tmp = table[i];
				while (tmp) {
					if (tmp->getValue().getPhone() == _phone) {
						tmp->Show();
						return;
					}
				}
			}
		}
	}
	cout << "ERROR: Firm was not found" << endl;
}

void HashTable::find_by_adress(string _adress)
{
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getValue().getAdress() == _adress && table[i]->getNext() == nullptr) {
				table[i]->Show();
				return;
			}
			else if (table[i]->getValue().getAdress() != _adress && table[i]->getNext() != nullptr) {
				Node* tmp = table[i];
				while (tmp) {
					if (tmp->getValue().getAdress() == _adress) {
						tmp->Show();
						return;
					}
				}
			}
		}
	}
	cout << "ERROR: Firm was not found" << endl;
}

void HashTable::find_by_activity(string _activity)
{
	for (int i = 0; i < n; i++) {
		if (table[i]) {
			if (table[i]->getValue().getActivity() == _activity && table[i]->getNext() == nullptr) {
				table[i]->Show();
				return;
			}
			else if (table[i]->getValue().getActivity() != _activity && table[i]->getNext() != nullptr) {
				Node* tmp = table[i];
				while (tmp) {
					if (tmp->getValue().getActivity() == _activity) {
						tmp->Show();
						return;
					}
				}
			}
		}
	}
	cout << "ERROR: Firm was not found" << endl;
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
				fout << table[i]->getValue().getName() << endl;
				fout << table[i]->getValue().getOwner() << endl;
				fout << table[i]->getValue().getPhone() << endl;
				fout << table[i]->getValue().getAdress() << endl;
				fout << table[i]->getValue().getActivity() << endl;
			}
			else {
				while (table[i]) {
					fout << table[i]->getValue().getName() << endl;
					fout << table[i]->getValue().getOwner() << endl;
					fout << table[i]->getValue().getPhone() << endl;
					fout << table[i]->getValue().getAdress() << endl;
					fout << table[i]->getValue().getActivity() << endl;
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

	Firm tmp;
	string name, owner, phone, adress, activity;

	for (int i = 0; i < count; i++) {
		getline(fin, name);
		//fin.get();
		tmp.setName(name);

		getline(fin, owner);
		//fin.get();
		tmp.setOwner(owner);

		getline(fin, phone);
		//fin.get();
		tmp.setPhone(phone);

		getline(fin, adress);
		//fin.get();
		tmp.setAdress(adress);

		getline(fin, activity);
		///fin.get();
		tmp.setActivity(activity);

		int p = hash(tmp.getName());
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