#include <iostream>
#include <string>
#include <Windows.h>
using namespace std	;

string Trim(string text) {
	int left = 0, right = 0;
	while (text[left] == ' ') left++;

	int len = text.length();

	while (len - 1 - right >= 0 && text[len - 1 - right] == ' ') right++;

	int lenNew = len - right - left;

	string str;
	str = text.substr(left, lenNew);
	return str;
}
string PIB(string Name) {
	string fullName = Trim(Name);

	int pos1 = fullName.find(' ');

	string pib = fullName.substr(0, pos1 + 1);

	string tmp = fullName.substr(pos1 + 1);
	tmp = Trim(tmp);
	int pos2 = tmp.find(' ') + (fullName.length() - tmp.length());

	string name;
	name = fullName.substr(pos1, pos2 - pos1);

	tmp = tmp.substr(pos2 - (fullName.length() - tmp.length()) + 1);
	tmp = Trim(tmp);
	string Patronymic = fullName.substr(pos2);

	name = Trim(name);
	pib += name[0];
	pib += '.';

	Patronymic = Trim(Patronymic);
	pib += Patronymic[0];
	pib += '.';

	return pib;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "+==================================================================================================+" << endl;
	string name1 = "Іваненко Петро Степанович";
	string name2 = "   Іваненко Петро Степанович";
	string name3 = "Іваненко Петро Степанович      ";
	string name4 = "     Іваненко                  Петро     Степанович      ";

	cout << "Імена: " << endl << endl;
	cout << name1 << endl << name2 << endl << name3 << endl << name4 << endl;
	cout << "+==================================================================================================+" << endl << endl << endl;

	cout << "+==================================================================================================+" << endl;
	cout << "Призвище, ініціали: " << endl << endl;
	string pib = PIB(name1);
	cout << pib << endl;

	pib = PIB(name2);
	cout << pib << endl;

	pib = PIB(name3);
	cout << pib << endl;

	pib = PIB(name4);
	cout << pib << endl;
	cout << "+==================================================================================================+" << endl ;
	return 0;
}