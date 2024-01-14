#include "List.h"
//#define _CRT_SECURE_NO_WARNINGS
List::List() :head(nullptr), tail(nullptr) {}
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
void List::Save_Students(const char* fname, List arr)
{
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "ERROR: Error write file: " << fname << "\tError:" << nError << endl;
		return;
	}
	Node* tmp = arr.head;
	fprintf(fs, "%i\n", arr.Size());
	while (tmp) {
		fprintf(fs, "%20s\t", tmp->getValue().getSurname());
		fprintf(fs, "%3i\t", tmp->getValue().getBirthDate().getDay());
		fprintf(fs, "%3i\t", tmp->getValue().getBirthDate().getMonth());
		fprintf(fs, "%6i\n", tmp->getValue().getBirthDate().getYear());
		tmp = tmp->getNext();
	}
	fclose(fs);
}
void List::Load_Students(const char* fname)
{
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		cout << "ERROR: Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}

	int temp_size = 0;
	fscanf(fs, "%i", &temp_size);

	Student tmp;
	String temp_student_surname;
	Date temp_student_birthdate;
	int td = 0;
	int tm = 0;
	int ty = 0;
	for (int i = 0; i < temp_size; i++) {
		fscanf(fs, "%s", temp_student_surname.str);
		tmp.setSurname(temp_student_surname);

		fscanf(fs, "%d", &td);
		fscanf(fs, "%d", &tm);
		fscanf(fs, "%d", &ty);

		temp_student_birthdate.setDay(td);
		temp_student_birthdate.setMonth(tm);
		temp_student_birthdate.setYear(ty);
		tmp.setBirthDate(temp_student_birthdate);
		this->push_back(tmp);
	}
	fclose(fs);
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
void List::FindBySurname(String temp_surname) {
	Node* tmp = head;
	while (tmp) {
		if (tmp->getValue().getSurname() == temp_surname) {
			tmp->Show();
			return;
		}
		tmp = tmp->getNext();
	}
}
void List::push_back(Student v) {
	Node* tmp = new Node(v);
	if (!isEmpty()) {
		tail->setNext(tmp);
	}
	else {
		head = tmp;
	}
	tail = tmp;
}
void List::push_front(Student v) {
	Node* tmp = new Node(v, head);
	if (!head) tail = tmp;
	head = tmp;
}
void List::insert(Student v, int i) {
	if (i == 0) {
		push_front(v);
		return;
	}
	else if (i < 0) cout << "Invalid index" << endl;
	Node* prev = FindPos(i - 1);
	if (!prev) return;
	Node* tmp = new Node(v, prev->getNext());
	prev->setNext(tmp);
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
void List::del_ind(int i)
{
	if (i == 0) {
		del_front();
	}
	else if (!isEmpty()) {
		Node* prev = FindPos(i - 1);
		Node* tmp = prev->getNext();
		if (!prev) return;
		prev->setNext(tmp->getNext());
		delete tmp;
	}
	else {
		cout << "Array is empty" << endl;
	}
}
void List::Show() const {
	Node* temp = head;
	if (!isEmpty()) {
		while (temp) {
			temp->Show();
			temp = temp->getNext();
		}
	}
	else cout << "Array is empty" << endl;
}
void List::Show_exact(int i) {
	if (i < 0) {
		cout << "ERROR: Invalid index" << endl;
		return;
	}
	else {
		Node* tmp = FindPos(i);
		cout << "Result: "; tmp->Show();
	}
}
void List::Sort()
{
	Node* a, * b, * p, * h = NULL;
	for (Node* i = head; i != NULL; ) {
		a = i;
		i = i->getNext();
		b = h;
		for (p = NULL; (b != NULL) && (a->getValue().getSurname() > b->getValue().getSurname()); ) {
			p = b;
			b = b->getNext();
		}

		if (p == NULL) {
			a->setNext(h);
			h = a;
		}
		else {
			a->setNext(b);
			p->setNext(a);
		}
	}
	if (h != NULL)
		head = h;
}