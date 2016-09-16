#include "stdafx.h"
#include "Card.h"
#include <stdlib.h>


Card::Card()
{
	value = rand() % 10 + 1;
	bonus = rand() % 4 + 1;
	color = rand() % 2;
}


Card::~Card()
{
}

int Card::getValue()
{
	return value;
}

int Card::getBonus()
{
	return bonus;
}

bool Card::getColor()
{
	return color;
}

int Card::isGreaterThan(Card & otherCard) const
{
	int returnValue;
	if (value > otherCard.value) {
		returnValue = 1;
	}else if(value < otherCard.value) {
		returnValue =  -1;
	}else if (color > otherCard.color) {
		returnValue = 1;
	}else if (color < otherCard.color) {
		returnValue = -1;
	}else {
		returnValue = 0;
	}
	return returnValue;
}

int Card::cardScore() const
{
	double colorValue;
	if (color == 0) {
		colorValue = 1;
	}
	else {
		colorValue = 1.5;
	}
	int cardScore = value*colorValue*bonus;
	return cardScore;
}
