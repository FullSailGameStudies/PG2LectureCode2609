#include "Card.h"
#include <iostream>

int Card::Value() const
{
    return (int)face_;
}

void Card::Print() const
{
    std::cout << FaceName() << " of " << SuitName() << "\n";
}

std::string Card::FaceName() const
{
    std::string name = "";
    switch (face_)
    {
    case Ace:
        name = "A";
        break;
    case Two:
    case Three:
    case Four:
    case Five:
    case Six:
    case Seven:
    case Eight:
    case Nine:
    case Ten:
        name = std::to_string(face_);
        break;
    case Jack:
        name = "J";
        break;
    case Queen:
        name = "Q";
        break;
    case King:
        name = "K";
        break;
    default:
        break;
    }
    return name;
}

std::string Card::SuitName() const
{
    std::string name = "";
    switch (suit_)
    {
    case Hearts:
        name = "Hearts";
        break;
    case Diamonds:
        name = "Diamonds";
        break;
    case Clubs:
        name = "Clubs";
        break;
    case Spades:
        name = "Spades";
        break;
    default:
        break;
    }
    return name;
}
