#include <iostream>
#include <string>
using namespace std;

struct PIB {
	string name, surname, middlename; //ім'я, прізвище, по батькові
};
struct Date {
	size_t day, month;
	int year;
};
struct Ed_Institution {
	string inst_name, inst_city, inst_country;
};
class Student {
private:
	PIB pib;
	Date b_date;
	string phone_num, city, country;
	Ed_Institution inst;
	size_t group_num;
	bool is_Leap(int year) {
		bool leap = false;
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
			leap = true;
		}
		else {
			leap = false;
		}
		return leap;
	}
public:
	Student(string n = "Name", string sn = "Surname", string mn = "Middlename", size_t bdd = 1, size_t bdm = 1, int bdy = 1, string pn = "1",          //конструктор для всіх змінних класу
		string ct = "City", string cntr = "Country", string instnm = "University", string instct = "City", string instcntr = "Country", size_t gn = 0) {
		pib.name = n; pib.surname = sn; pib.middlename = mn;
		b_date.day = bdd; b_date.month = bdm; b_date.year = bdy;
		phone_num = pn; city = ct; country = cntr;
		inst.inst_name = instnm; inst.inst_city = instct; inst.inst_country = instcntr;
		group_num = gn;
	}
	PIB get_PIB() const {
		return pib;
	}
	Date get_BD() const {
		return b_date;
	}
	string get_PhoneNum() const {
		return phone_num;
	}
	string get_City() const {
		return city;
	}
	string get_Country() const {
		return country;
	}
	Ed_Institution get_Inst() const {
		return inst;
	}
	void set_BD() {
		cout << "Student's day of birth: "; cin >> b_date.day;
		cout << "Student's month of birth: "; cin >> b_date.month;
		cout << "Student's year of birth: "; cin >> b_date.year;
		getchar();
		if (b_date.month < 1 || b_date.month > 12) b_date.month = 1;
		if (b_date.day < 1 || b_date.day > 31) b_date.day = 1;
		else if (b_date.day > 29 && b_date.month == 2 && is_Leap(b_date.year)) b_date.day = 1;
		else if (b_date.day > 28 && b_date.month == 2 && !is_Leap(b_date.year)) b_date.day = 1;
	}

	void Show_Student() const {
		cout << "Student's Name: " << pib.name << endl;
		cout << "Student's Surname: " << pib.surname << endl;
		cout << "Student's Middlename: " << pib.middlename << endl;
		cout << "Student's Date of birth (D.M.Y): " << b_date.day << "." << b_date.month << "." << b_date.year << endl;
		cout << "Student's Phone Number: " << phone_num << endl;
		cout << "Student's City: " << city << endl;
		cout << "Student's Country: " << country << endl;
		cout << "Education Institution's Name: " << inst.inst_name << endl;
		cout << "Education Institution's City: " << inst.inst_city << endl;
		cout << "Education Institution's Country: " << inst.inst_country << endl;
		cout << "Student's Group Number: " << group_num << endl;
	}
	void Input_Student() {
		cout << "Student's Name: "; getline(cin, pib.name);
		cout << "Student's Surname: "; getline(cin, pib.surname);
		cout << "Student's Middlename: "; getline(cin, pib.middlename);
		set_BD();
		cout << "Student's Phone Number: "; getline(cin, phone_num);
		cout << "Student's City: "; getline(cin, city);
		cout << "Student's Country: "; getline(cin, country);
		cout << "Education Institution's Name: "; getline(cin, inst.inst_name);
		cout << "Education Institution's City: "; getline(cin, inst.inst_city);
		cout << "Education Institution's Country: "; getline(cin, inst.inst_country);
		cout << "Student's Group Number: "; cin >> group_num;
	}
};

class Dot {
private:
	int x, y, z;
public:
	Dot(int x = 0, int y = 0, int z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	int getZ() const {
		return z;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setZ(int z) {
		this->z = z;
	}

	void Show_Dot() const {
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;
	}

	void Save(const char* fname, int x, int y, int z) {
		FILE* fs = NULL;
		int nError = fopen_s(&fs, fname, "wt");
		if (nError) {
			cout << "Error write file: " << fname << "\tError: " << nError << endl;
			exit(3);
		}
		fprintf(fs, "%20i", x);
		fprintf(fs, "%20i", y);
		fprintf(fs, "%20i", z);
		fclose(fs);
	}
	Dot Load(const char* fname) {
		FILE* fs = NULL;
		int nError = fopen_s(&fs, fname, "rt");
		if (nError) {
			cout << "Error read file: " << fname << "\tError: " << nError << endl;
			exit(3);
		}
		Dot dt;
		fscanf(fs, "%i", &dt.x);
		fscanf(fs, "%i", &dt.y);
		fscanf(fs, "%i", &dt.z);
		fclose(fs);
		return dt;
	}
};

int main() {
	{
		//Завдання 1
		Student student;
		cout << "Enter information about student: " << endl;
		student.Input_Student();

		cout << endl << "Information about student: " << endl;
		student.Show_Student();
	}
	{
		//Завдання 2
		Dot tochka, tochka2;
		int x, y, z;
		cout << "Enter information about dot: " << endl;
		cout << "X: "; cin >> x;
		cout << "Y: "; cin >> y;
		cout << "Z: "; cin >> z;
		tochka.setX(x);
		tochka.setY(y);
		tochka.setZ(z);

		cout << "Coordinates of dot: " << endl;
		tochka.Show_Dot();

		const char* coord = "coord.txt";
		tochka.Save(coord, x, y, z);
		tochka2 = tochka2.Load(coord);

		cout << "Same coordinates of other dot that were read from file: " << endl;
		tochka2.Show_Dot();
	}
	return 0;
}
