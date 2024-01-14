#include "String.h"
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
