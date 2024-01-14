#include "Firm.h"

Firm::Firm(string n, string o, string p, string ad, string ac) : name(n), owner(o), phone(p), adress(ad), activity(ac) {}

Firm::Firm() {
	name = "";
	owner = "";
	phone = "";
	adress = "";
	activity = "";
}

string Firm::getName() const {
	return name;
}

string Firm::getOwner() const {
	return owner;
}

string Firm::getPhone() const {
	return phone;
}

string Firm::getAdress() const {
	return adress;
}

string Firm::getActivity() const {
	return activity;
}

void Firm::setName(string n)
{
	name = n;
}

void Firm::setOwner(string o) 
{
	owner = o;
}

void Firm::setPhone(string p)
{
	phone = p;
}

void Firm::setAdress(string ad)
{
	adress = ad;
}

void Firm::setActivity(string ac)
{
	activity = ac;
}

void Firm::Show() const {
	cout << "| " << setw(20) << name << " | " << setw(20) << owner << " | " << setw(15) << phone << " | " << setw(20) << adress << " | " << setw(20) << activity <<  " |" << endl;
}
bool Firm::operator==(const Firm& f)
{
	if (this->name == f.name && this->owner == f.owner && this->phone == f.phone && this->adress == f.adress && this->activity == f.activity) return true;
	else return false;
}
