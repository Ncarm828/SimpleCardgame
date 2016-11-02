#include "stdafx.h"
#include "Players.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <algorithm>
#include <cstdlib>

//Globals 
#define LOOPSTART 0
#define SCORE_REDUCTION_NOTHING 0
#define SCORE_REDUCTION_AMOUNT 1
#define SCORE_INCREASE_AMOUNT 2
#define SCORE_INCREASE_NOTHING 0



using namespace std;

int validInput();
int WelcomeFunction();
void ClearScreen();
string GetNames(int playernumber);
void dealHand(Deck &TheDeck, Hand &TheHand, int AmountOfPlayers);  //prototype dealhand
void PrintScoreBoard( Players &player, Hand &CHand, int size); //Print the final score
bool ScoreChecker(Players &player, int size); //Checks the Score for game over

int main()
{
	
	int AmountOfPlayers = 0;	//Amount of players currently playing the game 
	vector<string> PlayerNames;	//Names of all the players
	Deck MainDeck;	//Declare deck
	Card CurrentCard;	//Declare card					
	Hand TheHand;	//Declare Hand


	ClearScreen();

	AmountOfPlayers = WelcomeFunction();
	
	for (int i = LOOPSTART; i < AmountOfPlayers; i++) {
		PlayerNames.push_back(GetNames(i));
	}

	ClearScreen();

	cout << "Great to meet you ";
	for (auto i = PlayerNames.begin(); i != PlayerNames.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
	cout << R"(Lets Get Started! 
		
		
		
		
		)"<< endl;

	//Creates the object for the players
	Players Players(AmountOfPlayers, PlayerNames);


	while (true) {

		TheHand.NewCards(); //sets your hand to empty
		dealHand(MainDeck, TheHand, AmountOfPlayers); //get cards off deck based on the amount of players
		cout << TheHand << endl;

		int CardWinner; //return of the card winner
		int* CardLosers = new int[AmountOfPlayers];
		CardWinner = TheHand.CompairCards(TheHand);
		TheHand.CardLosers(CardLosers, TheHand);

		if (CardWinner != -1) { //this shows that there are no winners in this hand
			Players.UpdateUserScore(CardWinner, SCORE_INCREASE_AMOUNT, SCORE_REDUCTION_NOTHING); //Gives winners the points 
		}
		for (int i = 0; i < AmountOfPlayers; i++) {
			if (CardLosers[i] == 1 && Players.GetScore(i) > 0) {
				Players.UpdateUserScore(i, SCORE_INCREASE_NOTHING, SCORE_REDUCTION_AMOUNT); //reduces everyone who got a bad card
			}
		}

		PrintScoreBoard(Players, TheHand, AmountOfPlayers); //Print the ScoreBoard

		cout << "Ready for the next round?" << endl;
		cout << " Y for yes and N for No" << endl;
		char RoundAnswer;
		cin >> RoundAnswer;
		if (tolower(RoundAnswer) == 'n') {
			break;
		}
		ClearScreen(); //Clears the screen so the user interface looks cleaned up 

		MainDeck.reshuffle(); //shuffles the deck after each round 

		if(ScoreChecker(Players, AmountOfPlayers)){
			
			int biggest = 0;
			for (int i = 0; i < AmountOfPlayers; i++) {
				if (Players.GetScore(biggest) < Players.GetScore(i)) {
					biggest = i;
				}
			}

			PrintScoreBoard(Players, TheHand, AmountOfPlayers); //Print the ScoreBoard
			cout << "The Winner Is:  " << Players.GetName(biggest) << endl;
			cout << endl;

			cout << "Want to Play again ?" << endl;
			cout << " Y for yes and N for No" << endl;
			char answer;
			cin >> answer;
			if (tolower(answer) == 'n') {
				break;
			}
		}
	}

	


    return 0;
}

/***********************************************/
//Function: validInput
//Iput : None
//Output : number of players 
//Description : this function is used to check the \
				user for their input of how many players. if the user \
				selects a value out of range or invalid this will catch the error
/***********************************************/

int validInput()
{
	int input;
	cin >> input;
	while (cin.fail() || input < 2 || input > 4)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "The input must be from 2 through 4.  Enter a NUMBER: ";
		cin >> input;
	}
	return input;
}

/***********************************************/
//Function: WelcomeFucntion
//Iput : None
//Output : number of players 
//Description : Simple welcome messages. calls\
				validInput for number of players 
/***********************************************/
int WelcomeFunction() {
	int players = 0;
	
	cout << "Welcome to the Card Game Counts" << endl;
	cout << "_______________________________" << endl;
	cout << endl;
	cout << "Counts is a simple text base game that consists if two to four players \n Once the order has been selected the order will stary the\nsame.  The game will consist of rounds, where each player draws a single card\nfrom a shuffled deck. The players’ cards will be compared to determine the winner of\nthe round (whose score will be increased) and or any penalized players\n (whose score will be decreased). A scoreboard should be displayed at the end of each round (to\ntrack player progress). Rounds will continue until an overall game winner is determined.\n" << endl;

	cout << "First, How many players would you like to play with?" << endl;
	players = validInput();

	return players;
}


