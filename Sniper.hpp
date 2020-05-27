#pragma once
#include "Soldier.hpp"

class Sniper : public Soldier
{
    const int maxLife = 100;

public:
    Sniper(int team) : Soldier(100, 50, role::Paramedic, false, team) {}
    virtual void hit(Board &board, std::pair<int, int> source)
    {
        return;
    }

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal()
    {
        _hp = maxLife;
    }
};