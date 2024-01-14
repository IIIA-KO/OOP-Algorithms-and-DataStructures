#pragma once
#include <string>
using namespace std;
class Score
{
	string name;
	int moves;
public:
	Score(string n, int m) : name(n), moves(m) {}
	Score() : name(""), moves(0) {}

	string getName() const;
	int getMoves() const;

	void setName(string n);
	void setMoves(int m);
};