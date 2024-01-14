#include <iostream>
using namespace std;

class Pet {
protected:
	char* name;
	char* type;
	char* color;
public:
	Pet(const char* n, const char* c) : name(_strdup(n)), color(_strdup(c)), type(_strdup("Animal")) {}
	~Pet() {
		delete[] name;
		delete[] type;
		delete[] color;
	}

	void Show() const {
		cout << "Name: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Color: " << color << endl;
	}
};
class Dog : public Pet {
public:
	Dog(const char* n, const char* c) : Pet(n, c) {
		type = _strdup("Dog");
	}
	~Dog() {}
	void Sound() {
		cout << "Bark!" << endl;
	}
};
class Cat : public Pet {
public:
	Cat(const char* n, const char* c) : Pet(n, c) {
		type = _strdup("Cat");
	}
	~Cat() {}
	void Sound() {
		cout << "Meow!" << endl;
	}
};
class Parrot : public Pet {
public:
	Parrot(const char* n, const char* c) : Pet(n, c) {
		type = _strdup("Parrot");
	}
	~Parrot() {}
	void Sound() {
		cout << "Squawk!" << endl;
	}
};
class Humster : public Pet {
public:
	Humster(const char* n, const char* c) : Pet(n, c) {
		type = _strdup("Humster");
	}
	~Humster(){}
	void Sound() {
		cout << "Chirp!" << endl;
	}
};



class Node {
private:
	int val;
	Node* next;
public:
	Node(int v, Node* n = nullptr);
	int getValue() const;
	void setValue(int v);
	Node* getNext() const;
	void setNext(Node* n);
	void Show() const;
};
Node::Node(int v, Node* n) : val(v), next(n) {}
int Node::getValue() const {
	return val;
}
void Node::setValue(int v) {
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

class List {
protected:
	Node* head;
	Node* tail;
public:
	List();
	virtual ~List();
	virtual void push_back(int v);
	virtual void push_front(int v);

	virtual void del_front();
	virtual void del_tail();

	int Size() const;
	void Clear();
	Node* FindPos(int pos);

	void Show() const;

	bool isEmpty() const;
};
List::List() :head(nullptr), tail(nullptr) {}
List::~List() {
	Clear();
}
bool List::isEmpty() const {
	return head == 0;
}
int List::Size() const
{
	int size = 0;
	Node* tmp = this->head;
	while (tmp) {
		tmp = tmp->getNext();
		size++;
	}
	return size;
}
void List::Clear()
{
	while (head) {
		this->del_front();
	}
}
Node* List::FindPos(int pos) {
	Node* tmp = head;
	int i = 0;
	while (tmp)
	{
		if (i == pos) break;
		i++;
		tmp = tmp->getNext();
	}
	return tmp;
}
void List::push_back(int v) {
	Node* tmp = new Node(v);
	if (!isEmpty()) {
		tail->setNext(tmp);
	}
	else {
		head = tmp;
	}
	tail = tmp;
}
void List::push_front(int v) {
	Node* tmp = new Node(v, head);
	if (!head) tail = tmp;
	head = tmp;
}
void List::del_front() {
	if (isEmpty()) return;
	Node* tmp = head;
	head = tmp->getNext();
	delete tmp;
}
void List::del_tail() {
	if (isEmpty()) return;
	Node* tmp = tail;
	if (head == tail) {
		head = tail = NULL;
	}
	else {
		tail->setNext(NULL);
	}
	delete tmp;
}
void List::Show() const {
	Node* temp = head;
	if (!isEmpty()) {
		while (temp) {
			temp->Show();
			temp = temp->getNext();
		}
		cout << endl;
	}
	else cout << "Array is empty" << endl;
}

class Stack : public List
{
	int count;
public:
	Stack();
	~Stack();

	void push(int elem);
	void pop();
	bool isempty() const;
	int size() const;
};
Stack::Stack() : List(), count(0) {}
Stack::~Stack() {}
bool Stack::isempty() const {
	return count == 0;
}
void Stack::push(int elem) {
	/*Node* tmp = new Node(elem, head);
	head = tmp;*/
	List::push_front(elem);
	count++;
}
void Stack::pop() {
	/*if (isempty()) {
		cout << "Stack is empty" << endl;
		return;
	}
	Node* tmp = head;
	head = tmp->getNext();
	delete tmp;*/
	List::del_front();
	count--;
}
int Stack::size() const {
	return this->count;
}

class Queue : public List
{
	int count;
public:
	Queue();
	~Queue();
	void push(int elem);
	void pop();
	int size() const;
};
Queue::Queue() : List(), count(0) {}
Queue::~Queue() {}
void Queue::push(int elem) {
	/*Node* tmp = new Node(elem);
	if (!isempty()) {
		tail->setNext(tmp);
	}
	else {
		head = tmp;
	}
	tail = tmp;*/
	List::push_back(elem);
	count++;
}
void Queue::pop() {
	/*if (isempty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node* tmp = head;
	head = tmp->getNext();
	delete tmp;*/
	List::del_front();
	count--;
}
int Queue::size() const {
	return this->count;
}

int main()
{
	//Завдання 1
	{
		Queue Q;
		cout << "QUEUE" << endl;
		cout << "+===========================================================================+" << endl;
		cout << "Push" << endl;
		cout << "Enter few elements to queue: " << endl;
		int element;
		for (int i = 0; i < 5; i++) {
			cout << "Enter element: "; cin >> element;
			Q.push(element);
		}
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Pop" << endl;
		Q.pop();
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Show" << endl;
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		Stack S;
		cout << "STACK" << endl;
		cout << "+===========================================================================+" << endl;
		cout << "Push" << endl;
		cout << "Enter few elements to stack: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << "Enter element: "; cin >> element;
			S.push(element);
		}
		S.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Pop" << endl;
		S.pop();
		S.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Show" << endl;
		S.Show();
		cout << "+===========================================================================+" << endl << endl << endl;
	}

	//Завдання 2
	{
		cout << "+=============================================================+" << endl;
		cout << "---------DOG---------" << endl;
		Dog d("Tuzik", "White");
		cout << "Information: " << endl; d.Show();
		cout << "Sound: "; d.Sound(); cout << endl;

		cout << "---------CAT---------" << endl;
		Cat c("Barsik", "Black");
		cout << "Information: " << endl; c.Show();
		cout << "Sound: "; c.Sound(); cout << endl;

		cout << "---------PARROT---------" << endl;
		Parrot p("Kesha", "Yellow");
		cout << "Information: " << endl; p.Show();
		cout << "Sound: "; p.Sound(); cout << endl;

		cout << "---------Humster---------" << endl;
		Humster h("Humsty", "Brown");
		cout << "Information: " << endl; h.Show();
		cout << "Sound: "; h.Sound(); cout << endl;
		cout << "+=============================================================+" << endl << endl << endl;
	}
	return 0;
}