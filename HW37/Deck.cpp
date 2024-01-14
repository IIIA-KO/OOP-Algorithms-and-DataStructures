#include "Deck.h"

Deck::Deck(const vector<string>& l) {
	Card tmp6(6, l[34], l[25]);
	Card tmp7(7, l[34], l[26]);
	Card tmp8(8, l[34], l[27]);
	Card tmp9(9, l[34], l[28]);
	Card tmp10(10, l[34], l[29]);
	Card tmpV(11, l[34], l[30]);
	Card tmpD(12, l[34], l[31]);
	Card tmpK(13, l[34], l[32]);
	Card tmpT(14, l[34], l[33]);

	deck.push_back(tmp6);
	deck.push_back(tmp7);
	deck.push_back(tmp8);
	deck.push_back(tmp9);
	deck.push_back(tmp10);
	deck.push_back(tmpV);
	deck.push_back(tmpD);
	deck.push_back(tmpK);
	deck.push_back(tmpT);

	tmp6.setType(l[35]);
	tmp7.setType(l[35]);
	tmp8.setType(l[35]);
	tmp9.setType(l[35]);
	tmp10.setType(l[35]);
	tmpV.setType(l[35]);
	tmpD.setType(l[35]);
	tmpK.setType(l[35]);
	tmpT.setType(l[35]);

	deck.push_back(tmp6);
	deck.push_back(tmp7);
	deck.push_back(tmp8);
	deck.push_back(tmp9);
	deck.push_back(tmp10);
	deck.push_back(tmpV);
	deck.push_back(tmpD);
	deck.push_back(tmpK);
	deck.push_back(tmpT);

	tmp6.setType(l[36]);
	tmp7.setType(l[36]);
	tmp8.setType(l[36]);
	tmp9.setType(l[36]);
	tmp10.setType(l[36]);
	tmpV.setType(l[36]);
	tmpD.setType(l[36]);
	tmpK.setType(l[36]);
	tmpT.setType(l[36]);

	deck.push_back(tmp6);
	deck.push_back(tmp7);
	deck.push_back(tmp8);
	deck.push_back(tmp9);
	deck.push_back(tmp10);
	deck.push_back(tmpV);
	deck.push_back(tmpD);
	deck.push_back(tmpK);
	deck.push_back(tmpT);

	tmp6.setType(l[37]);
	tmp7.setType(l[37]);
	tmp8.setType(l[37]);
	tmp9.setType(l[37]);
	tmp10.setType(l[37]);
	tmpV.setType(l[37]);
	tmpD.setType(l[37]);
	tmpK.setType(l[37]);
	tmpT.setType(l[37]);

	deck.push_back(tmp6);
	deck.push_back(tmp7);
	deck.push_back(tmp8);
	deck.push_back(tmp9);
	deck.push_back(tmp10);
	deck.push_back(tmpV);
	deck.push_back(tmpD);
	deck.push_back(tmpK);
	deck.push_back(tmpT);
}

vector<Card>& Deck::getDeck() {
	return deck;
}

void Deck::Print_Deck() const
{
	for (int i = 0; i < deck.size(); i++) {
		deck[i].Print_Card();
	}
}