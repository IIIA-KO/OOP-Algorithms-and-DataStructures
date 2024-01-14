#include "Game.h"

bool is_file_empty(ifstream& f)
{
	return f.peek() == ifstream::traits_type::eof();
}
bool is_eng(const vector<string> l) {
	return l[1][0] >= 65 && l[1][0] <= 90;
}

void PrintBotDeck(const deque<Card>& bd, const vector<string>& l) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, { 0, 1 });
	cout << l[44] << endl;
	cout << l[43] << bd.size() << endl;
	for (auto p : bd) {
		p.Print_Card();
	}
	if (is_eng(l)) {
		cout << l[49];
	}
	else {
		cout << l[46];
	}
}
void PrintPlayerDeck(const deque<Card>& ud, const vector<string>& l) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(h, { 150, 1 });
	cout << l[45] << endl;

	SetConsoleCursorPosition(h, { 150, 2 });
	cout << l[43] << ud.size() << endl;
	short i = 3;
	for (auto p : ud) {
		SetConsoleCursorPosition(h, { 150, i });
		p.Print_Card();
		++i;
	}
	SetConsoleCursorPosition(h, { 150, i });
	if (is_eng(l)) {
		cout << l[49];
	}
	else {
		cout << l[46];
	}
}
void PrintGame(const deque<Card>& ud, const deque<Card>& bd, const vector<string>& l, const Card& utmp, const Card& btmp) {
	PrintBotDeck(bd, l);
	PrintPlayerDeck(ud, l);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	short col = 70;

	SetConsoleCursorPosition(h, { col, 13 });
	cout << l[47] << endl;
	SetConsoleCursorPosition(h, { col, 14 });
	btmp.Print_Card();

	SetConsoleCursorPosition(h, { col, 23 });
	utmp.Print_Card();
	SetConsoleCursorPosition(h, { col, 24 });
	cout << l[48] << endl;
}

vector<Score> loadScores(const string& fname) {
	vector<Score> tmparr{};
	Score tmp;
	string tmpname = "";
	int tmpmoves = 0;

	ifstream f(fname, ios::in);
	if (!f.is_open()) {
		throw exception("Error: File was not opened");
	}

	if (is_file_empty(f)) {
		return tmparr;
		f.close();
	}

	int size = 0;
	(f >> size).get();


	for (int i = 0; i < size; i++) {
		getline(f, tmpname);
		tmp.setName(tmpname);

		(f >> tmpmoves).get();
		tmp.setMoves(tmpmoves);

		tmparr.push_back(tmp);
	}
	return tmparr;
}
void saveScoresArr(vector<Score>& sarr, const string& fname) {
	ofstream f(fname);
	if (!f.is_open()) {
		throw exception("Error: File was not opened");
	}
	f << sarr.size() << endl;
	for (int i = 0; i < sarr.size(); i++) {
		f << sarr[i].getName() << endl;
		f << sarr[i].getMoves() << endl;
	}
	f.close();
}
void saveScore(const string& fname, vector<Score>& sarr, const Score& s) {
	sarr.push_back(s);
	saveScoresArr(sarr, fname);
}

vector<string> LanguageMenu() {
	vector<string> language;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	const char* textMenu[]{
			"English",
			"Українська"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t select = 0;

	string fname, tmp;

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 0: {
			fname = "en.txt";
			ifstream fin(fname, ios::in);
			if (!fin.is_open()) {
				throw exception("Error: File was not opened");
			}
			while (getline(fin, tmp)) {
				language.push_back(tmp);
			}
			fin.close();
			return language;
		}

		case 1: {
			fname = "ua.txt";
			ifstream fin(fname, ios::in);
			if (!fin.is_open()) {
				throw exception("Error: File was not opened");
			}
			while (getline(fin, tmp)) {
				language.push_back(tmp);
			}
			fin.close();
			return language;
		}
		}
	}
}

