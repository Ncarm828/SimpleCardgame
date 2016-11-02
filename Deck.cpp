#include "stdafx.h"
#include <algorithm>    
#include <ctime>        
#include "Deck.h"



// *Need these for the shuffle

Rank getRank(int cardValue)
{
	return ((Rank)(cardValue % 13));
}

Suit getSuit(int cardValue)
{
	return ((Suit)(cardValue / 13));
}

Card int2Card(int value)
{
	Card C;
	C.rank = getRank(value);
	C.suit = getSuit(value);
	return(C);
}



Deck::Deck()
{
	thisCard = 0;
	for (int i = 0; i<DECKSIZE; i++)
		cards[i] = int2Card(i);
	// seed the random number generator 
	srand(unsigned(time(NULL)));
	reshuffle();
}

// random generator function:
Card Deck::dealCard()
{
	return(cards[thisCard++]);
}


void Deck::reshuffle()
{
	random_shuffle(cards, cards + 52);
	thisCard = 0;
}

ostream &operator<<(ostream &out, const Card &TheCard)
{
	out << rankStr[int(TheCard.rank)] << suitStr[int(TheCard.suit)] << " ";
	return(out);
}

void Deck::printDeck()
{
	for (int i = 0; i<52; i++) {
		cout << cards[i];
		if (i % 13 == 12)
			cout << endl;
	}
}

