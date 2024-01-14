#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;

class File {
public:
	virtual void Display(const char* path) const {
		ifstream fin;
		char s;
		fin.open(path);
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin.get(s);
				cout << s;
			}
			cout << endl;
		}
		else {
			throw exception("file was not opened\n");
		}
		fin.close();
	}
};

class File_ASCII : public File {
public:
	void Display(const char* path) const {
		ifstream fin;
		char s;
		fin.open(path);
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin.get(s);
				if (s == ' ') cout << '\n';
				else cout << int(s) << ' ';
			}
			cout << endl;
		}
		else {
			throw exception("file was not opened\n");
		}
		fin.close();
	}
};

class File_Bin : public File {
public:
	void Display(const char* path) const {
		ifstream fin;
		char s;
		fin.open(path);
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin.get(s);
				if (s == ' ') cout << '\n';
				else cout << bitset<8>(int(s)) << ' ';
			}
			cout << endl;
		}
		else {
			throw exception("file was not opened\n");
		}
		fin.close();
	}
};

int main()
{
	try {
		const char* fname = "myfile.txt";
		File f;
		File_ASCII f_a;
		File_Bin f_b;

		cout << "+=====================================================================================+" << endl;
		cout << "Standart read file: " << endl << endl;
		f.Display(fname);
		cout << "+=====================================================================================+" << endl << endl << endl;

		cout << "+=====================================================================================+" << endl;
		cout << "ASCII read file (each word in new line for better reading): " << endl << endl;
		f_a.Display(fname);
		cout << "+=====================================================================================+" << endl << endl << endl;

		cout << "+=====================================================================================+" << endl;
		cout << "Binary read file (each word in new line for better reading): " << endl << endl;
		f_b.Display(fname);
		cout << "+=====================================================================================+" << endl << endl << endl;
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}