#pragma once
#include "Soldier.hpp"

class SniperCommander : public Soldier
{
    const int maxLife = 120;

public:
    SniperCommander(int team) : Soldier(120, 100, role::Sniper, true, team) {}
    virtual void hit(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        int max_life = 0;
        std::pair<int, int> max_location_life;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i].at(j);
                if (current != nullptr)
                {
                    if (current->_team != board[source.first].at(source.second)->_team && max_life < current->_hp)
                    {
                        max_location_life.first = i;
                        max_location_life.second = j;
                        max_life = current->_hp;
                    }
                }
            }
        }
        Soldier *Atteker = board[source.first].at(source.second);
        Soldier *Victim = board[max_location_life.first].at(max_location_life.second);
        if (Victim)
        {
            Victim->_hp = Victim->_hp - Atteker->_dpa;

            if (Victim->_hp < 0)
            {
                board[max_location_life.first].at(max_location_life.second) = nullptr;
                delete Victim;
            }
        }

        return;
    }
    virtual void hitAll(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                Soldier *current = board[i][j];
                if (!current)
                    continue;
                if (current->_specialty == role::Sniper && current->_team == this->_team)
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