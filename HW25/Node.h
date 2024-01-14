#pragma once
#include <iostream>
#include "Firm.h"
using namespace std;
class Node
{
private:
	Firm val;

	Node* next;
public:
	Node(Firm v, Node* n = nullptr);

	Firm getValue() const;

	void setValue(Firm v);

	Node* getNext() const;

	void setNext(Node* n);

	void Show() const;
};