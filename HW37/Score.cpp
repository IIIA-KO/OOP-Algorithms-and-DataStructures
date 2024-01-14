#include "Score.h"

string Score::getName() const
{
	return name;
}

int Score::getMoves() const
{
	return moves;
}

void Score::setName(string n)
{
	name = n;
}

void Score::setMoves(int m)
{
	moves = m;
}
