#include <iostream>
#include <string.h>
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

class String
{
protected:
	char* str;
public:
	~String();
	String();
	String(int capacity);
	String(const char* string);
	String(const String& s);
	void Show_Str() const;
	void Input_Str();
	int len() const;
	void Clear();
	friend ostream& operator<<(ostream& out, const String& S);
	friend istream& operator>>(istream& in, String& S);
	String& operator=(const String& text);
	void operator=(String&& text);
	void operator+=(String& text);
	String operator+(const String& text) const;
	bool operator==(const String& text);
	bool operator!=(const String& text);
	bool operator>(const String& text);
	char* getStr() const;
};
String::~String() {
	delete[] str;
}
String::String() {
	/*int capacity = 81;
	str = new char[capacity];*/
	str = nullptr;
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
	if (str)
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
int String::len() const {
	if (!str) return 0;
	return strlen(getStr());
}
void String::Clear()
{
	if (str) {
		free(str);
		str = 0;
	}
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
void String::operator+=(String& text)
{
	str = _strdup(strcat(this->getStr(), text.str));
}
String String::operator+(const String& text) const {
	String tmp;
	int thislen = strlen(this->str);
	int txtlen = strlen(text.str);
	tmp.str = new char[thislen + txtlen + 1];
	int i = 0;
	for (; i < thislen; i++) {
		tmp.str[i] = this->str[i];
	}
	for (int j = 0; j < txtlen; j++, i++) {
		tmp.str[i] = text.str[j];
	}
	tmp.str[thislen + txtlen] = '\0';
	return tmp;
}
bool String::operator==(const String& text)
{
	return strcmp(this->str, text.str) == 0;
}
bool String::operator!=(const String& text)
{
	return strcmp(this->str, text.str) != 0;
}
bool String::operator>(const String& text)
{
	return strcmp(this->str, text.str) == 1;
}

class bits : public String {
protected:
	bool isBin(const char* string) const;
	bool isBin(char* string) const;
	bool isBin() const;
public:
	//~bits(); деструктор не потрібний, адже бітовий рядок створений на базі звичаного рядка. Деструктор звичайного рядка слугує деструктором для бітового
	bits();
	bits(const char* string);
	bits(const bits& string);
	bits(char symbol);

	void change();
	bits& operator=(bits& text);
	bool operator==(const bits& text);
	bool operator!=(const bits& text);

	friend bits operator+(char ch, bits b);
	bits operator +(const bits& b);
	void operator+=(const bits& b);
};
bits::bits() : String() {}
bits::bits(const char* string) : String(string) {
	if (!isBin(str)) Clear();
}
bits::bits(const bits& string) : String(string) {
	if (!isBin(str)) Clear();
}
bits::bits(char symbol) {
	char* s = new char[2];
	s[1] = 0;
	s[0] = symbol;
	if (isBin(s)) str = strdup(s);
}
bool bits::isBin(const char* string) const {
	if (!string) {
		return 0;
	}
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != '0' && string[i] != '1') {
			return 0;
		}
	}
	return 1;
}
bool bits::isBin(char* string) const {
	if (!string) return 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] != '0' && string[i] != '1')
			return 0;
	}
	return 1;
}
bool bits::isBin() const {
	if (!this->str) return 0;
	for (int i = 0; i < strlen(this->str); i++) {
		if (this->str[i] != '0' && this->str[i] != '1')
			return 0;
	}
	return 1;
}
bits& bits::operator=(bits& text) {
	String::operator=(text);
	return *this;
}
bool bits::operator==(const bits& text) {
	return strcmp(str, text.getStr()) == 0;
}
bool bits::operator!=(const bits& text) {
	return strcmp(str, text.getStr()) != 0;
}
void bits::change() {
	if (str[0] == '1') {
		for (int i = 1; i < len(); i++) {
			if (str[i] == '0')
				str[i] = '1';
			else
				str[i] = '0';
		}
	}
	*this += bits(1);
}

bits operator+(char s, bits string) {
	int l = string.len();
	char* txt = new char[l];
	strcpy(txt, string.str);
	string.str = new char[l + 1];
	string.str[0] = s;
	for (int i = 0; i < l; i++) string.str[i] = txt[i - 1];
	return string;
}
bits bits::operator +(const bits& b)
{
	int k, q = 0, a1, a2;
	if (this->len() > b.len()) k = len();
	else k = b.len();
	char* r = new char[k + 2];
	memset(r, '0', k + 1);
	r[k + 1] = 0;
	int i = len() - 1;
	int j = b.len() - 1;
	for (int n = k; n > 0; n--)
	{
		if (i >= 0) {
			a1 = str[i] - '0';
		}
		else
			a1 = 0;
		if (j >= 0) {
			a2 = b.str[j] - '0';
		}
		else
			a2 = 0;
		switch (a1 + a2 + q)
		{
		case 3:
			r[n] = 1;
			q = 2;
			break;
		case 2:
			r[n] = '0';
			q = 1;
			break;
		case 1:
			r[n] = '1';
			q = 0;
			break;
		case 0:
			r[n] = '0';
			q = 0;
			break;
		}
		i--;
		j--;
	}
	if (q == 1) {
		r[0] = '1';
	}
	return bits(r);
}
void bits::operator+=(const bits& b) {
	bits tmp = *this + b;
	*this = tmp;
}

int main()
{
	//Завдання 1
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
		cout << "+=============================================================+" << endl << endl << endl;
	}

	//Завдання 2
	{
		bits bit_string, bit_string2;
		cout << "Enter Bit String A: "; cin >> bit_string;
		cout << "Enter Bit String B: "; cin >> bit_string2;

		cout << "+=============================================================+" << endl;
		cout << "Change sign of Bit Sting" << endl;
		cout << "Bit String A: " << bit_string << endl;
		bit_string.change();
		cout << "Result: " << bit_string << endl;
		cout << "+=============================================================+" << endl << endl << endl;

		cout << "+=============================================================+" << endl;
		cout << "A == B ?" << endl;
		cout << "Result: " << (bit_string == bit_string2) << endl;
		cout << "+=============================================================+" << endl << endl << endl;

		cout << "+=============================================================+" << endl;
		cout << "A != B ?" << endl;
		cout << "Result: " << (bit_string != bit_string2) << endl;
		cout << "+=============================================================+" << endl << endl << endl;

		cout << "+=============================================================+" << endl;
		cout << "A + B ?" << endl;
		bits bit_string3 = bit_string + bit_string2;
		cout << "Result: " << bit_string3 << endl;
		cout << "+=============================================================+" << endl << endl << endl;

		cout << "+=============================================================+" << endl;
		cout << "A += B" << endl;
		cout << "A: " << bit_string << endl;
		cout << "B: " << bit_string2 << endl;
		bit_string += bit_string2;
		cout << "Result: " << bit_string << endl;
		cout << "+=============================================================+" << endl << endl << endl;
	}
	return 0;
}
