#pragma once
#include "Node.h"
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

	void push(Student str);

	void Show() const;

	void Clear();

	void find_by_surname(string _surname);

	void delete_student(string surname);

	void Save(const char* fname);

	void Load(const char* fname);
};