#include <iostream>
using namespace std;

class String
{
private:
	char* str;
public:
	~String();
	String();
	String(int capacity);
	String(const char* string);
	String(const String& s);
	void Show_Str() const;
	void Input_Str();
	friend ostream& operator<<(ostream& out, const String& S);
	friend istream& operator>>(istream& in, String& S);
	String& operator=(const String& text);
	void operator=(String&& text);
	bool operator==(const String& text);
	bool operator>(const String& text);

	char* getStr() const;
};
String::~String() {
	delete[] str;
}
String::String() {
	int capacity = 81;
	str = new char[capacity];
}
String::String(int capacity) {
	str = new char[capacity + 1];
}
String::String(const char* string) {
	str = _strdup(string);
}
String::String(const String& s) {
	str = _strdup(s.str);
}
void String::Show_Str() const {
	cout << str << endl;
}
char* String::getStr() const {
	return str;
}
void String::Input_Str() {
	delete[] str;
	char string[100];
	cin >> string;
	str = _strdup(string);
}
ostream& operator<<(ostream& out, const String& S) {
	S.Show_Str();
	return out;
}
istream& operator>>(istream& in, String& S) {
	S.Input_Str();
	return in;
}
String& String::operator=(const String& text) {
	if (this == &text)
		return *this;
	delete[] str;
	str = _strdup(text.str);
	return *this;
}
void String::operator=(String&& text) {
	str = text.str;
	text.str = nullptr;
}

bool String::operator==(const String& text)
{
	return strcmp(this->str, text.str) == 0;
}
bool String::operator>(const String& text)
{
	return strcmp(this->str, text.str) == 1;
}

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
class Stack
{
	Node<T>* head;
	int count;
public:
	Stack();
	~Stack();

	void push(T elem);
	void pop();
	T top() const;
	bool isempty() const;
	int size() const;

	bool check_brackets(const String& txt);
};
template <class T>
Stack<T>::Stack() : head(nullptr), count(0) {}
template <class T>
Stack<T>::~Stack() {
	while (head) {
		pop();
	}
}
template <class T>
bool Stack<T>::isempty() const {
	return count == 0;
}
template <class T> void Stack<T>::push(T elem) {
	Node<T>* tmp = new Node<T>(elem, head);
	head = tmp;
	count++;
}
template <class T>
void Stack<T>::pop() {
	if (isempty()) {
		cout << "Stack is empty" << endl;
		return;
	}
	Node<T>* tmp = head;
	head = tmp->getNext();
	delete tmp;
	count--;
}
template<class T>
int Stack<T>::size() const {
	return this->count;
}
template<class T>
T Stack<T>::top()const {
	if (count != 0)
		return head->getValue();
	/*else {
		cout << "Stack is empty" << endl;
		exit(-1);
	}*/
}
template<class T>
bool Stack<T>::check_brackets(const String& txt)
{
	if (strlen(txt.getStr()) == 0) {
		cout << "String is empty" << endl;
		return false;
	}
	else if (txt.getStr()[0] == ')' || txt.getStr()[0] == '}' || txt.getStr()[0] == ']' || txt.getStr()[0] == '>') {
		cout << txt.getStr()[0] << endl;
		return false;
	}
	else {
		for (int i = 0; i < strlen(txt.getStr()); i++) {
			char ch = txt.getStr()[i];
			switch (ch) {
			case '(':
			case '{':
			case '[':
			case '<':
				push(ch);
				break;

			case ')':
				if (top() == '(')
					pop();
				else {
					for (int j = 0; j < i; j++) cout << txt.getStr()[j];
					cout << endl;
					return false;
				}
				break;

			case '}':
				if (top() == '{')
					pop();
				else {
					for (int j = 0; j < i; j++) cout << txt.getStr()[j];
					cout << endl;
					return false;
				}
				break;

			case ']':
				if (top() == '[')
					pop();
				else {
					for (int j = 0; j < i; j++) cout << txt.getStr()[j];
					cout << endl;
					return false;
				}
				break;

			case '>':
				if (top() == '<')
					pop();
				else {
					for (int j = 0; j < i; j++) cout << txt.getStr()[j];
					cout << endl;
					return false;
				}
				break;
			}
		}
	}
	if (count == 0) return true;
	else return false;
}

int main()
{
	/*
	* Тестові рядки:
	* "({x-y-z}*[x+2y]-(z+4x))" - правильно
	* "([x-y-z}*[x+2y)-{z+4x)]" - неправильно
	*/

	Stack<char> sentence;
	String text;
	cout << "Enter string: "; cin.getline(text.getStr(), 100);//cin >> text;
	if (sentence.check_brackets(text))
		cout << "String is valid" << endl;
	else
		cout << "String is invalid" << endl;
	return 0;
}