#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
using namespace std;

template <class key_type, class value_type, class comparator>
ostream& operator<<(ostream& out, const map<key_type, value_type, comparator>& arr) {
	for (auto p : arr)
		cout << setw(15) << p.first << " | " << setw(5) << p.second << endl;
	out << endl;
	return out;
}

size_t CountAllaWords(const string& text) {
	size_t all_words = 0;
	int i = 0;
	while (text[i]) {
		if (text[i] == ' ')
			all_words++;
		i++;
	}
	return all_words + 1;
}
string ReadText(const string& fname) {
	ifstream fin("text.txt");
	if (!fin.is_open()) {
		throw exception("file was not opened\n");
	}
	string text;
	getline(fin, text);
	fin.close();
	return text;
}
void WriteResult(const string& fname, int words, const map<string, int>& arr) {
	ofstream fout("result.txt");
	if (!fout.is_open()) {
		throw exception("file was not opened\n");
	}
	int percent = words * 0.1;
	for (auto it = arr.begin(); it != arr.end(); it++)
		if (it->second >= percent)
			fout << it->first << " " << it->second << endl;
	fout.close();
}

int main()
{
	map <string, int> arr;

	cout << "+===============================================================================================================+" << endl;
	string text = ReadText("text.txt");
	cout << "Text:\n" << text << endl;
	cout << "+===============================================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================================+" << endl;
	size_t all_words = CountAllaWords(text);
	cout << "Words Count:" << all_words << endl;
	cout << "+===============================================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================================+" << endl;
	istringstream ss(text);		//скажу чесно - я таку штуку загуглив
	string tmp;
	while (ss >> tmp)
		arr[tmp]++;

	cout << "Map: " << endl << arr;
	cout << "+===============================================================================================================+" << endl << endl << endl;


	cout << "+===============================================================================================================+" << endl;
	cout << "Most popular words: " << endl;

	WriteResult("result.txt", all_words, arr);
	int percent = all_words * 0.1;
	for (auto it = arr.begin(); it != arr.end(); it++)
		if (it->second >= percent)
			cout << setw(15) << (*it).first << " | " << setw(5) << (*it).second << endl;
	cout << "+===============================================================================================================+" << endl << endl << endl;
	return 0;
}