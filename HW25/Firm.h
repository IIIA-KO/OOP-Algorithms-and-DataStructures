#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class Firm {
	string name, owner, phone, adress, activity;
public:
	Firm();
	Firm(string n, string o, string p, string ad, string ac);

	string getName() const;
	string getOwner() const;
	string getPhone() const;
	string getAdress() const;
	string getActivity() const;

	void setName(string n);
	void setOwner(string o);
	void setPhone(string p);
	void setAdress(string ad);
	void setActivity(string ac);

	void Show() const;
	bool operator==(const Firm& f);
};