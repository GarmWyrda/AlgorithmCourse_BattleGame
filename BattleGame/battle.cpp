#include "stdafx.h"
#include "battle.h"
#include <algorithm>


battle::battle(int nbCardsPerPlayer, Pile<Card> deck)
{
	this->nbCardsPerPlayer = nbCardsPerPlayer;
	this->deck = deck;
	this->playersDecks[0] = Pile<Card>(this->nbCardsPerPlayer);
	this->playersDecks[1] = Pile<Card>(this->nbCardsPerPlayer);
	this->playersDecksWon[0] = Pile<Card>(this->nbCardsPerPlayer * 2);
	this->playersDecksWon[1] = Pile<Card>(this->nbCardsPerPlayer * 2);
	this->gameResult[0] = -1;
	this->gameResult[1] = -1;
	this->isGameOver = false;
}


battle::~battle()
{
}

bool battle::getIsGameOver()
{
	return this->isGameOver;
}

void battle::exchangeSetsOfDecks()
{
	this->playersDecks[0] = this->playersDecksWon[0];
	this->playersDecks[1] = this->playersDecksWon[1];
	this->playersDecksWon[0] = Pile<Card>(this->nbCardsPerPlayer * 2);
	this->playersDecksWon[1] = Pile<Card>(this->nbCardsPerPlayer * 2);
}

void battle::distributeCards()
{
	for (int i = 0; i < nbCardsPerPlayer; i++) {
		this->playersDecks[0].empiler(this->deck.depiler());
		this->playersDecks[1].empiler(this->deck.depiler());
	}
}

void battle::startGame()
{
	std::cout << "Player 1's Deck" << std::endl;
	std::cout << playersDecks[0] << std::endl;
	std::cout << "Player 2's Deck" << std::endl;
	std::cout << playersDecks[1] << std::endl;
	std::cout << std::endl;
	std::cout << "Let the game begins !" << std::endl;
	system("pause");
	Card card1, card2;
	float scorePlayer1 = 0, scorePlayer2 = 0;
	int nbRounds = std::min(playersDecks[0].taille(), playersDecks[1].taille());
	for (int i = 1; i <= nbRounds; i++) {
		card1 = playersDecks[0].depiler();
		card2 = playersDecks[1].depiler();
		std::cout << "Player 1 : " << card1 << std::endl;
		std::cout << "Player 2 : " << card2 << std::endl;

		int whoWon = card1.isGreaterThan(card2);	//return -1 if card2 is greater, 1 if this card1 is greater, and 0 if it's equal
		if (whoWon == -1) {
			playersDecksWon[1].empiler(card1);
			playersDecksWon[1].empiler(card2);
			scorePlayer2 += card1.cardScore();
			scorePlayer2 += card2.cardScore();
			std::cout << "Player 2 wins" << std::endl;
		}
		if (whoWon == 0) {
			playersDecksWon[0].empiler(card1);
			playersDecksWon[1].empiler(card2);
			scorePlayer1 += card1.cardScore();
			scorePlayer2 += card2.cardScore();
			std::cout << "Draw" << std::endl;
		}
		if (whoWon == 1) {
			playersDecksWon[0].empiler(card1);
			playersDecksWon[0].empiler(card2);
			scorePlayer1 += card1.cardScore();
			scorePlayer1 += card2.cardScore();
			std::cout << "Player 1 wins" << std::endl;
		}
		std::cout << "------------------" << std::endl;
		system("pause");
	}
	std::cout << "Battle Game is over !" << std::endl;
	std::cout << "Score : " << std::endl;
	if (scorePlayer1 > scorePlayer2) {
		std::cout << "Player 1 won ! With a score of : " << scorePlayer1 << " - Player 2 has a score of : " << scorePlayer2 << std::endl;
	}
	else if (scorePlayer1 < scorePlayer2) {
		std::cout << "Player 2 won ! With a score of : " << scorePlayer2 << " - Player 1 has a score of : " << scorePlayer1 << std::endl;
	}
	else {
		std::cout << "It 's a tie ! Both players has a score of : " << scorePlayer1 << std::endl;
	}
	
	if (playersDecksWon[0].taille() == 0 || playersDecksWon[1].taille() == 0) {
		this->isGameOver = true;
	}
}
