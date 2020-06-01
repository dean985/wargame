#pragma once
#include "Soldier.hpp"

class FootCommander : public Soldier
{
    static const int maxLife = 150;

public:
    FootCommander(int team) : Soldier(150, 20, role::Foot, true, team) {}

    
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal() override
    {
        _hp = maxLife;
    }
};