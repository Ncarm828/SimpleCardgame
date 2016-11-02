// File: Card.h
// Declaration of struct for holding playing card

#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include "stdafx.h"

using namespace std;

enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
enum Suit { Clubs, Diamonds, Hearts, Spades };

struct Card {
	Rank rank;
	Suit suit;
};

static string rankStr[] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
static string suitStr[] = { "S","H","D","C" };

#endif
