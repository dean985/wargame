#pragma once
#include "Soldier.hpp"

class FootCommander : public Soldier
{
    static const int maxLife = 150;

public:
    FootCommander(int team) : Soldier(maxLife, 20, role::Foot, true, team) {}

    virtual void hit(Board &board, std::pair<int, int> source) override
        {
            return;
        }
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal() override
    {
        _hp = maxLife;
    }
};