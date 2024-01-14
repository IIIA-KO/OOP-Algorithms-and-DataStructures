#pragma once
#include "Card.h"
#include <vector>
class Deck
{
private:
	vector<Card> deck;
public:

	Deck(const vector<string>& l);

	vector<Card>& getDeck();

	void Print_Deck() const;
};