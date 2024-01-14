#pragma once
#include "Menu.h"
#include "Score.h"
#include <deque>
#include <random>

bool is_file_empty(ifstream& f);

bool is_eng(const vector<string> l);

void PrintBotDeck(const deque<Card>& bd, const vector<string>& l);

void PrintPlayerDeck(const deque<Card>& ud, const vector<string>& l);

void PrintGame(const deque<Card>& ud, const deque<Card>& bd, const vector<string>& l, const Card& utmp, const Card& btmp);

vector<Score> loadScores(const string& fname);

void saveScoresArr(vector<Score>& sarr, const string& fname);

void saveScore(const string& fname, vector<Score>& sarr, const Score& s);

vector<string> LanguageMenu();

void SaveMenu(const vector<string>& l, const string& fname, vector<Score>& sarr, const int& moves);

void doGame(vector<Score>& sarr, const string& fname, vector<string> lang);

void Game_Menu();