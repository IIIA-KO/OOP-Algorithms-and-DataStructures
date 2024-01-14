#pragma once
#include <iostream>
using namespace std;
class String
{
private:
public:
	char* str;
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
};