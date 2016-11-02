
#ifndef _DECK_H_
#define _DECK_H_
#include <iostream>
#include "Card.h"
#include "stdafx.h"

int const DECKSIZE = 52;

using namespace std;

class Deck {
public:

	// Construct a shuffled deck.
	Deck();

	// Deal the first card off the deck. 
	// Mutator. Increments thisCard
	Card dealCard();

	// Shuffle the deck.
	// Mutator. Multiple swaps of array elements
	void reshuffle();

	// Print cards in deck
	// Facilitator. Converts enumeration types to strings.
	void printDeck();

private:
	Card cards[52];
	// Invariant: thisCard is the index of the card on top
	int thisCard;

};

// Overloaded insertion operator to define inserting a Card into an ostream
ostream &operator<<(ostream &out, const Card &TheCard);

#endif
