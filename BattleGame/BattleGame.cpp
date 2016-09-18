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
	for (int i = 0; i < nbCards; i++) {
		Card newCard = Card();
		deck.empiler(newCard);
	}
	
	std::cout << deck << std::endl;
	//LA SUITE POUR DEMAIN ? OU CE SOIR ? TROP DE SUSPENS
	system("pause");
	return 0;

}

