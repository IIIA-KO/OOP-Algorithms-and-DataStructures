#include "Node.h"
Node::Node(Firm v, Node* n) : val(v), next(n) {}

Firm Node::getValue() const {
	return val;
}

void Node::setValue(Firm v) {
	val = v;
}

Node* Node::getNext() const {
	return next;
}

void Node::setNext(Node* n) {
	next = n;
}

void Node::Show() const {
	/*cout << val << " ";*/
	val.Show();
}