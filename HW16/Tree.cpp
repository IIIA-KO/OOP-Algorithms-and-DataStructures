#include "Tree.h"

Tree::Tree() :root(nullptr) {}

Tree::~Tree() {
	Clear();
	root = 0;
}

Tnode* Tree::getRoot()
{
	return root;
}

void Tree::Insert(int v, Tnode* cur, Tnode* tmp)
{
	if (!cur) return;
	else if (cur->getNum() == v) return;
	else if (cur->getNum() > v) {
		if (cur->left) {
			Insert(v, cur->left, tmp);
		}
		else {
			cur->left = new Tnode(v, tmp->arr);
		}
	}
	else {
		if (cur->right) {
			Insert(v, cur->right, tmp);
		}
		else {
			cur->right = new Tnode(v, tmp->arr);
		}
	}
}
void Tree::Insert(int number, const String& receipt)
{
	Tnode* cur = root;
	Tnode* temp;
	if (!root) {
		RList ar;
		ar.push_front(receipt);
		root = new Tnode(number, ar);
	}
	if (Find(cur, number) != nullptr) {
		/*temp = Find(cur, number);
		temp->arr.push_front(receipt);*/
		Find(cur, number)->arr.push_front(receipt);
	}
	else {
		RList ar;
		ar.push_front(receipt);
		Tnode* temp = new Tnode(number, ar);
		Insert(temp->getNum(), root, temp);
	}
}

void Tree::Show(Tnode* cur) const
{
	if (!cur) return;
	Show(cur->left);
	Show(cur->right);
	cur->Show();
}

Tnode* Tree::Find(Tnode* cur, int v) const
{
	if (!cur) return nullptr;
	if (cur->getNum() == v) {
		return cur;
	}
	if (v < cur->getNum()) {
		if (cur->left)
			return Find(cur->left, v);
		else
			return nullptr;
	}
	else {
		if (cur->right)
			return Find(cur->right, v);
		else
			return nullptr;
	}
}

void Tree::Show() const
{
	Show(root);
}

void Tree::Show_by_number(int number) const
{
	Tnode* tmp = Find(root, number);
	if (!tmp) {
		cout << "There is no car with such number" << endl;
		return;
	}
	else tmp->Show();
}

void Tree::Show_by_range(Tnode* node, int num1, int num2) const
{
	if (num1 > num2) {
		cout << "Left side of range has bigger value than Right one" << endl;
		return;
	};
	if (!node) return;

	if (node->getNum() > num1) {
		Show_by_range(node->left, num1, num2);
	}
	if (node->getNum() >= num1 && node->getNum() <= num2) {
		node->Show();
	}
	if (node->getNum() < num2) {
		Show_by_range(node->right, num1, num2);
	}
}

void Tree::Show_by_range(int num1, int num2) const
{
	Show_by_range(root, num1, num2);
}

void Tree::Clear(Tnode* cur)
{
	if (!cur)return;
	Clear(cur->left);
	Clear(cur->right);
	delete cur;
}

void Tree::Clear()
{
	Clear(root);
	root = 0;
}