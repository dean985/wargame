#pragma once
#include "Soldier.hpp"

class ParamedicCommander : public Soldier
{
    const int maxLife = 200;

public:
    ParamedicCommander(int team) : Soldier(200, 100, role::Paramedic, true, team) {}
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i][j];
                if (!current)
                    continue;
                if (current->_specialty == role::Paramedic && current->_team == this->_team)
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