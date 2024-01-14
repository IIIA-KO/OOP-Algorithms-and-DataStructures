#include "Tnode.h"

Tnode::Tnode(int v, RList a, Tnode* l, Tnode* r) : number(v), left(l), right(r), arr(a){}

//Tnode::~Tnode() {
//	if (left)delete left;
//	if (right)delete right;
//}

int Tnode::getNum() const
{
	return number;
}

void Tnode::setNum(int v)
{
	number = v;
}

void Tnode::Show() const
{
	cout << number << "\t";
	arr.Show();
	cout << endl;
}