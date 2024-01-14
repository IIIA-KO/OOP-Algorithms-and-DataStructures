#include "HashTable.h"

class Guide {
	size_t n;
	HashTable array;
public:
	Guide(size_t _n) : n(_n), array(n){}

	void push(const Firm& t) {
		array.push(t);
	}
	void Show() const {
		array.Show(); 
	}
	void SaveArray(const char* fname) {
		array.Save(fname);
	}
	void SaveElement(const char* fname, const Firm& f) {
		array.push(f);
		array.Save(fname);
	}
	void Clear() {
		array.Clear();
	}
	void LoadArray(const char* fname) {
		array.Load(fname);
	}

	void findName(string name) {
		array.find_by_name(name);
	}
	void findOwner(string owner) {
		array.find_by_owner(owner);
	}
	void findPhone(string phone) {
		array.find_by_phone(phone);
	}
	void findAdress(string adress) {
		array.find_by_adress(adress);
	}
	void findActivity(string activity) {
		array.find_by_activity(activity);
	}
};

int main()
{
	Guide arr(10);
	const char* fname = "Guide.txt";

	cout << "+==================================================================================================================================================+" << endl;
	Firm a("IT", "John Morgan", "+099-412-44-11", "Kyivska 32 st.", "IT");
	Firm b("Pfizer", "Mary Bells", "+099-412-44-12", "Odesska 48 st.", "Medicine");
	Firm c("Oil LTD", "Samuel Marston", "+099-412-44-13", "Lvivska 36 st.", "Resourses");
	Firm d("Uber", "Mike Cormak", "+099-412-44-14", "Dniprovska 12 st.", "Transport");
	arr.push(a);
	arr.push(b);
	arr.push(c);
	arr.push(d);
	
	cout << "Guide of Firms: " << endl;
	arr.Show();
	arr.SaveArray(fname);
	cout << "Guide was saves to file" << endl;
	cout << "+==================================================================================================================================================+" << endl << endl << endl;

	cout << "+==================================================================================================================================================+" << endl;
	string str;
	Firm e;
	cout << "Enter new Firm: \n";
	cout << "Name: "; getline(cin, str);
	e.setName(str);

	cout << "Owner: "; getline(cin, str);
	e.setOwner(str);

	cout << "Phone: "; getline(cin, str);
	e.setPhone(str);

	cout << "Adress: "; getline(cin, str);
	e.setAdress(str);

	cout << "Activity: "; getline(cin, str);
	e.setActivity(str);

	arr.SaveElement(fname, e);
	arr.Show();
	cout << "+==================================================================================================================================================+" << endl << endl << endl;

	cout << "+==================================================================================================================================================+" << endl << endl << endl;
	cout << "Find by: \n";
	cout << "Name: ";
	getline(cin, str);
	arr.findName(str);

	cout << "Owner: "; getline(cin, str);
	arr.findOwner(str);

	cout << "Phone: "; getline(cin, str);
	arr.findPhone(str);

	cout << "Adress: "; getline(cin, str);
	arr.findAdress(str);

	cout << "Activity: "; getline(cin, str);
	arr.findActivity(str);
	cout << "+==================================================================================================================================================+" << endl << endl << endl;

	cout << "+==================================================================================================================================================+" << endl;
	cout << "Load from file: " << endl;
	cout << "Guide was cleared\nGuide (empty): " << endl;
	arr.Clear();
	arr.Show();
	arr.LoadArray(fname);
	cout << "Loaded Guide: " << endl;
	arr.Show();
	cout << "+==================================================================================================================================================+" << endl << endl << endl;
	return 0;
}