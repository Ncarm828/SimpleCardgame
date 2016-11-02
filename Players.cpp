#include "stdafx.h"
#include "Players.h"
#include <string>
#include <vector>
#include <iostream>





/***********************************************/
//Function: Players
//Iput : AmountOfPlayers - amount of players currently playing, names - array of different names of each player
//Output : N/A
//Description : Copy Constructor 
/***********************************************/
Players::Players(int NumberOfPlayers, std::vector<std::string>& PlayerNames) {
	
	for (auto i = PlayerNames.begin(); i != PlayerNames.end(); ++i) {
		Player CurrentPlayer;

		CurrentPlayer.name = *i;
		CurrentPlayer.score = 0;
		CurrentPlayer.CardSuit = std::string();
		CurrentPlayer.CardValue = std::string();

		PlayerList.push_back(CurrentPlayer); 
	}
}

/***********************************************/
//Function: ~Players
//Iput : N/A
//Output : N/A
//Description : Destructor
/***********************************************/
Players::~Players() {
	PlayerList.clear();
}

/***********************************************/
//Function: GetName
//Iput : player - which player is needed to be accessed
//Output : player - players name 
//Description : Get the name of a user 
/***********************************************/
std::string Players::GetName(int player) {
	return PlayerList[player].name;
}

/***********************************************/
//Function: GetScore
//Iput : player - which player is needed to be accessed
//Output : score - score of the player 
//Description : get a certain users score 
/***********************************************/
int Players::GetScore(int player) {
	return PlayerList[player].score;
}

/***********************************************/
//Function: GetCard
//Iput : player - which player is needed to be accessed
//Output : string of both suit and value 
//Description : returns a card of a certain player. The first item is the suit. the second is the card value 
/***********************************************/
std::vector<std::string> Players::GetCard(int player) {
	std::vector<std::string> CardInfo;
	CardInfo[0] = PlayerList[player].CardSuit;
	CardInfo[1] = PlayerList[player].CardValue;
	return CardInfo;
}


/***********************************************/
//Function: UpdateUserCard
//Iput :  player - which player is needed to be accessed, suit - card suit, cardnumber - current card number 
//Output : N/A
//Description : Set the card after each round for each player 
/***********************************************/
void Players::UpdateUserCard(int player, std::string suit, int cardnumber) {
	SetCard(player, suit, cardnumber);
}


/***********************************************/
//Function: UpdateUserScore
//Iput : player - which player is needed to be accessed, Score - current score of user, reduction - set to zero unless a reduction to score is needed
//Output : N/A
//Description : Sets the score of the player after each round 
/***********************************************/
void Players::UpdateUserScore(int player, int score, int reduction) {
	SetScore(player,score, reduction);
}



/***********************************************/
//Function: SetScore
//Iput : player - which player is needed to be accessed, Score - current score of user, reduction - set to zero unless a reduction to score is needed
//Output : N/A
//Description : Sets the score of the player after each round 
/***********************************************/
void Players::SetScore(int player, int score, int reduction) {
	
	if (reduction > 0 && score == 0) {
		PlayerList[player].score -= reduction;
	}
	else if(score > 0 && reduction == 0){
		PlayerList[player].score += score;
	}
	else {
		std::cout << "invalid score entry" << std::endl;
	}
}

/***********************************************/
//Function: SetCard
//Iput :  player - which player is needed to be accessed, suit - card suit, cardnumber - current card number 
//Output :N/A
//Description : Set the card after each round for each player 
/***********************************************/
void Players::SetCard(int player, std::string suit, int cardnumber) {
	if (!suit.empty() && cardnumber != 0) {
		PlayerList[player].CardSuit = suit;
		PlayerList[player].CardValue = std::to_string(cardnumber);
	}
	else {
		std::cout << "invalid card entry" << std::endl;
	}
}

/***********************************************/
//Function: PrintPlayer
//Iput :  player - which player is needed to be accessed, 
//Output : N/A
//Description : Print out all player information 
/***********************************************/
void Players::PrintPlayer(int player) {
	
	std::cout << PlayerList[player].name << std::endl; 
	std::cout << PlayerList[player].score << std::endl;
	std::cout << PlayerList[player].CardSuit << std::endl;
	std::cout << PlayerList[player].CardValue << std::endl;

}