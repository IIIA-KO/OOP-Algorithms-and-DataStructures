#include <iostream>
using namespace std;

class String {
	char* str;
	static int count;
public:
	~String() {
		delete[] str;
		count--;
	}
	String() {
		int capacity = 81;
		str = new char[capacity];
		count++;
	}
	String(int capacity) {
		str = new char[capacity + 1];
		count++;
	}
	String(const char* string) {
		str = _strdup(string);
		count++;
	}
	String(const String& s) {
		str = _strdup(s.str);
		count++;
	}

	void Show_Str() const {
		cout << str << endl;
	}
	void Input_Str() {
		delete[] str;
		char string[81];
		cin >> string;
		str = _strdup(string);
		//cin.getline(str, 81); ?
	}
	static void Show_count() {
		cout << "Created objects: " << count << endl;
	}
};
int String::count = 0;

int main()
{
	String str1;
	String str2(120);
	String str3("Goodbye, World!");

	cout << "Enter String: "; str1.Input_Str();
	cout << "Enter String: "; str2.Input_Str();

	str1.Show_Str();
	str2.Show_Str();
	str3.Show_Str();

	String::Show_count();
	return 0;
}