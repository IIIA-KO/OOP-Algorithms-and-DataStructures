#include <iostream>
#include <fstream>
#include <iomanip>
#include<conio.h>
#include <Windows.h>
#define BACKGROUND 0
#define FOREGROUNG 2
#define SELECTITEMMENU 15
#define LEFTMENU 85
#define TOPMENU 20
using namespace std;


void SetColor(unsigned short backColor, unsigned short foreColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);
	SetConsoleTextAttribute(h, color);
}
void Setcursor(unsigned short row, unsigned short col) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord{ col, row };
	SetConsoleCursorPosition(h, coord);
}
void paintMenu(const char** textMenu, size_t sizeMenu, size_t select) {
	system("cls");
	Setcursor(TOPMENU, LEFTMENU);
	cout << "...............MENU..............." << endl;
	for (size_t i = 0; i < sizeMenu; i++)
	{
		Setcursor(TOPMENU + i + 1, LEFTMENU);
		if (i == select) {
			SetColor(BACKGROUND, SELECTITEMMENU);
			cout << "=> " << textMenu[i] << endl;
		}
		else {
			cout << "  " << textMenu[i] << endl;
		}
		SetColor(BACKGROUND, FOREGROUNG);
	}
}
size_t Menu(const char** textMenu, size_t sizeMenu, size_t select) {
	unsigned char c = 80;
	while (true)
	{
		if (c == 72 || c == 80)
			paintMenu(textMenu, sizeMenu, select);
		c = _getch();
		switch (c) {
		case 13:
			return select;
		case 72:
			if (select == 0) select = sizeMenu;
			select--;
			break;

		case 80:
			select++;
			if (select == sizeMenu) select = 0;
			break;
		}
	}
	return 0;
}


int RandomNum(int min, int max) {
	return rand() % (max - min + 1) + min;
}
void SaveRandBin(const char* fname) {
	int n = RandomNum(1, 100);
	ofstream fout(fname, ios::binary);
	if (!fout.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	for (int i = 0; i < n; i++) {
		int num = RandomNum(-100, 100);
		fout.write((char*)&num, sizeof(num));
	}
	fout.close();
}
int Count(const char* fname) {
	ifstream f(fname, ios::binary);
	if (!f.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	/*int count = 0, n = 0;
	while (!f.eof()) {
		f.read((char*)&n, sizeof(n));
		count++;
	}*/

	f.seekg(0, ios::end);
	int count = f.tellg() / sizeof(count);
	f.seekg(0, ios::beg);
	return count;
}
void PrintArr(const char* fname) {
	ifstream fin(fname, ios::binary);
	if (!fin.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	int  n = 0;
	for (int i = 0; i < Count(fname); i++) {
		fin.read((char*)&n, sizeof(n));
		cout << n << " ";
	}
	cout << endl;
	fin.close();
}
int Sum(const char* fname) {
	ifstream f(fname, ios::binary);
	if (!f.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	int sum = 0, n;
	for (int i = 0; i < Count(fname); i++) {
		f.read((char*)&n, sizeof(n));
		sum += n;
	}
	f.close();
	return sum;
}
double Avg(const char* fname) {
	double avg = 0;
	avg = double(Sum(fname)) / Count(fname);
	return avg;
}
void PrintMoreAvg(const char* fname) {
	ifstream fin(fname, ios::binary);
	if (!fin.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	int avg = Avg(fname), n = 0;
	for (int i = 0; i < Count(fname); i++) {
		fin.read((char*)&n, sizeof(n));
		if (n > avg) cout << n << " ";
	}
	cout << endl;
	fin.close();
}

void SortBin(const char* fname) {
	fstream f(fname, ios::in | ios::out | ios::binary);
	if (!f.is_open()) {
		throw exception("ERROR: File was not opened");
	}
	int x, y, s = Count(fname);
	f.seekg(0, ios::beg);
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s - 1; j++) {
			f.read((char*)&x, sizeof(x));
			f.read((char*)&y, sizeof(y));
			if (x > y) {
				f.seekg(-8, ios::cur);
				f.write((const char*)&y, sizeof(y));
				f.write((const char*)&x, sizeof(x));
				f.seekg(-4, ios::cur);
			}
			else {
				f.seekg(-4, ios::cur);
			}
		}
		f.seekg(0, ios::beg);
	}
	f.close();
}

int main()
{
	srand(time(0));
	const char* fname = "randbinarr.bin";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Create Array",
		"2) Count numbers",
		"3) Count sum",
		"4) Count average",
		"5) Output numbers bigger than avarage",
		"6) Sort",
		"7) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 6:
			return select;

		case 0:
			SaveRandBin(fname);
			PrintArr(fname);
			break;

		case 1:
			cout << "Count of numbers: " << Count(fname) << endl;
			break;

		case 2:
			cout << "Sum of elements: " << Sum(fname) << endl;
			break;

		case 3:
			cout << "Avarage of all numbers: " << Avg(fname) << endl;
			break;

		case 4:
			cout << "Numbers bigger than avarage: "; PrintMoreAvg(fname);
			break;

		case 5:
			SortBin(fname);
			PrintArr(fname);
			break;

		default:
			break;
		}
		cout << "---DONE---\n";
		_getch();
	}
	return 0;
}