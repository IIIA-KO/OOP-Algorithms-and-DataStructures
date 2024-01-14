#pragma once
#include "Tnode.h"
class Tree
{
private:
	Tnode* root;

	void Insert(int v, Tnode* cur, Tnode* tmp);

	void Show(Tnode* cur) const;

	void Show_by_range(Tnode* node, int num1, int num2) const;
public:
	Tree();

	~Tree();

	Tnode* getRoot();

	void Insert(int number, const String& receipt);

	void Show() const;

	void Show_by_number(int number) const;

	void Show_by_range(int num1, int num2) const;

	void Clear(Tnode* cur);

	void Clear();

	Tnode* Find(Tnode* cur, int v) const;
};