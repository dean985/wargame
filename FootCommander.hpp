#pragma once
#include "Soldier.hpp"

class FootCommander : public Soldier
{
    static const int maxLife = 150;

public:
    FootCommander(int team) : Soldier(150, 20, role::Foot, true, team) {}

    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i][j];
                if (!current)
                    continue;
                if (current->_specialty == role::Foot && current->_team == this->_team)
                {
                    current->hit(board, source);
                }
            }
        }
    }

    void heal() override
    {
        _hp = maxLife;
    }
};