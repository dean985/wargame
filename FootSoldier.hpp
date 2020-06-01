#pragma once
#include "Soldier.hpp"

class FootSoldier : public Soldier
{
    static const int maxLife = 100;

public:
    FootSoldier(int team) : Soldier( 100, 10, role::Foot, false, team) {}

    // virtual void hit(Board &board, std::pair<int, int> source) override
    // {
    //     return;
    // }


    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        return;
    }

    void heal() override
    {
        _hp = maxLife;
    }
};