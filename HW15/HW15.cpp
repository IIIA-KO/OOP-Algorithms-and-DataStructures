#include <iostream>
using namespace std;

template <class T>
class Node {
private:
	T val;
	Node* next;
public:
	Node(T v, Node* n = NULL);
	T getValue() const;
	void setValue(int v);
	Node* getNext() const;
	void setNext(Node* n);
	void Show() const;
};
template <class T>
Node<T>::Node(T v, Node* n) : val(v), next(n) {}
template <class T>
T Node<T>::getValue() const {
	return val;
}
template <class T>
void Node<T>::setValue(int v) {
	val = v;
}
template <class T>
Node<T>* Node<T>::getNext() const {
	return next;
}
template <class T>
void Node<T>::setNext(Node<T>* n) {
	next = n;
}
template <class T>
void Node<T>::Show() const {
	cout << val << " ";
}



template <class T>
class Queue
{
	Node<T>* head;
	Node<T>* tail;
	int count;
public:
	Queue();
	~Queue();
	void push(T elem);
	void pop();
	T front() const;
	T back()const;
	bool isempty() const;
	bool isfull() const;
	int size() const;
	void Show();
};
template <class T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), count(0) {}
template <class T>
Queue<T>::~Queue() {
	while (head) {
		pop();
	}
}
template <class T>
bool Queue<T>::isempty() const {
	return count == 0;
}
template<class T>
bool Queue<T>::isfull() const
{
	return count > 0;
}
template <class T>
void Queue<T>::push(T elem) {
	Node<T>* tmp = new Node<T>(elem);
	if (!isempty()) {
		tail->setNext(tmp);
	}
	else {
		head = tmp;
	}
	tail = tmp;
	count++;
}
template <class T>
void Queue<T>::pop() {
	if (isempty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node<T>* tmp = head;
	head = tmp->getNext();
	delete tmp;
	count--;
}
template<class T>
int Queue<T>::size() const {
	return this->count;
}
template<class T>
void Queue<T>::Show()
{
	Node<T>* tmp = head;
	for (int i = 0; i < count; i++) {
		cout << tmp->getValue() << " ";
		tmp = tmp->getNext();
	}
	cout << endl;
}
template<class T>
T Queue<T>::front()const {
	if (count != 0)
		return head->getValue();
	else {
		cout << "Queue is empty" << endl;
		exit(-1);
	}
}
template<class T>
T Queue<T>::back()const {
	if (count != 0)
		return tail->getValue();
	else {
		cout << "Queue is empty" << endl;
		exit(-1);
	}
}


template <class T>
class Queue_Priority
{
	Node<T>* head;
	Node<T>* tail;
	int count;
public:
	Queue_Priority();
	~Queue_Priority();
	void push(T elem);
	void pop();
	T front() const;
	T back()const;
	bool isempty() const;
	bool isfull() const;
	int size() const;
	void Show();
	Node<T>* FindPos(int pos);
	int peek() const;
};
template <class T>
Queue_Priority<T>::Queue_Priority() : head(nullptr), tail(nullptr), count(0) {}
template <class T>
Queue_Priority<T>::~Queue_Priority() {
	while (head) {
		pop();
	}
}
template <class T>
bool Queue_Priority<T>::isempty() const {
	return count == 0;
}
template<class T>
bool Queue_Priority<T>::isfull() const
{
	return count > 0;
}
template<class T>
Node<T>* Queue_Priority<T>::FindPos(int pos) {
	Node<T>* tmp = head;
	int i = 0;
	while (tmp)
	{
		if (i == pos) break;
		i++;
		tmp = tmp->getNext();
	}
	return tmp;
}
template<class T>
int Queue_Priority<T>::peek() const
{
	if (isfull())
		return head->getValue();
	else
		cout << "Queue is empty" << endl;
}
template <class T>
void Queue_Priority<T>::push(T elem) {
	Node<T>* cur = head;
	Node<T>* tmp = new Node<T>(elem, 0);
	if (isfull()) {
		if (head->getValue() > elem){
			tmp->setNext(head);
			head = tmp;
		}
		else{
			while (cur->getNext() && cur->getNext()->getValue() < elem)
				cur = cur->getNext();
			tmp->setNext(cur->getNext());
			cur->setNext(tmp);
		}
	}
	else {
		head = tmp;
		tail = tmp;
	}
	count++;
}
template <class T>
void Queue_Priority<T>::pop() {
	if (isempty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node<T>* tmp = head;
	head = tmp->getNext();
	delete tmp;
	count--;
}
template<class T>
int Queue_Priority<T>::size() const {
	return this->count;
}
template<class T>
void Queue_Priority<T>::Show()
{
	Node<T>* tmp = head;
	for (int i = 0; i < count; i++) {
		cout << tmp->getValue() << " ";
		tmp = tmp->getNext();
	}
	cout << endl;
}
template<class T>
T Queue_Priority<T>::front()const {
	if (count != 0)
		return head->getValue();
	else {
		cout << "Queue_Priority is empty" << endl;
		exit(-1);
	}
}
template<class T>
T Queue_Priority<T>::back()const {
	if (count != 0)
		return tail->getValue();
	else {
		cout << "Queue_Priority is empty" << endl;
		exit(-1);
	}
}



int main()
{
	//Завдання 1
	{
		Queue<int> Q;
		cout << "+===========================================================================+" << endl;
		cout << "Is Empty" << endl;
		cout << Q.isempty() << endl;
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Is Full" << endl;
		cout << Q.isfull() << endl;
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Enqueue" << endl;
		cout << "Enter few elements to queue: " << endl;
		int element;
		for (int i = 0; i < 5; i++) {
			cout << "Enter element: "; cin >> element;
			Q.push(element);
		}
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Dequeue" << endl;
		Q.pop();
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Show" << endl;
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;
	}

	//Завдання 2
	{
		Queue_Priority<int> Q;
		cout << "+===========================================================================+" << endl;
		cout << "Is Empty" << endl;
		cout << Q.isempty() << endl;
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Is Full" << endl;
		cout << Q.isfull() << endl;
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "InsertWithPriority" << endl;
		cout << "Enter few elements to queue: " << endl;
		int element;
		for (int i = 0; i < 5; i++) {
			cout << "Enter element: "; cin >> element;
			Q.push(element);
		}
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "PullHighestPriorityElement" << endl;
		Q.pop();
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Peek" << endl;
		cout << Q.peek() << endl;
		cout << "+===========================================================================+" << endl << endl << endl;

		cout << "+===========================================================================+" << endl;
		cout << "Show" << endl;
		Q.Show();
		cout << "+===========================================================================+" << endl << endl << endl;
	}
	return 0;
}