/***********************************************/
//Function: ClearScreen
//Iput : N/A
//Output : N/A 
//Description : This function will clean the consol so that the user will see only the current game and or game round. This is for a more friendly UI
/***********************************************/
void ClearScreen() {
	//Used to clear the console so the user can focus just on the UI of the game 

#ifdef _WIN32
	system("cls");
#ifdef _WIN64
	system("cls");
#endif
#elif __APPLE__
	#if TARGET_OS_MAC
	system("clear");
	#else
	#   error "Unknown Apple platform"
	#endif
#elif __linux__
	system("clear");
#elif __unix__ // all unices not caught above
	system("clear");
#else
#   error "Unknown compiler"
#endif

}


/***********************************************/
//Function: GetNames
//Iput : N/A
//Output : returns a string of the name from the user 
//Description : get the users name and checks for unknown entry
/***********************************************/
string GetNames(int playernumber) {
	string input;
	cout << "Player #" << playernumber + 1 << ", Please enter yout Name" << endl;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "There was an error entering your name. Please Enter A Valid Name.";
		cin >> input;
	}
	return input;
}

/*********************************************************************/
/*                                                                   */
/*   Function name:  Void dealHand                                   */
/*                                                                   */
/*   Description:    inputs deck and you get three cards             */
/*                                                                   */
/*   Parameters: TheDeck - input - deck of cards                     */
/*               TheCard - input - Hand of cards                     */
/*                                     							     */
/*   Return Value:   none                                            */
/*********************************************************************/
void dealHand(Deck &TheDeck, Hand &TheHand, int AmountOfPlayers)
{
	for (int idx = LOOPSTART; idx < AmountOfPlayers; idx++)
	{
		TheHand += TheDeck.dealCard();
	}
}


/*********************************************************************/
/*                                                                   */
/*   Function name:  Void PrintScoreBoard                                   */
/*                                                                   */
/*   Description:    Prints ScoreBoard						         */
/*                                                                   */
/*   Parameters:     None										     */
/*												                     */                                							     
/*   Return Value:   none                                            */
/*********************************************************************/
void PrintScoreBoard(Players &player, Hand &CHand, int size) {
	cout << "/*********************************************************************/" << endl;
	cout <<  endl;
	cout << " NAME:  " << player.GetName(0) << "  SCORE:  " << player.GetScore(0) <<  endl;
	cout << " NAME:  " << player.GetName(1) << "  SCORE:  " << player.GetScore(1) <<  endl;
	if (size > 2) {
		cout <<" NAME:  " << player.GetName(2) << "  SCORE:  " << player.GetScore(2) << endl;
	}
	if (size > 3) {
		cout << " NAME:  " << player.GetName(3) << "  SCORE:  " << player.GetScore(3) << endl;
	}
	cout <<  endl;
	cout << "/*********************************************************************/" << endl;
		
}


/*********************************************************************/
/*                                                                   */
/*   Function name:  Void ScoreChecker                                */
/*                                                                   */
/*   Description:    checks score    						         */
/*                                                                   */
/*   Parameters:     None										     */
/*												                     */
/*   Return Value:   none                                            */
/*********************************************************************/
bool ScoreChecker(Players &player, int size) {

	bool Go = false; //checks that one of the vakues is actually 21 or greater
	int* arr = new int[size]; //Holds the scores of all players 
	int diff = 0; //for telling the difference of two different numbers 


	for (int i = 0; i < size; i++) {
		if (player.GetScore(i) >= 21) {
			Go = true; //only true if one of the values in the scores is 21 or greater 
		}
	}

	if (Go) {

		for (int i = LOOPSTART; i < size; i++) {
			arr[i] = player.GetScore(i); //place each score into the array
		}

		sort(arr, arr + size); //sort the array so that largest number is the last digit in the array 

		if (arr[size-1] == arr[size-2]) { //check to see of the last two numbers are equal
			return false; //if they are equal the game goes on
		}else {
			/*Since the last two numbers are the greatet of the numbers, we only care about these two. 
			if the last number and the second to last number are equal then we can leave the function because
			we then can say that all other values in the array must be equal to or less than the last value.
			if the values are not equal than we must check the difference between the last two numbers. If the distance between the last
			and second to last number are greater than one, we can also say that all values are less than the last value in the array
			and have a greater distance then one.  */
			diff = abs(arr[size-1] - arr[size-2]);
			if (diff > 1)
				return true; //the values are greater the 1 and so the game is over
			else
				return false; //the values are not less than 1 so keep going 
		}	
	}
	return false;
}