#pragma once
#include <string>
#include "Date.h"
class Student
{
private:
	string surname;

	Date birth_date;
public:
	Student(string sn, Date bd);

	Student();

	string getSurname() const;

	Date getBirthDate() const;

	void setSurname(string _surname);

	void setBirthDate(Date _birth_date);

	void Show_Student() const;

	friend ostream& operator<<(ostream& out, const Student& D);
};