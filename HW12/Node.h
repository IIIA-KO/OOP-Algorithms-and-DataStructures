#pragma once
#include "Student.h"
using namespace std;
class Node {
private:
	Student val;
	Node* next;
public:
	Node(Student v, Node* n = nullptr);
	Student getValue() const;
	void setValue(Student v);
	Node* getNext() const;
	void setNext(Node* n);
	void Show() const;
};