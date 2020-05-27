#pragma once
#include "Soldier.hpp"

class SniperCommander : public Soldier
{
    const int maxLife = 120;

public:
    SniperCommander(int team) : Soldier(maxLife, 100, role::Sniper, true, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal()
    {
        _hp = maxLife;
    }
};