#include "Student.h"

Student::Student(string sn, Date bd) {
	surname = sn;
	birth_date = bd;
}

Student::Student()
{
	surname = "";
	birth_date.setDay(0);
	birth_date.setMonth(0);
	birth_date.setYear(0);
}

string Student::getSurname() const {
	return surname;
}

Date Student::getBirthDate() const {
	return birth_date;
}

void Student::setSurname(string _surname) {
	surname = _surname;
}

void Student::setBirthDate(Date _birth_date) {
	birth_date = _birth_date;
}

void Student::Show_Student() const {
	cout << "Surname: " << surname << " | Birth Date: " << birth_date << endl;
}

ostream& operator<<(ostream& out, const Student& D) {
	D.Show_Student();
	return out;
}