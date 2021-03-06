#pragma once
#include "Soldier.hpp"
#include <cstdlib>

class FootSoldier : public Soldier
{
    const int maxLife = 100;

public:
    FootSoldier(int team) : Soldier(100, 10, role::Foot, false, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        int dist1 = board.size() + board[0].size();
        int Distance;
        Soldier **nearSoldier = nullptr;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Distance = abs(j - source.second) + abs(i - source.first);

                if (board[i][j] != nullptr && board[i][j]->_team != this->_team && Distance < dist1)
                {
                    dist1 = Distance;
                    nearSoldier = &board[i][j];
                }
            }
        }
        if (nearSoldier)
        {
            (*nearSoldier)->_hp -= this->_dpa;
            if ((*nearSoldier)->_hp <= 0)
            {
                (*nearSoldier) = nullptr;
            }
        }
        else
        {
            //Soldier couldn't find someone to shoot at.
            //No one got shot.
            throw "FootSoldier couldn't find someone to shoot at";
        }
    }
    virtual void hitAll(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override{

    }
    void heal() override
    {
        _hp = maxLife;
    }
};