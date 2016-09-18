#include "stdafx.h"
#include "Card.h"
#include <stdlib.h>


Card::Card()
{
	value = (short)rand() % 10 + 1;
	bonus = (short)rand() % 4 + 1;
	int forColor = rand() % 2;
	color = (bool)forColor;
}


Card::~Card()
{
}

short Card::getValue() const
{
	return value;
}

short Card::getBonus() const
{
	return bonus;
}

bool Card::getColor() const
{
	return color;
}

int Card::isGreaterThan(Card & otherCard)
{
	int result;
	if (value > otherCard.value) {
		result = 1;
	}else if(value < otherCard.value) {
		result =  -1;
	}else if (color > otherCard.color) {
		result = 1;
	}else if (color < otherCard.color) {
		result = -1;
	}else {
		result = 0;
	}
	return result;
}

float Card::cardScore() const
{
	float colorValue=1;
	if (color == 1) {
		colorValue = 1.5;
	}
	float cardScore = value*colorValue*bonus;
	return cardScore;
}

std::ostream & operator<<(std::ostream & stream, const Card card)
{
	string color;
	if (card.getColor()) {
		color = "red";
	}
	else {
		color = "black";
	}
	stream << "Value : " << card.getValue() << " Bonus : " << card.getBonus() << " Color : " << color << " Playing Value : " << card.cardScore() << std::endl;
	return stream;
}
