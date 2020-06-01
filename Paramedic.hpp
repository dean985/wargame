#pragma once
#include "Soldier.hpp"

class Paramedic : public Soldier
{
    const int maxLife = 100;

public:
    Paramedic(int team) : Soldier(100, 50, role::Paramedic, false, team) {}
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        for (int i = source.first - 1; i < source.first + 2 && i < board.size(); i++)
        {
            if (i < 0)
            {
                i = 0;
            }

            for (int j = source.second - 1; j < source.second + 2 && j < board[i].size(); j++)
            {
                if (j < 0)
                {
                    j = 0;
                }

                if (j == source.second && i == source.first)
                {
                    continue;
                }
                if (board[i][j] != nullptr && board[i][j]->_team == this->_team)
                {
                    board[i][j]->heal();
                }
            }
        }
    }

    void heal() override
    {
        _hp = maxLife;
    }
};