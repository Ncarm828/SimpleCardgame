#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
#include "Hand.h"
#include "Card.h"
#include "SortSearch.h"
using namespace std;


//description: greats a hand that has nothing in it   
Hand::Hand()
{
	SetNumCards(0);
}

//Description: makes the cards reset to 0 so that a set of cards can go in
void Hand::NewCards()
{
	SetNumCards(0);
}

//Description: sets the rank and the suit 
void Hand::SetCard(int idx, const Card &TheCard)
{
	Poker[idx].rank = TheCard.rank;
	Poker[idx].suit = TheCard.suit;
}

//Description:overload operator that gives you the next card
Hand Hand::operator += (const Card &TheNextCard)
{
	SetCard(GetNumCards(), TheNextCard);
	SetNumCards(GetNumCards() + 1);
	return (*this);
}

//overload operator that gives you the next card
const Hand &Hand::operator ++ ()
{
	SetNumCards(GetNumCards() + 1);
	return (*this);
}

//sorting for the cards
void Hand::sort(Card Poker, int size)
{
	//selSort(&Poker, size);
}

//sets 
//sets the card numbers a value
void Hand::SetNumCards(int value)
{
	NumberOfCards = value;
}

//gets 
//gets the number rank and suit of cards
Card Hand::GetCard(int idx) const
{
	return (Poker[idx]);
}

//gets
//gets the number of cards
int Hand::GetNumCards() const
{
	return(NumberOfCards);
}

//checks if left is greater then right card
bool operator > (const Card &left, const Card &right)
{
	if (left.rank > right.rank)
		return true;
	else
		return false;
}

//checks if left is less than right card
bool operator < (const Card &left, const Card &right)
{
	if (left.rank < right.rank)
		return true;
	else
		return false;
}

//checks if left is equal to right card
bool operator == (const Card &left, const Card &right)
{
	if (left.rank == right.rank)
		return true;
	else
		return false;
}

//checks if left subtracted to right card (suit)
int  operator - (const Card &left, const Card &right)
{
	return (left.suit - right.suit);
}

//left card rank added to right card rank
int operator + (const Card &left, const Card &right)
{
	return (left.rank + right.rank);
}

//overloaded operator for << to output the winnings 
ostream &operator << (ostream& MyCard, const Hand &Hand)
{
	for (int i = 0; i < Hand.NumberOfCards; i++){
		cout << "Player" << i << " cards:  ";
		MyCard << Hand.GetCard(i) << endl;
	}
	return MyCard;
}

//operator that output what kind of winning you have if any  
string Hand::operator ()()
{
	return ("Nothing");
}

//checks if its a royal flush
bool Hand::Royalflush()
{
	if (GetCard(0).rank + GetCard(1).rank + GetCard(2).rank == 23)
		return true;
	else
		return false;
}

//checks if its a flush
bool Hand::Flush()
{
	if (GetCard(0).suit - GetCard(1).suit == 0 && GetCard(0).suit - GetCard(2).suit == 0)
		return true;
	else
		return false;
}

//checks if its a straight
bool Hand::Straight()
{

	if (GetCard(2).rank - GetCard(1).rank == 1 && GetCard(2).rank - GetCard(0).rank == 2)
		return true;
	else if (GetCard(2).rank - GetCard(1).rank == 1 && GetCard(2).rank - GetCard(0).rank == 12)
		return true;
	else
		return false;
}

//checks if its a three of a kind
bool Hand::Threeofakind()
{
	if (GetCard(0).rank == GetCard(1).rank && GetCard(0).rank == GetCard(2).rank)
		return true;
	else
		return false;
}

//checks if you have a pair
bool Hand::Onepair(int MyNumberOfCards)
{
	if (MyNumberOfCards == 2) {
		if (GetCard(0).rank == GetCard(1).rank)
			return true;
	}
	if (MyNumberOfCards == 3) {
		if (GetCard(0).rank == GetCard(1).rank)
			return true;
		else if (GetCard(0).rank == GetCard(2).rank)
			return true;
		else if (GetCard(1).rank == GetCard(2).rank)
			return true;
	}
	if (MyNumberOfCards == 4) {
		if (GetCard(0).rank == GetCard(1).rank)
			return true;
		else if (GetCard(0).rank == GetCard(2).rank)
			return true;
		else if (GetCard(0).rank == GetCard(3).rank)
			return true;
		else if (GetCard(1).rank == GetCard(2).rank)
			return true;
		else if (GetCard(1).rank == GetCard(3).rank)
			return true;
		else if (GetCard(2).rank == GetCard(3).rank)
			return true;
	}
	return false;
}

//Compares the different cards that have been drawn
int Hand::CompairCards(const Hand &Hand) { 
	
	int postion = 0;

	for (int i = 0; i < Hand.NumberOfCards; i++)
	{
		if ((GetCard(postion).rank >= 10 || GetCard(postion).rank == 0) && i < Hand.NumberOfCards) {
			if (!(postion == (Hand.NumberOfCards - 1))) {
				postion += 1;
			}
			//Do nothing
		}
		else {
			if ((GetCard(postion).rank < GetCard(i).rank) && ((GetCard(i).rank < 10) && GetCard(postion).rank != 0)) {
				postion = i;
			}
			else if (GetCard(postion).rank == GetCard(i).rank) {
				if (GetCard(postion).suit > GetCard(i).suit) {
					postion = i;
				}
			}
		}
	}

	if (postion == (Hand.NumberOfCards - 1) && (GetCard(postion).rank >= 10 || GetCard(postion).rank == 0)) {
		postion = -1; //This will show that all cards in the hand are Penalty cards 
	}
		
	return postion;
}

void Hand::CardLosers(int CardLosers[], const Hand &Hand) {
	
	for (int i = 0; i < Hand.NumberOfCards; i++)
	{
		if (GetCard(i).rank >= 10 || GetCard(i).rank == 0) {
			CardLosers[i] = 1;
		}
		else {
			CardLosers[i] = 0;
		}
	}
}
