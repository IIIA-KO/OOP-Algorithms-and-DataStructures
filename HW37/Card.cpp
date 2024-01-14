#include "Card.h"

Card::Card(size_t n, string t, string _n) : nominal(n), type(t), name(_n) {}

size_t Card::getNominal() const
{
	return nominal;
}
string Card::getType() const
{
	return type;
}
string Card::getName() const
{
	return name;
}

void Card::setType(string t)
{
	type = t;
}

void Card::Print_Card() const
{
	if (name[0] >= 65 && name[0] <= 90) {
		cout << "[" << setw(8) << name << " - " << setw(8) << type << "]" << endl;
	}
	else {
		cout << "[ " << setw(7) << name << " - " << setw(5) << type << " ]" << endl;
	}
}