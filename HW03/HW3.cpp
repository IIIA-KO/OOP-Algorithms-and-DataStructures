#include <iostream>
using namespace std;

class Human
{
private:
	char* name;
	int age;
	double m;
public:
	~Human() {
		if (name) {
			delete[] name;
		}
	}
	Human(const char* n, int a = 0, double m1 = 2.5) {
		name = _strdup(n);
		age = a;
		m = m1;
	}
	Human(const Human& h) {
		m = h.m;
		age = h.age;
		name = _strdup(h.name);
	}
	Human(Human&& h) {
		name = h.name;
		h.name = NULL;
		age = h.age;
		m = h.m;
	}

	void SetName(const char* n) {
		delete[] name;
		name = _strdup(n);
	}
	void Show_Human() const {
		cout << "Name: " << name << " | " << "Age: " << age << " | " << "Weight: " << m << endl;
	}
};

class Flat {
private:
	char* num;
	double s;
	Human** humans;
	int count_humans;
public:
	~Flat() {
		for (int i = 0; i < count_humans; i++) {
			delete humans[i];
		}
		delete[] num;
		delete[] humans;
	}
	Flat(const char* nf, double sf) {
		num = _strdup(nf);
		s = sf;
		count_humans = 0;
		humans = 0;
	}
	Flat(const Flat& f) {
		s = f.s;
		count_humans = f.count_humans;
		this->num = _strdup(f.num);

		this->humans = new Human * [f.count_humans];
		for (int i = 0; i < f.count_humans; i++) {
			humans[i] = new Human(*f.humans[i]);
		}
	}
	Flat(Flat&& f) {
		s = f.s;
		count_humans = f.count_humans;
		num = _strdup(f.num);
		f.num = NULL;
		for (int i = 0; i < count_humans; i++) {
			humans[i] = new Human(*f.humans[i]);
		}
		f.humans = NULL;
	}

	void Add_Human(const Human& h) {
		Human** tmp = new Human * [count_humans + 1];
		for (int i = 0; i < count_humans; i++) {
			tmp[i] = humans[i];
		}
		tmp[count_humans] = new Human(h);
		delete[] humans;
		count_humans++;
		humans = tmp;
	}
	void Del_Human(int pos) {
		Human** temp = new Human * [count_humans - 1];
		for (int i = 0; i < pos; i++)
			temp[i] = humans[i];
		for (int i = pos; i < count_humans - 1; i++)
			temp[i] = humans[i + 1];
		delete humans[pos];
		delete[] humans;
		count_humans--;
		humans = temp;
	}

	void Show_Flat() const {
		cout << "Number: " << num << " | " << "Square: " << s << " | " << "Residents: " << endl;
		for (int i = 0; i < count_humans; i++) {
			cout << "Resident " << i + 1 << ")" << endl;
			humans[i]->Show_Human();
			cout << endl;
		}
	}
};

class Building {
	char* street;
	Flat** flats;
	int count_flats;
public:
	~Building() {
		delete[] street;
		for (int i = 0; i < count_flats; i++) {
			delete flats[i];
		}
		delete[] flats;
	}
	Building(const char* street) {
		this->street = _strdup(street);
		flats = 0;
		count_flats = 0;
	}
	Building(const Building& b) {
		count_flats = b.count_flats;
		this->street = _strdup(b.street);

		this->flats = new Flat * [b.count_flats];
		for (int i = 0; i < b.count_flats; i++) {
			flats[i] = new Flat(*b.flats[i]);
		}
	}
	Building(Building&& b) {
		count_flats = b.count_flats;
		street = _strdup(b.street);
		b.street = NULL;
		for (int i = 0; i < count_flats; i++) {
			flats[i] = new Flat(*b.flats[i]);
		}
		b.flats = NULL;
	}

	void Add_Flat(const Flat& f) {
		Flat** tmp = new Flat * [count_flats + 1];
		for (int i = 0; i < count_flats; i++) {
			tmp[i] = flats[i];
		}
		tmp[count_flats] = new Flat(f);
		delete[] flats;
		count_flats++;
		flats = tmp;
	}
	void Del_Flat(int pos) {
		Flat** temp = new Flat * [count_flats - 1];
		for (int i = 0; i < pos; i++)
			temp[i] = flats[i];
		for (int i = pos; i < count_flats - 1; i++)
			temp[i] = flats[i + 1];
		delete flats[pos];
		delete[] flats;
		count_flats--;
		flats = temp;
	}

	void Show_Building() const {
		cout << "Street: " << street << endl;
		cout << "Flats: " << endl;
		for (int i = 0; i < count_flats; i++) {
			cout << "Flat " << i + 1 << ")" << endl;
			flats[i]->Show_Flat();
			cout << endl;
		}
	}
};

int main()
{
	Building B("Kyivska 123");

	Flat F1("12CB", 102.44);
	Human H1("Petro", 23, 78.4);
	F1.Add_Human(H1);
	B.Add_Flat(F1);

	Flat F2("13B", 72.2);
	Human H2("Ivan", 18, 9.8);
	F2.Add_Human(H2);
	B.Add_Flat(F2);
	cout << "Information about building: " << endl;
	B.Show_Building();

	cout << "Creating copy of 1st building..." << endl << endl;
	Building B2(B);
	cout << "Information about copy of building: " << endl;
	B2.Show_Building();
	return 0;
}