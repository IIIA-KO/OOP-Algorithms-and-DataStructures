#pragma once
#include "String.h"
#include "Date.h"
class Student
{
private:
	String surname;
	Date birth_date;
public:
	Student(String sn, Date bd);
	Student();
	String getSurname() const;
	Date getBirthDate() const;
	void setSurname(String _surname);
	void setBirthDate(Date _birth_date);

	void Show_Student() const;
	friend ostream& operator<<(ostream& out, const Student& D);
};