#pragma once
#include "Node.h"
#include <fstream>
#include <string>

class HashTable
{
private:
	Node** table;

	size_t n;
	int count;
public:
	explicit HashTable(size_t _n);

	~HashTable();

	int hash(string str);

	void push(Firm str);

	void Show() const;

	void Clear();

	void find_by_name(string _name);
	void find_by_owner(string _owner);
	void find_by_phone(string _phone);
	void find_by_adress(string _adress);
	void find_by_activity(string _activity);

	void Save(const char* fname);

	void Load(const char* fname);
};