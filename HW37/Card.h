#pragma once
#include <iostream>
#include <iomanip>

#include <string>

#include<conio.h>
#include <Windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <io.h> 

#include <fstream>
using namespace std;

class Card
{
private:
	size_t nominal;
	string type;
	string name;
public:
	Card(size_t n, string t, string _n);

	size_t getNominal() const;
	string getType() const;
	string getName() const;

	void setType(string t);

	void Print_Card() const;
};