#pragma once
#include "Weapon.h"
class Knife :
    public Weapon
{
public:

    Knife(int range, int damage, bool serrated_)
        : Weapon(range, damage), serrated_(serrated_)
    {}
    bool Serrated() const { return serrated_; }
    void Serrated(bool serrated)
    {
        serrated_ = serrated;
    }

    int calcDamage() override;
    void showMe() override;

private:
    bool serrated_;
};

