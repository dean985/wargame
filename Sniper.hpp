#pragma once
#include "Soldier.hpp"
#include <iostream>

class Sniper : public Soldier
{
    const int maxLife = 100;

public:
    Sniper(int team) : Soldier(100, 50, role::Sniper, false, team) {}

    ~Sniper()
    {
        std::cout << "can't reach the destination" << std::endl;
    }

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

            if (Victim->_hp <= 0)
            {
                // call distructor
                // *Victim;
                board[max_location_life.first].at(max_location_life.second) = nullptr;
                delete Victim;
                //*Victim = nullptr;
            }
        }

        return;
    }

    virtual void hitAll(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
    }

    void heal() override
    {
        _hp = maxLife;
    }
};