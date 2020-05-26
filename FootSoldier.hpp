#pragma once
#include "Soldier.hpp"
namespace WarGame
{

    class FootSoldier : public WarGame::Soldier
    {
    public:
        FootSoldier(uint team) : Soldier(100, 10, team){}
        FootSoldier(uint hp, uint dpa, uint team) : Soldier(hp, dpa, team) {}
        void attack(WarGame::Board & board, WarGame::Board::MoveDIR){
            std::cout << "Foot Soldier" << std::endl;
            return;
        }
    };
} 