void SaveMenu(const vector<string>& l, const string& fname, vector<Score>& sarr, const int& moves) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	const char* textMenu[]{
			l[12].c_str(),
			l[13].c_str()
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");

		switch (select)
		{
		case 0:
		{
			string name;
			SetConsoleCursorPosition(h, { 65, 10 });
			cout << l[14]; getline(cin, name);
			saveScore(fname, sarr, { name, moves });
			return;
		}

		case 1:
			return;
		}
	}
}

void doGame(vector<Score>& sarr, const string& fname, vector<string> lang)
{
	srand(time(0));
	mt19937 generator(time(0));

	Deck mainDeck(lang);
	shuffle(mainDeck.getDeck().begin(), mainDeck.getDeck().end(), generator);

	deque<Card> userDeck{ mainDeck.getDeck().begin(), mainDeck.getDeck().begin() + mainDeck.getDeck().size() / 2 };
	deque<Card> botDeck{ mainDeck.getDeck().begin() + mainDeck.getDeck().size() / 2, mainDeck.getDeck().end() };


	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


	PrintBotDeck(botDeck, lang);
	PrintPlayerDeck(userDeck, lang);
	SetConsoleCursorPosition(h, { 65, 37 });
	cout << lang[5] << endl;
	cin.get();

	int moves = 0;

	while (!userDeck.empty() && !botDeck.empty()) {
		deque<Card> table{};
		do
		{
			Card utmp = userDeck.front();
			Card btmp = botDeck.front();
			userDeck.pop_front();
			botDeck.pop_front();
			table.push_front(utmp);
			table.push_front(btmp);

			if (utmp.getNominal() == 6 && btmp.getNominal() == 14) {
				std::shuffle(table.begin(), table.end(), generator);
				std::copy(table.begin(), table.end(), back_inserter(userDeck));

				system("cls");
				PrintGame(userDeck, botDeck, lang, utmp, btmp);

				if (is_eng(lang)) {
					SetConsoleCursorPosition(h, { 72, 18 });
				}
				else {
					SetConsoleCursorPosition(h, { 69, 18 });
				}
				cout << lang[6] << table.size() << lang[8] << endl;

				SetConsoleCursorPosition(h, { 65, 37 });
				cout << lang[24] << endl;
				cin.get();
				moves++;
				break;
			}
			if (btmp.getNominal() == 6 && utmp.getNominal() == 14) {
				std::shuffle(table.begin(), table.end(), generator);
				std::copy(table.begin(), table.end(), back_inserter(botDeck));

				system("cls");
				PrintGame(userDeck, botDeck, lang, utmp, btmp);

				if (is_eng(lang)) {
					SetConsoleCursorPosition(h, { 72, 18 });
				}
				else {
					SetConsoleCursorPosition(h, { 69, 18 });
				}
				cout << lang[7] << table.size() << lang[8] << endl;

				SetConsoleCursorPosition(h, { 65, 37 });
				cout << lang[24] << endl;
				cin.get();
				moves++;
				break;
			}

			if (utmp.getNominal() > btmp.getNominal() && utmp.getNominal() != 6 && btmp.getNominal() != 14) {
				std::shuffle(table.begin(), table.end(), generator);
				std::copy(table.begin(), table.end(), back_inserter(userDeck));

				system("cls");
				PrintGame(userDeck, botDeck, lang, utmp, btmp);

				if (is_eng(lang)) {
					SetConsoleCursorPosition(h, { 72, 18 });
				}
				else {
					SetConsoleCursorPosition(h, { 69, 18 });
				}
				cout << lang[6] << table.size() << lang[8] << endl;

				SetConsoleCursorPosition(h, { 65, 37 });
				cout << lang[24] << endl;
				cin.get();
				moves++;
				break;
			}
			if (btmp.getNominal() > utmp.getNominal() && btmp.getNominal() != 6 && utmp.getNominal() != 14) {
				std::shuffle(table.begin(), table.end(), generator);
				std::copy(table.begin(), table.end(), back_inserter(botDeck));

				system("cls");
				PrintGame(userDeck, botDeck, lang, utmp, btmp);

				if (is_eng(lang)) {
					SetConsoleCursorPosition(h, { 72, 18 });
				}
				else {
					SetConsoleCursorPosition(h, { 69, 18 });
				}
				cout << lang[7] << table.size() << lang[8] << endl;

				SetConsoleCursorPosition(h, { 65, 37 });
				cout << lang[24] << endl;
				cin.get();
				moves++;
				break;
			}
			else {
				system("cls");
				SetConsoleCursorPosition(h, { 62, 10 });

				cout << lang[9] << endl;

				SetConsoleCursorPosition(h, { 0, 0 });
				PrintGame(userDeck, botDeck, lang, utmp, btmp);

				SetConsoleCursorPosition(h, { 65, 37 });
				cout << lang[24] << endl;
				cin.get();
				moves++;
			}
		} while (!userDeck.empty() && !botDeck.empty());
	}

	system("cls");
	if (userDeck.empty()) {
		SetConsoleCursorPosition(h, { 25, 20 });
		cout << lang[11] << endl;
		SetConsoleCursorPosition(h, { 75, 21 });
		cout << lang[41] << moves << lang[42] << endl;
	}
	if (botDeck.empty()) {
		SetConsoleCursorPosition(h, { 25, 20 });
		cout << lang[10] << endl;
		SetConsoleCursorPosition(h, { 75, 21 });
		cout << lang[40] << moves << lang[42] << endl;
	}
	SetConsoleCursorPosition(h, { 65, 37 });
	cout << lang[24] << endl;
	cin.get();

	SaveMenu(lang, fname, sarr, moves);
}

