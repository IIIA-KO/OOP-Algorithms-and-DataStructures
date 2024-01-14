#include <iostream>
using namespace std;


template<class T>
class Node2 {
private:
	int val;
public:
	Node2* next;
	Node2* prev;

	Node2(int v, Node2* n = NULL, Node2* p = NULL);

	int getValue() const;
	void setValue(int v);
	Node2* getNext() const;
	void setNext(Node2* n);
	Node2* getPrev() const;
	void setPrev(Node2* p);
	void Show() const;
};
template<class T>
Node2<T>::Node2<T>(int v, Node2<T>* n, Node2<T>* p) : val(v), next(n), prev(p) {}
template<class T>
int Node2<T>::getValue() const {
	return val;
}
template<class T>
void Node2<T>::setValue(int v) {
	val = v;
}
template<class T>
Node2<T>* Node2<T>::getNext() const {
	return next;
}
template<class T>
void Node2<T>::setNext(Node2<T>* n) {
	next = n;
}
template<class T>
Node2<T>* Node2<T>::getPrev() const {
	return prev;
}
template<class T>
void Node2<T>::setPrev(Node2<T>* p) {
	prev = p;
}
template<class T>
void Node2<T>::Show() const {
	cout << val << " ";
}


template<class R>
class List2 {
	Node2<R>* head;
	Node2<R>* tail;
public:
	List2();
	~List2();
	void push_back(int v);
	void push_front(int v);
	void insert(int v, int i);
	void del_pos(int i);

	void del_front();
	void del_tail();
	Node2<R>* FindPos(int pos);
	void Show() const;
	void ShowR() const;
	bool isEmpty() const;
	void Clear();
	int find(int elem) const;
	int replace(int elem, int rv);
	void reverse();
};
template<class R>
List2<R>::List2() :head(nullptr), tail(nullptr) {}
template<class R>
List2<R>::~List2() { Clear(); }
template<class R>
void List2<R>::Clear() {
	while (head)
		del_front();
}
template<class R>
int List2<R>::find(int elem) const
{
	Node2<R>* tmp = head;
	int i = 0;
	while (tmp) {
		int v = tmp->getValue();
		if (v == elem) {
			return i;
		}
		i++;
		tmp = tmp->getNext();
	}
	return -1;
}
template<class R>
int List2<R>::replace(int elem, int rv)	//неправильно работает
{
	Node2<R>* tmp = head;
	int count = 0;
	while (tmp) {
		int v = tmp->getValue();
		if (v == elem) {
			tmp->setValue(rv);
			count++;
		}
		tmp = tmp->getNext();
	}
	return count;
}
template<class R>
bool List2<R>::isEmpty() const {
	return head == 0;
}
template<class R>
Node2<R>* List2<R>::FindPos(int pos) {
	Node2<R>* tmp = head;
	int i = 0;
	while (tmp)
	{
		if (i == pos) break;
		i++;
		tmp = tmp->getNext();
	}
	return tmp;
}
template<class R>
void List2<R>::push_back(int v) {
	Node2<R>* tmp = new Node2<R>(v, NULL, tail);
	if (!isEmpty()) {
		tail->setNext(tmp);
		//tmp->setPrev(tail);
	}
	else {
		head = tmp;
	}
	tail = tmp;
}
template<class R>
void List2<R>::push_front(int v) {
	Node2<R>* tmp = new Node2<R>(v, head);
	if (!head) {
		tail = tmp;
	}
	else {
		tmp->setNext(head);
		head->setPrev(tmp);
	}
	head = tmp;
}
template<class R>
void List2<R>::insert(int v, int i) {
	/*if (i < 0) return;
	if (i == 0) {
		push_front(v);
		return;
	}
	Node2* prev = FindPos(i - 1);
	Node2* next = FindPos(i);
	if (!prev) {
		return;
	}
	if(!next){
		return;
	}
	if (next = tail) {
		push_back(v);
		return;
	}
	Node2* tmp = new Node2(v);
	prev->setNext(tmp);
	tmp->setPrev(prev);

	next->setPrev(tmp);
	tmp->setNext(next);*/

	if (i < 0) return;
	if (i == 0) {
		push_front(v);
		return;
	}
	Node2<R>* cur = FindPos(i - 1);
	if (!cur) {
		return;
	}
	Node2<R>* tmp = new Node2<R>(v, cur->next, cur);
	if (cur->next) {
		cur->next->prev = tmp;
	}
	else tail = tmp;
	cur->next = tmp;
}
template<class R>
void List2<R>::del_pos(int i)
{
	if (i < 0) return;
	if (i == 0) {
		del_front();
		return;
	}
	else if (!isEmpty()) {
		if (FindPos(i) == tail) {
			del_tail();
			return;
		}
		Node2<R>* prev = FindPos(i - 1);
		Node2<R>* tmp = prev->getNext();
		if (!prev) return;
		prev->setNext(tmp->getNext());
		tmp->getNext()->setPrev(tmp->prev);
		delete tmp;
	}
	else {
		cout << "Array is empty" << endl;
	}

}
template<class R>
void List2<R>::del_front() {
	if (isEmpty()) return;
	Node2<R>* tmp = head;
	if (head == tail) {
		head = tail = NULL;
	}
	else {
		head = tmp->getNext();
		head->prev = NULL;
	}
	delete tmp;
}
template<class R>
void List2<R>::del_tail() {
	if (isEmpty()) return;
	Node2<R>* tmp = tail;
	if (head == tail) {
		head = tail = NULL;
	}
	else {
		tail = tmp->getPrev();
		tail->next = NULL;
	}
	delete tmp;
}
template<class R>
void List2<R>::Show() const {
	Node2<R>* temp = head;
	if (!isEmpty()) {
		while (temp) {
			temp->Show();
			temp = temp->getNext();
		}
		cout << endl;
	}
	else {
		cout << "Array is empty" << endl;
		return;
	}
}
template<class R>
void List2<R>::reverse()
{
	Node2<R>* tmp1 = head;
	Node2<R>* tmp2 = tmp1->next;
	tmp1->next = NULL;
	tmp1->prev = tmp2;
	while (tmp2)
	{
		tmp2->prev = tmp2->next;
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp2->prev;
	}
	head = tmp1;
}
template<class R>
void List2<R>::ShowR() const {
	Node2<R>* temp = head;
	while (temp) {
		temp->Show();
		temp = temp->getPrev();
	}
	cout << endl;
}



