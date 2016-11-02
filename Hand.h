

#ifndef HAND_H
#define HAND_H
#include "Card.h" //file that is in use
#include "Deck.h" //deck file that is in use
#include <iostream>

using namespace std;

class Hand     //Hand class  
{
public:

	int NumberOfCards; //number of cards you have

	/******************************************************************/
	// Constructor
	//name: Hand
	//description: greats a hand that has nothing in it
	// parameters: none
	// return: none
	/******************************************************************/
	Hand();

	/******************************************************************/
	//Name: GetCard()
	//Description: Gets the card from the set cards
	//Parameters: idx - input - cards ranks and suits
	//return: poker[idx]
	/******************************************************************/
	Card GetCard(int idx) const;

	/******************************************************************/
	//Name: Operator +=()
	//Description:overload operator that gives you the next card
	//Parameters: TheNextCard - input - Has the value of The Hand
	//Return: *this
	/******************************************************************/
	Hand operator += (const Card &TheNextCard);

	/******************************************************************/
	//Name: operator ++()
	//Description: increment the card by one
	//Parameters: none
	//return:this*
	/******************************************************************/
	const Hand &Hand::operator ++();

	/******************************************************************/
	//Name: Sortsearch()
	//Description: sorts cards
	//Parameters: none
	//return: none
	/******************************************************************/
	void sort(Card Poker, int size);

	/******************************************************************/
	//Name: operator
	//Description: checks the cards you have and outputs what hand you have
	//Parameters: none
	//return: string
	/******************************************************************/
	string operator ()();

	/******************************************************************/
	//name: NewCards()
	//Description: makes the cards reset to 0 so that a set of cards can go in
	//Parameters: none
	//return: none
	/******************************************************************/
	void NewCards();

	/******************************************************************/
	//name: CompairCards
	//Description: 
	//Parameters: 
	//return: 
	/******************************************************************/
	int CompairCards(const Hand &Hand);

	/******************************************************************/
	//name: CardLosers
	//Description: 
	//Parameters: 
	//return: 
	/******************************************************************/
	void CardLosers(int CardLosers[], const Hand &Hand);

private:

	//declare
	Card Poker[4];  //the cards in your hand

	/******************************************************************/
	//Name: SetCard()
	//Description: sets the rank and the suit
	//Parameters: Idx - input - sets suit and rank
	//            TheCard - input - Has the values of suit & rank
	//return: none
	/******************************************************************/
	void SetCard(int idx, const Card &TheCard);

	/******************************************************************/
	//Name: SetNumCards()
	//Description: Sets the number you cards
	//Parameters: value - input - how many cards
	//return: *this
	/******************************************************************/
	void SetNumCards(int value);

	/******************************************************************/
	//Name: GetNumCards()
	//Description: Gets the number of cards
	//Parameters: none
	//return: NumberOfCards
	/******************************************************************/
	int GetNumCards() const;

	/******************************************************************/
	//Name: Royalflush, straightflush, three of a kind, flush, straight
	//      one pair
	//Description: each one takes the cards and checks whether it is
	//             a Royal flush, straight, three of a kind, flush
	//             straight flush or a pair and return true or false
	//Parameters: None
	//return: bool(true or false
	/******************************************************************/
	bool Royalflush();    //checks for a royalflush
	bool StriaghtFlush(); //checks for a straightflush
	bool Threeofakind();  //checks for three of a kind
	bool Flush();         //checks for a flush
	bool Straight();      //checks for a straight
	bool Onepair(int myNumberOfCards);       //checks for a pair
};

	/******************************************************************/
	//Name: operator >,<,==,+,-
	//description: checks left and right card whether its greater,
	//             less then equal to or it adds and subtracted
	//Parameters: Card left - input - takes card one
	//            Card right - input - takes card two
	//return: bool true or false
	/******************************************************************/
bool operator > (const Card &left, const Card &right);  //greater than 
bool operator < (const Card &left, const Card &right);  //less than
bool operator == (const Card &left, const Card &right); //equal too
int operator + (const Card &left, const Card &right);  //add to
int operator - (const Card &left, const Card &right);   //subtract from

	/******************************************************************/
	//Name: Operator << ()
	//description: overload << so you can output if the three cards have a value or not
	//parameters: MyCard - input - The cards
	//            Hand - input - the hand
	//Return: String of different hand types
	/******************************************************************/
ostream  &operator << (ostream& MyCard, const Hand  &Hand);
#endif