void Game_Menu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	vector<string> language = LanguageMenu();

	string fname = "Scores.txt";

	vector<Score> scores_arr = loadScores(fname);

	const char* textMenu[]{
			language[1].c_str(),
			language[2].c_str(),
			language[3].c_str(),
			language[4].c_str()
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	size_t select = 0;

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 0:
			doGame(scores_arr, fname, language);
			break;

		case 1:
			SetConsoleCursorPosition(h, { 25, 8 });
			cout << language[15] << endl;

			SetConsoleCursorPosition(h, { 25,10 });
			cout << language[16] << endl;

			SetConsoleCursorPosition(h, { 25, 12 });
			cout << language[17] << endl;

			SetConsoleCursorPosition(h, { 25, 14 });
			cout << language[18] << endl;

			SetConsoleCursorPosition(h, { 25, 16 });
			cout << language[19] << endl;

			SetConsoleCursorPosition(h, { 25, 18 });
			cout << language[20] << endl;

			SetConsoleCursorPosition(h, { 25, 20 });
			cout << language[21] << endl;

			SetConsoleCursorPosition(h, { 25, 22 });
			cout << language[22] << endl;

			SetConsoleCursorPosition(h, { 25, 24 });
			cout << language[23] << endl;

			SetConsoleCursorPosition(h, { 65, 26 });
			cout << language[24] << endl;
			cin.get();
			break;

		case 2:
			if (scores_arr.size() == 0) {
				SetConsoleCursorPosition(h, { 75, 15 });
				cout << "Warning: File is empty" << endl;
				SetConsoleCursorPosition(h, { 72, 35 });
				cout << language[24] << endl;
				cin.get();
				break;
			}
			else {
				SetConsoleCursorPosition(h, { 70, 4 });
				cout << "| " << setw(20) << language[38] << " | " << setw(6) << language[39] << " |\n";
				for (int i = 0; i < scores_arr.size(); i++) {
					SetConsoleCursorPosition(h, { 70, short(5 + i) });
					cout << "| " << setw(20) << scores_arr[i].getName() << " | " << setw(6) << scores_arr[i].getMoves() << " |\n";
				}
			}
			SetConsoleCursorPosition(h, { 72, 35 });
			cout << language[24] << endl;
			cin.get();
			break;

		case 3:
			exit(0);
		}
	}
}