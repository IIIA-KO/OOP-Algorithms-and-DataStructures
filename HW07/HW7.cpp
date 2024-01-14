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
	double s, price;
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
	Flat(const char* nf, double sf, double pf) {
		num = _strdup(nf);
		s = sf;
		price = pf;
		count_humans = 0;
		humans = 0;
	}
	Flat(const Flat& f) {
		price = f.price;
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
		price = f.price;
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
		cout << "Number: " << num << " | " << "Square: " << s << " | " << "Price: " << price << " | " << "Residents: " << endl;
		for (int i = 0; i < count_humans; i++) {
			cout << "Resident " << i + 1 << ")" << endl;
			humans[i]->Show_Human();
			cout << endl;
		}
	}

	bool operator==(const Flat& F) {
		return s == F.s;
	}
	bool operator>(const Flat& F) {
		return price > F.price;
	}
	bool operator<(const Flat& F) {
		return price < F.price;
	}
	Flat& operator=(const Flat& F) {
		if (this != &F) {
			price = F.price;
			s = F.s;
			count_humans = F.count_humans;
			this->num = _strdup(F.num);
			this->humans = new Human * [F.count_humans];
			for (int i = 0; i < F.count_humans; i++) {
				humans[i] = new Human(*F.humans[i]);
			}
		}
		return *this;
	}
};

class Overcoat {
	double price;
	char* type;
public:
	~Overcoat() {
		delete[] type;
	}
	Overcoat() {
		price = 0;
		type = NULL;
	}
	Overcoat(double p, const char* t) {
		price = p;
		this->type = _strdup(t);
	}
	Overcoat(const Overcoat& O) : Overcoat(O.price, O.type) {}
	Overcoat(Overcoat&& O) : Overcoat(O) { O.type = NULL; }

	int get_Price() const {
		return price;
	}
	char* get_Type() const {
		return type;
	}
	void set_Price(int p) {
		price = p;
	}
	void set_Type(const char* t) {
		type = _strdup(t);
	}

	void Show_Overcoat() const {
		cout << "Price: " << price << " | " << "Type: " << type << endl;
	}

	bool operator==(const Overcoat& O) const {
		return type == O.type;
	}
	bool operator> (const Overcoat& O) const {
		if (strcmp(type, O.type) == 0)
			return price > O.price;
		else return 0;
	}
	bool operator< (const Overcoat& O) const {
		if (strcmp(type, O.type) == 0)
			return price < O.price;
		else return 0;
	}
	Overcoat& operator= (const Overcoat& O) {
		if (this != &O) {
			price = O.price;
			delete[] type;
			type = _strdup(O.type);
		}
		return *this;
	}
};

int main()
{
    //Overcoat
    {
        Overcoat palto(123.50, "Palto"), kurtka(99.80, "Kurtka"), puhovyk(150.50, "Puhovyk");
        Overcoat palto2(116.30, "Palto"), kurtka2(100.20, "Kurtka"), puhovyk2(103.10, "Puhovyk");

		cout << "Overcoat 1: "; palto.Show_Overcoat();
		cout << "Overcoat 2: "; puhovyk.Show_Overcoat();
		cout << "Is Palto equal to Puhovyk ?" << endl;
		cout << (palto == puhovyk) << endl << "No " << endl << endl;

		cout << "Over coat 3: "; palto2.Show_Overcoat();
		cout << "Over coat 4: "; puhovyk2.Show_Overcoat();
		cout << "Overcoat3 = Overcoat4" << endl;
		palto2 = puhovyk2;
		cout << "Over coat 3: "; palto2.Show_Overcoat();
		cout << "Over coat 4: "; puhovyk2.Show_Overcoat();
		cout << endl;

		cout << "Overcoat 5: "; kurtka.Show_Overcoat();
		cout << "Overcoat 6: "; kurtka2.Show_Overcoat();
		cout << "Overcoat5 price < Overcoat6 price ?" << endl;
		cout << (kurtka < kurtka2) << endl << "Yes" << endl << endl;
    }

    //Flat
    {
		Flat A("101", 250, 500000), B("102", 150, 250000), C("103", 150, 230000);
		cout << "Flat A: "; A.Show_Flat();
		cout << "Flat B: "; B.Show_Flat();
		cout << "Flat C: "; C.Show_Flat();

		cout << "Is A square > B square ?" << endl;
		cout << (A < B) << endl << "No" << endl << endl;

		cout << "B square == C square ?" << endl;
		cout << (B == C) << endl << "Yes" << endl << endl;

		//cout << "Flat B: "; B.Show_Flat();
		//cout << "Flat C: "; C.Show_Flat();
		cout << "B = C" << endl;
		B = C;
		cout << "Flat B: "; B.Show_Flat();
		cout << "Flat C: "; C.Show_Flat();
		cout << endl;
    }
    return 0;
}