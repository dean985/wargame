#pragma once
#include "Soldier.hpp"

class ParamedicCommander : public Soldier
{
    const int maxLife = 200;

public:
    ParamedicCommander(int team) : Soldier(maxLife, 100, role::Paramedic, true, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal()
    {
        _hp = maxLife;
    }
};