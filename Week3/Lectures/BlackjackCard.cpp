#include "BlackjackCard.h"

int BlackjackCard::Value() const
{
    //how do I fix this error?
    // 1) call the getters
    //OR...
    // 2) make the fields 'protected' in the Card class
    if (face_ >= CardFace::Jack && face_ <= CardFace::King)
        return 10;
    return Card::Value();
}
