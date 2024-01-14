#pragma once
#include "RList.h"
class Tnode
{
private:
	int number;
public:
	RList arr;

	Tnode* left;

	Tnode* right;

	Tnode(int v, RList a, Tnode* l = 0, Tnode* r = 0);

	//~Tnode();

	int getNum() const;

	void setNum(int v);

	void Show() const;
};