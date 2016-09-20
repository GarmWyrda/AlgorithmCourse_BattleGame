// BattleGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <time.h>
#include <iostream>
#include "battle.h"


#define MAX_SIZE 100
using namespace std;


int main()
{
	srand(time(NULL)); // initializes random seed
	int nbCards;

	string input;
	bool answered = false;
	while (!answered) {
		std::cout << "how many cards per player ( 1 to 50) ?" << std::endl;
		std::getline(std::cin, input);
		try {
			nbCards = std::stoi(input);
			if (nbCards > 0 && nbCards <= 50) {
				answered = true;
			}
			else {
				std::cout << "Please enter a number between 1 and 50" << std::endl;
			}
		}
		catch (...) {
			std::cout << "Please enter a number between 1 and 50" << std::endl;
		}
	}
	Pile<Card> deck = Pile<Card>(MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; i++) {
		Card newCard = Card();
		deck.empiler(newCard);
	}
	std::cout << "Deck initialized" << std::endl;
	std::cout << deck << std::endl;
	bool endTheGame = false;
	battle battleGame = battle(nbCards, deck);
	battleGame.distributeCards();
	while (!endTheGame) {
		battleGame.startGame();
		std::cout << "Another game ?" << std::endl;
		std::cout << "Type 1 if you want to play again with a new deck (same amount of cards per player)" << std::endl;
		if (!battleGame.getIsGameOver()) {
			std::cout << "Type 2 if you want to play with your \"Gain Decks\", we'll then use the smallest Deck" << std::endl;
		}
		std::cout << "Type anything else if you want to quit" << std::endl;
		std::getline(std::cin, input);
		int answer = 0;
		try {
			answer = std::stoi(input);
		}
		catch (...) {
			endTheGame = true;
		}

		if (answer == 1) {
			std::cout << "1 is chosen, new game !" << std::endl;
			endTheGame = false;
			Pile<Card> newDeck = Pile<Card>(MAX_SIZE);
			for (int i = 0; i < MAX_SIZE; i++) {
				Card newCard = Card();
				newDeck.empiler(newCard);
			}
			std::cout << "Deck initialized" << std::endl;
			std::cout << newDeck << std::endl;
			battleGame = battle(nbCards, newDeck);
			battleGame.distributeCards();
		}
		else if (answer == 2) {
			std::cout << "2 is chosen, the battle keeps going !" << std::endl;
			endTheGame = false;
			battleGame.exchangeSetsOfDecks();
		}
		else {
			endTheGame = true;
		}
	}
		system("pause");
		return 0;

}

