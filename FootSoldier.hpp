#pragma once
#include "Soldier.hpp"
namespace WarGame
{

    class FootSoldier : public WarGame::Soldier
    {
    public:
        FootSoldier(uint team) : Soldier(100, 10, team)
        {
        }
        // void move(WarGame::Board &, WarGame::Board::MoveDIR);
    };


    // void FootSoldier::move(WarGame::Board &, WarGame::Board::MoveDIR)
    // {
    //     return;
    // }

} 
