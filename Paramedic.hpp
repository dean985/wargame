#pragma once
#include "Soldier.hpp"

class Paramedic : public Soldier
{
    const int maxLife = 100;

public:
    Paramedic(int team) : Soldier(maxLife, 50, role::Paramedic, false, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal()
    {
        _hp = maxLife;
    }
};