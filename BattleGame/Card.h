#pragma once
#include <iostream>
#include <string>
using std::string;

class Card
{
public:
	Card();
	~Card();
	short getValue() const;
	short getBonus() const;
	bool getColor() const;
	int isGreaterThan(Card &otherCard);	//return -1 if otherCard is greater, 1 if this card is greater, and 0 if it's equal
	float cardScore() const;	//return the score of the card
	friend std::ostream& operator<< (std::ostream&, const Card);

private:
	short value, bonus;	//value is the value of the card (1 to 10), bonus is from 1 to 4
	bool color;		//0 (false) is BLACK, 1 (true) is RED
};

