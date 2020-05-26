#pragma once
#include "Soldier.hpp"

namespace WarGame
{
    class Paramedic : public Soldier
    {
    public:
        Paramedic(uint team) : Soldier(100, 50, team) {}
        Paramedic(uint hp, uint dpa, uint team) : Soldier(hp, dpa, team) {}
        virtual void move(WarGame::Board &, WarGame::Board::MoveDIR);

        void move(WarGame::Board &, WarGame::Board::MoveDIR);
    };
    
} 