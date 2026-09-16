#pragma once
#include "enums.h"
#include <string>

class Card
{
public:

	Card(CardFace face, CardSuit suit) :
		face_(face), suit_(suit)
	{}

	int Value() const;
	void Print() const;
	std::string FaceName() const;
	std::string SuitName() const;

	CardFace Face() const { return face_; }
	void Face(CardFace face)
	{
		if (face >= CardFace::Ace and face <= CardFace::King)
		{
			face_ = face;
		}
	}

	CardSuit Suit() const { return suit_; }
	void Suit(CardSuit suit)
	{
		if (suit >= CardSuit::Hearts && suit <= CardSuit::Spades)
			suit_ = suit;
	}


private:
	CardFace face_;
	CardSuit suit_;
};

