#include "stdafx.h"
#include "battle.h"


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
}


battle::~battle()
{
}
