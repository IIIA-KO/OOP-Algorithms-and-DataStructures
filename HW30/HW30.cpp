#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Train {
	int number, hour = 0, minute = 0;
	string designation_station;
public:
	Train(int n, int h, int m, string ds) {
		number = n;
		hour = h;
		minute = m;
		designation_station = ds;
	}

	int getNum() const { return number; }
	int getHour() const { return hour; }
	int getMinute() const { return minute; }
	string getStation() const { return designation_station; }

	void setNum(int n) { number = n; }
	void setHour(int h) { hour = h; }
	void setMinute(int m) { minute = m; }
	void setStation(string ds) { designation_station = ds; }

	void Show() const {
		cout << "| " << setw(10) << number << " | " << setw(8) << hour << ":" << minute << " | " << setw(35) << designation_station << " |\n";
	}
};

ostream& operator<<(ostream& out, const vector<Train>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].Show();
	}
	cout << endl;
	return out;
}

void Show_exact(int num, vector<Train> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].getNum() == num) {
			arr[i].Show();
			return;
		}
	}
	cout << "ERROR: There is no such train in array" << endl;
}

int main()
{
	cout << "======================================================--Automated Railway Station Information System--======================================================" << endl << endl;
	vector<Train> railway;
	int num, h = 0, m = 0;
	string station;

	cout << "ENTER INFORMATION: " << endl;
	cout << "Add 3 trains to array: \n";
	for (int i = 0; i < 3; i++) {
		cout << "Enter " << i + 1 << " train: \n";
		cout << "Enter number of train (number >= 0. Please, enter correct value for number. Otherwize it'll be seted to zero): "; cin >> num;
		cout << "Enter sending time (please, enter correct values. Otherwise these values'll be zeted to zero):\nHour: "; cin >> h;
		cout << "Minute: "; cin >> m;
		cin.get();
		cout << "Enter name of designation station: "; getline(cin, station);
		cout << endl;

		if (num < 0) num = 0;
		if (h < 0 || h > 23) h = 0;
		if (m < 0 || m > 59) m = 0;

		Train a(num, h, m, station);

		railway.push_back(a);
	}
	cout << "=========================================================================================================================================================" << endl << endl << endl;

	cout << "=========================================================================================================================================================" << endl;
	cout << "SHOW TRAIN BY NUMBER: " << endl;
	cout << "Enter the train number you want to see information about: "; cin >> num;
	Show_exact(num, railway);
	cout << "=========================================================================================================================================================" << endl << endl << endl;

	cout << "=========================================================================================================================================================" << endl;
	cout << "SHOW ARRAY: " << endl;
	cout << "Your array of trains: " << endl << railway << endl;
	cout << "=========================================================================================================================================================" << endl << endl << endl;
	
	return 0;
}