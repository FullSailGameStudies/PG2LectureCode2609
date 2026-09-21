#include "Knife.h"
#include <iostream>

int Knife::calcDamage()
{
    return Weapon::calcDamage();
}

void Knife::showMe()
{
    std::cout << "Knife: serrated - " << ((serrated_) ? "true" : "false") << " ";
    Weapon::showMe();

}
