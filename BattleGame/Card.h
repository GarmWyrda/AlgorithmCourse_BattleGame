#pragma once

class Card
{
public:
	Card();
	~Card();
	int getValue();
	int getBonus();
	bool getColor();
	int isGreaterThan(Card &otherCard) const;	//return -1 if otherCard is greater, 1 if this card is greater, and 0 if it's equal
	int cardScore() const;	//return the score of the card

private:
	int value, bonus;	//value is the value of the card (1 to 10), bonus is from 1 to 4
	bool color;		//0 (false) is BLACK, 1 (true) is RED
};

