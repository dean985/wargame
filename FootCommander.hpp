#pragma once
#include "Soldier.hpp"
#include "Commander.hpp"
#include <iostream>
#include <typeinfo>
namespace WarGame
{

    class FootCommander : public WarGame::FootSoldier
    {
    public:
        std::vector<FootSoldier *> soldiers;
        FootCommander(uint team) : FootSoldier(150, 50, team) {}

        void addSoldier(FootSoldier *const s);
        void addSoldiers(std::vector<FootSoldier *> ss);

        void attack(WarGame::Board & board, WarGame::Board::MoveDIR){
            std::cout << "Foot Commander" << std::endl;
            return;
        } 
    };


    void FootCommander::addSoldier(FootSoldier *const s)
    {
        soldiers.push_back(s);
        return;
    }

    void FootCommander::addSoldiers(std::vector<FootSoldier *> ss)
    {
        for (FootSoldier *sold : ss)
        {
            if (typeid(sold).name() == "FootSoldier")
            {
                this->addSoldier(sold);
            }
        }
    }
} 