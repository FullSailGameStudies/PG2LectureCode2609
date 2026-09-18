#pragma once
#include "Card.h"
class BlackjackCard : public Card
{
public:
	//it's ok to define simple ctors in the header file
	BlackjackCard(CardFace face, CardSuit suit) :
		Card(face,suit)
	{	}

};

