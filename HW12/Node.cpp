#include "Node.h"
Node::Node(Student v, Node* n) : val(v), next(n) {}
Student Node::getValue() const {
	return val;
}
void Node::setValue(Student v) {
	val = v;
}
Node* Node::getNext() const {
	return next;
}
void Node::setNext(Node* n) {
	next = n;
}
void Node::Show() const {
	cout << val << " ";
}