int main()
{
	//Завдання 1
	List2<int> arr;
	cout << "+===============================================================================================+" << endl;
	int elem;
	cout << "ADD TO HEAD" << endl;
	cout << "Array: " << endl; arr.Show();
	cout << "Enter 5 numbers to array";
	for (int i = 0; i < 5; i++) {
		cout << "Enter element: "; cin >> elem;
		arr.push_front(elem);
	}
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================+" << endl;
	cout << "ADD TO TAIL" << endl;
	cout << "Array: " << endl; arr.Show();
	cout << "Enter element you want to add to tail of array: "; cin >> elem;
	arr.push_back(elem);
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================+" << endl;
	cout << "DELETE FROM HEAD" << endl;
	cout << "Array: " << endl; arr.Show();
	arr.del_front();
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;

	cout << "+===============================================================================================+" << endl;
	cout << "DELETE FROM TAIL" << endl;
	cout << "Array: " << endl; arr.Show();
	arr.del_tail();
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================+" << endl;
	cout << "DELETE FROM ALL" << endl;
	cout << "Array: " << endl; arr.Show();
	arr.Clear();
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;

	//Завдання 2
	cout << "+===============================================================================================+" << endl;
	cout << "Enter 5 numbers to array" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Enter element: "; cin >> elem;
		arr.push_front(elem);
	}
	cout << "Array: " << endl; arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================+" << endl;
	int ind;
	arr.Show();
	cout << "Enter elemnt: "; cin >> elem;
	cout << "Enter index where you want to insert element"; cin >> ind;
	arr.insert(elem, ind);
	arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;

	cout << "+===============================================================================================+" << endl;
	arr.Show();
	cout << "Enter index where you want to delete element"; cin >> ind;
	arr.del_pos(ind);
	arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;

	cout << "+===============================================================================================+" << endl;
	arr.Show();
	cout << "Enter element index of which you want to find: "; cin >> elem;
	cout << "Index of element: " << arr.find(elem) << endl;
	cout << "+===============================================================================================+" << endl << endl << endl;

	cout << "+===============================================================================================+" << endl;
	arr.Show();
	int change_elem;
	cout << "Enter element you want to replace: "; cin >> elem;
	cout << "Enter replace-element: "; cin >> change_elem;
	cout << "Count of replaced elements: " << arr.replace(elem, change_elem) << endl;
	arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;

	cout << "+===============================================================================================+" << endl;
	cout << "Reverse" << endl;
	arr.reverse();
	arr.Show();
	cout << "+===============================================================================================+" << endl << endl << endl;
	return 0;
}