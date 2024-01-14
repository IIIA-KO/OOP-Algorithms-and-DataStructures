#include <iostream>
using namespace std;

class TryPassword {
	string password;
public:
	bool Check_Password(string pass) {
		if (pass.length() < 10) {
			throw exception("ERROR: Password too short");
			return false;
		}
		else {
			bool num = false, low = false, upper = false, sym = false;
			for (int i = 0; i < pass.length(); i++) {
				if (pass[i] >= '0' && pass[i] <= '9') num = true;
				if (pass[i] >= 'a' && pass[i] <= 'z') low = true;
				if (pass[i] >= 'A' && pass[i] <= 'Z') upper = true;
				if (pass[i] >= '!' && pass[i] <= '/') sym = true;
			}
			if (num == false)
				throw exception("ERROR: Password dosn't contain numbers ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')");

			if (low == false)
				throw exception("ERROR: Password doesn't contain lowercase letters");

			if (upper == false)
				throw exception("ERROR: Password doesn't contain uppercase letters");

			if (sym == false)
				throw exception("ERROR: Password doesn't contain special symbols ('!', '\"', '#', '$', '%', '&', ' \' ', '(', ')', '*', '+', '-', '.', '/')");
		}
		return true;
	}
	TryPassword(string pass) {
		if (!Check_Password(pass)) {
			throw exception("ERROR: Passwors is invalid");
		}
		else {
			cout << "Your password was successfuly created !" << endl;
			password = pass;
		}
	}
};

int main()
{
	try {
		string password;
		cout << "CREATE PASSWORD" << endl;
		cout << "Password must be longer than 10 symbols\nPassword must contain at least one lowercase letter !\nPassword must contain at least one uppercase letter\nPassword must containt at least one special symbol ('!', '\"', '#', '$', '%', '&', ' \' ', '(', ')', '*', '+', '-', '.', '/')\nPassword must contain at least one number\n";
		cout << "Enter password: "; cin >> password;

		TryPassword p(password);
	}
	catch (const exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}