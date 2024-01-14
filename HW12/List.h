#pragma once
#include "Node.h"
class List {
	Node* head;
	Node* tail;
public:
	List();
	void push_back(Student v);
	void push_front(Student v);
	void insert(Student v, int i);

	void del_front();
	void del_tail();
	void del_ind(int i);

	int Size() const;
	void Clear();
	Node* FindPos(int pos);
	void FindBySurname(String temp_surname);

	void Show() const;
	void Show_exact(int pos);

	bool isEmpty() const;

	void Save_Students(const char* fname, List arr);
	void Load_Students(const char* fname);

	void Sort();
};