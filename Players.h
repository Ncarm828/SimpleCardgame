#pragma once
#include <string>
#include <vector>



class Players
{


private:

	/***********************************************/
	//Function: SetScore
	//Iput : player - which player is needed to be accessed, Score - current score of user, reduction - set to zero unless a reduction to score is needed
	//Output : N/A
	//Description : Sets the score of the player after each round 
	/***********************************************/
	void SetScore(int player, int score, int reduction);

	/***********************************************/
	//Function: SetCard
	//Iput :  player - which player is needed to be accessed, suit - card suit, cardnumber - current card number 
	//Output :N/A
	//Description : Set the card after each round for each player 
	/***********************************************/
	void SetCard(int player, std::string suit, int cardnumber);


	//A struct of each player and information
	struct Player
	{
		std::string name;
		int score;
		std::string CardSuit; //currently not used 
		std::string CardValue; //currently not used 
	};

	//List of each of the players 
	std::vector<Player> PlayerList;


public:

	/***********************************************/
	//Function: Players
	//Iput : AmountOfPlayers - amount of players currently playing, names - array of different names of each player
	//Output : N/A
	//Description : Copy Constructor 
	/***********************************************/
	Players::Players(int AmountOfPlayers, std::vector<std::string>& PlayerNames);

	/***********************************************/
	//Function: ~Players
	//Iput : N/A
	//Output : N/A
	//Description : Destructor
	/***********************************************/
	~Players();

	/***********************************************/
	//Function: GetName
	//Iput : player - which player is needed to be accessed
	//Output : player - players name 
	//Description : Get the name of a user 
	/***********************************************/
	std::string GetName(int player);

	/***********************************************/
	//Function: GetScore
	//Iput : player - which player is needed to be accessed
	//Output : score - score of the player 
	//Description : get a certain users score 
	/***********************************************/
	int GetScore(int player);

	/***********************************************/
	//Function: GetCard
	//Iput : player - which player is needed to be accessed
	//Output : string of both suit and value 
	//Description : returns a card of a certain player 
	/***********************************************/
	std::vector<std::string> GetCard(int player);


	/***********************************************/
	//Function: UpdateUserCard
	//Iput :  player - which player is needed to be accessed, suit - card suit, cardnumber - current card number 
	//Output : N/A
	//Description : Set the card after each round for each player 
	/***********************************************/
	void UpdateUserCard(int player, std::string suit, int cardnumber);


	/***********************************************/
	//Function: UpdateUserScore
	//Iput : player - which player is needed to be accessed, Score - current score of user, reduction - set to zero unless a reduction to score is needed
	//Output : N/A
	//Description : Sets the score of the player after each round 
	/***********************************************/
	void UpdateUserScore(int player, int score, int reduction);

	/***********************************************/
	//Function: PrintPlayer
	//Iput :  player - which player is needed to be accessed, 
	//Output : N/A
	//Description : Print out all player information 
	/***********************************************/
	void PrintPlayer(int player);


};

